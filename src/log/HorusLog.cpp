#include "HorusLog.h"

namespace horus
{
    std::shared_ptr<spdlog::logger> Log::s_horusLogger;

    void Log::init()
    {
        spdlog::set_pattern("%^[%n][%l]: %v%$");
        s_horusLogger = spdlog::stdout_color_mt("HORUS_LOG");
        s_horusLogger->set_level(spdlog::level::trace);
    }
}
