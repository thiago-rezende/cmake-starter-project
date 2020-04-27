#include "pch.h"
#include "project_config.h"
#include "log/log.h"

int main(int argc, char **argv)
{
    // Initialize the Logger
    Horus::Log::init();

    H_INFO("CMake Starter Project!");
    H_INFO("PROJECT_NAME: {}", PROJECT_NAME);
    H_INFO("PROJECT_VERSION: {}", MyProject_VERSION);

    H_TRACE("--- HORUS LOG ---");
    H_INFO("That's an info.");
    H_WARN("That's an warning.");
    H_ERROR("That's an error.");
    H_CRITICAL("That's an critical.");

    return 0;
}
