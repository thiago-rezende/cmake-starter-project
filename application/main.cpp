#include <application/pch.h>
#include <application/core/logger.h>
#include <config.h>

int main()
{
    /* Initialize Logger */
    Horus::Logger::Init();

    /* CMake Configured File Defines */
    H_INFO("PROJECT NAME => {}", PROJECT_NAME);
    H_INFO("PROJECT VERSION => {}", PROJECT_VERSION);

    /* Some Log Utils */
    H_TRACE("CMake Starter Project!");
    H_DEBUG("That's a debug.");
    H_INFO("That's an info.");
    H_WARN("That's a warning.");
    H_ERROR("That's an error.");
    H_CRITICAL("That's a critical.");

    return 1;
}
