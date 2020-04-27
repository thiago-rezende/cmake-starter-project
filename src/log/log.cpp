#include "log.h"

namespace Horus
{
    std::shared_ptr<spdlog::logger> Log::s_horusLogger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%n][%l]: %v%$");
        s_horusLogger = spdlog::stdout_color_mt("LOG");
        s_horusLogger->set_level(spdlog::level::trace);
    }
}
