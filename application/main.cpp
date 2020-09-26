#include "pch.h"
#include "core/logger.h"

int main()
{
    /* Initialize Logger */
    Horus::Logger::Init();

    /* Some Log Utils */
    H_TRACE("CMake Starter Project!");
    H_DEBUG("That's a debug.");
    H_INFO("That's an info.");
    H_WARN("That's a warning.");
    H_ERROR("That's an error.");
    H_CRITICAL("That's a critical.");

    return 0;
}
