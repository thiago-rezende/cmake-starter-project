/**
 * @file logger.h
 * @brief Simple Log Utility
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
        static void init(const std::string &logger_name = "log");

        /**
         * @brief Get the logger object
         *
         * @return std::shared_ptr<spdlog::logger>&
         */
        inline static std::shared_ptr<spdlog::logger> &get_logger() { return s_logger; }
    };

} // namespace Horus

/* Logger Macros */
#ifdef ENABLE_LOGGER // Only defined on debug builds to save performance
#define H_TRACE(...) ::Horus::Logger::get_logger()->trace(__VA_ARGS__)
#define H_DEBUG(...) ::Horus::Logger::get_logger()->debug(__VA_ARGS__)
#define H_INFO(...) ::Horus::Logger::get_logger()->info(__VA_ARGS__)
#define H_WARN(...) ::Horus::Logger::get_logger()->warn(__VA_ARGS__)
#define H_ERROR(...) ::Horus::Logger::get_logger()->error(__VA_ARGS__)
#define H_CRITICAL(...) ::Horus::Logger::get_logger()->critical(__VA_ARGS__)
#else
#define H_TRACE(...)
#define H_DEBUG(...)
#define H_INFO(...)
#define H_WARN(...)
#define H_ERROR(...)
#define H_CRITICAL(...)
#endif
