#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace horus
{
    class Log
    {
    private:
        static std::shared_ptr<spdlog::logger> s_horusLogger;

    public:
        static void init();

        inline static std::shared_ptr<spdlog::logger> &getLogger() { return s_horusLogger; }
    };
}

#ifdef H_DEBUG
#define H_TRACE(...) ::horus::Log::getLogger()->trace(__VA_ARGS__)
#define H_INFO(...) ::horus::Log::getLogger()->info(__VA_ARGS__)
#define H_WARN(...) ::horus::Log::getLogger()->warn(__VA_ARGS__)
#define H_ERROR(...) ::horus::Log::getLogger()->error(__VA_ARGS__)
#define H_CRITICAL(...) ::horus::Log::getLogger()->critical(__VA_ARGS__)
#else
#define H_TRACE(...)
#define H_INFO(...)
#define H_WARN(...)
#define H_ERROR(...)
#define H_CRITICAL(...)
#endif
