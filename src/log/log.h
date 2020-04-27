#pragma once

#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

namespace Horus
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
#define H_TRACE(...) ::Horus::Log::getLogger()->trace(__VA_ARGS__)
#define H_INFO(...) ::Horus::Log::getLogger()->info(__VA_ARGS__)
#define H_WARN(...) ::Horus::Log::getLogger()->warn(__VA_ARGS__)
#define H_ERROR(...) ::Horus::Log::getLogger()->error(__VA_ARGS__)
#define H_CRITICAL(...) ::Horus::Log::getLogger()->critical(__VA_ARGS__)
#else
#define H_TRACE(...)
#define H_INFO(...)
#define H_WARN(...)
#define H_ERROR(...)
#define H_CRITICAL(...)
#endif
