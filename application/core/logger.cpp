#include "core/logger.h"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Horus
{
    std::shared_ptr<spdlog::logger> Logger::s_logger = nullptr;

    void Logger::init(const std::string &logger_name)
    {
        spdlog::set_pattern("%^[%n][%l]: %v%$");
        s_logger = spdlog::stdout_color_mt(logger_name);
        s_logger->set_level(spdlog::level::trace);
    }
} // namespace Horus
