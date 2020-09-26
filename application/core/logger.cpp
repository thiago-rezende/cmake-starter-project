#include <application/core/logger.h>

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Horus
{
    std::shared_ptr<spdlog::logger> Logger::s_horus_logger;

    void Logger::Init()
    {
        spdlog::set_pattern("%^[%n][%l]: %v%$");
        s_horus_logger = spdlog::stdout_color_mt("LOGGER");
        s_horus_logger->set_level(spdlog::level::trace);
    }
} // namespace Horus
