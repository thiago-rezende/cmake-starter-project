/**
 * @file log.h
 * @author Thiago Rezende (thiago-rezende.github.io)
 * @brief Simple Log Utility
 * @version 0.1
 * @date 2020-09-26
 *
 * @copyright Copyright (c) 2020 Thiago Rezende
 *
 */

#pragma once

#include <spdlog/spdlog.h>

namespace Horus
{
    /**
     * @brief Horus Logger class
     *
     */
    class Logger
    {
    private:
        /**
         * @brief Horus logger
         *
         */
        static std::shared_ptr<spdlog::logger> s_horus_logger;

    public:
        /**
         * @brief Initialize the logging system
         *
         */
        static void Init();

        /**
         * @brief Get the horus logger object
         *
         * @return std::shared_ptr<spdlog::logger>&
         */
        inline static std::shared_ptr<spdlog::logger> &GetHorusLogger() { return s_horus_logger; }
    };

} // namespace Horus

/* Logger Macros */
#ifdef ENABLE_LOG_MACROS // Only defined on debug builds to save performance
#define H_TRACE(...) ::Horus::Logger::GetHorusLogger()->trace(__VA_ARGS__)
#define H_DEBUG(...) ::Horus::Logger::GetHorusLogger()->debug(__VA_ARGS__)
#define H_INFO(...) ::Horus::Logger::GetHorusLogger()->info(__VA_ARGS__)
#define H_WARN(...) ::Horus::Logger::GetHorusLogger()->warn(__VA_ARGS__)
#define H_ERROR(...) ::Horus::Logger::GetHorusLogger()->error(__VA_ARGS__)
#define H_CRITICAL(...) ::Horus::Logger::GetHorusLogger()->critical(__VA_ARGS__)
#else
#define H_TRACE(...)
#define H_DEBUG(...)
#define H_INFO(...)
#define H_WARN(...)
#define H_ERROR(...)
#define H_CRITICAL(...)
#endif
