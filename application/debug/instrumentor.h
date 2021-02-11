/**
 * @file instrumentor.h
 * @brief Simple Instrumentor for Profiling
 *
 * This profiler will generate a json file that can be visualized with the chromium tracer
 */

#pragma once

#include <mutex>
#include <chrono>
#include <string>
#include <thread>
#include <fstream>
#include <algorithm>

namespace Horus
{
    namespace Debug
    {

        struct ProfileResult
        {
            const std::string name;
            long long start, end;
            uint32_t thread_id;
        };

        class Instrumentor
        {
            std::string m_session_name = "None";
            std::ofstream m_output_stream;
            int m_profile_count = 0;
            std::mutex m_lock;
            bool m_active_session = false;

            Instrumentor() {}

        public:
            static Instrumentor &Instance()
            {
                static Instrumentor instance;
                return instance;
            }

            ~Instrumentor()
            {
                end_session();
            }

            void begin_session(const std::string &name, const std::string &file_path = "results.json")
            {
                if (m_active_session)
                {
                    end_session();
                }
                m_active_session = true;
                m_output_stream.open(file_path);
                write_header();
                m_session_name = name;
            }

            void end_session()
            {
                if (!m_active_session)
                {
                    return;
                }
                m_active_session = false;
                write_footer();
                m_output_stream.close();
                m_profile_count = 0;
            }

            void write_profile(const ProfileResult &result)
            {
                std::lock_guard<std::mutex> lock(m_lock);

                if (m_profile_count++ > 0)
                {
                    m_output_stream << ",";
                }

                std::string name = result.name;
                std::replace(name.begin(), name.end(), '"', '\'');

                m_output_stream << "{";
                m_output_stream << "\"cat\":\"function\",";
                m_output_stream << "\"dur\":" << (result.end - result.start) << ',';
                m_output_stream << "\"name\":\"" << name << "\",";
                m_output_stream << "\"ph\":\"X\",";
                m_output_stream << "\"pid\":0,";
                m_output_stream << "\"tid\":" << result.thread_id << ",";
                m_output_stream << "\"ts\":" << result.start;
                m_output_stream << "}";
            }

            void write_header()
            {
                m_output_stream << "{\"otherData\": {},\"traceEvents\":[";
            }

            void write_footer()
            {
                m_output_stream << "]}";
            }
        };

        class InstrumentationTimer
        {
            ProfileResult m_result;

            std::chrono::time_point<std::chrono::high_resolution_clock> m_start_time_point;
            bool m_stopped;

        public:
            InstrumentationTimer(const std::string &name)
                : m_result({name, 0, 0, 0}), m_stopped(false)
            {
                m_start_time_point = std::chrono::high_resolution_clock::now();
            }

            ~InstrumentationTimer()
            {
                if (!m_stopped)
                {
                    stop();
                }
            }

            void stop()
            {
                auto end_time_point = std::chrono::high_resolution_clock::now();

                m_result.start = std::chrono::time_point_cast<std::chrono::microseconds>(m_start_time_point).time_since_epoch().count();
                m_result.end = std::chrono::time_point_cast<std::chrono::microseconds>(end_time_point).time_since_epoch().count();
                m_result.thread_id = std::hash<std::thread::id>{}(std::this_thread::get_id());
                Instrumentor::Instance().write_profile(m_result);

                m_stopped = true;
            }
        };

    } // namespace Debug

} // namespace Horus

#ifdef ENABLE_PROFILING
/* Resolve Function Segnature Macro */
#if defined(__GNUC__) || (defined(__MWERKS__) && (__MWERKS__ >= 0x3000)) || (defined(__ICC) && (__ICC >= 600)) || defined(__ghs__)
#define H_FUNC_SIG __PRETTY_FUNCTION__
#elif defined(__DMC__) && (__DMC__ >= 0x810)
#define H_FUNC_SIG __PRETTY_FUNCTION__
#elif (defined(__FUNCSIG__) || (_MSC_VER))
#define H_FUNC_SIG __FUNCSIG__
#elif (defined(__INTEL_COMPILER) && (__INTEL_COMPILER >= 600)) || (defined(__IBMCPP__) && (__IBMCPP__ >= 500))
#define H_FUNC_SIG __FUNCTION__
#elif defined(__BORLANDC__) && (__BORLANDC__ >= 0x550)
#define H_FUNC_SIG __FUNC__
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901)
#define H_FUNC_SIG __func__
#elif defined(__cplusplus) && (__cplusplus >= 201103)
#define H_FUNC_SIG __func__
#else
#define H_FUNC_SIG "H_FUNC_SIG unknown!"
#endif

/* Profile Macros */
#define H_PROFILE_BEGIN_SESSION(name, file_path) ::Horus::Debug::Instrumentor::Instance().begin_session(name, file_path)
#define H_PROFILE_END_SESSION() ::Horus::Debug::Instrumentor::Instance().end_session()
#define H_PROFILE_SCOPE_LINE(name, line) ::Horus::Debug::InstrumentationTimer timer_line_##line(name)
#define H_PROFILE_SCOPE(name) H_PROFILE_SCOPE_LINE(name, __LINE__)
#define H_PROFILE_FUNCTION() H_PROFILE_SCOPE(H_FUNC_SIG)
#else
#define H_PROFILE_BEGIN_SESSION(name, file_path)
#define H_PROFILE_END_SESSION()
#define H_PROFILE_SCOPE_LINE(name, line)
#define H_PROFILE_SCOPE(name)
#define H_PROFILE_FUNCTION()
#endif
