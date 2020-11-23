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
         * @brief Logger
         *
         */
        static std::shared_ptr<spdlog::logger> s_logger;

    public:
        /**
         * @brief Initialize the logging system
         *
         */
        static void Init();

        /**
         * @brief Get the logger object
         *
         * @return std::shared_ptr<spdlog::logger>&
         */
        inline static std::shared_ptr<spdlog::logger> &GetLogger() { return s_logger; }
    };

} // namespace Horus

/* Logger Macros */
#ifdef ENABLE_LOG_MACROS // Only defined on debug builds to save performance
#define H_TRACE(...) ::Horus::Logger::GetLogger()->trace(__VA_ARGS__)
#define H_DEBUG(...) ::Horus::Logger::GetLogger()->debug(__VA_ARGS__)
#define H_INFO(...) ::Horus::Logger::GetLogger()->info(__VA_ARGS__)
#define H_WARN(...) ::Horus::Logger::GetLogger()->warn(__VA_ARGS__)
#define H_ERROR(...) ::Horus::Logger::GetLogger()->error(__VA_ARGS__)
#define H_CRITICAL(...) ::Horus::Logger::GetLogger()->critical(__VA_ARGS__)
#else
#define H_TRACE(...)
#define H_DEBUG(...)
#define H_INFO(...)
#define H_WARN(...)
#define H_ERROR(...)
#define H_CRITICAL(...)
#endif
