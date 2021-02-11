/**
 * @file main.cpp
 * @author Thiago Rezende (thiago-rezende.github.io)
 * @brief Application Entry Point
 *
 */

int main()
{
    /* Initialize Logger */
    Horus::Logger::init();

    /* CMake Configured File Defines */
    H_INFO("PROJECT NAME => {}", PROJECT_NAME);
    H_INFO("PROJECT VERSION => {}", PROJECT_VERSION);
    H_INFO("PROJECT DESCRIPTION => {}", PROJECT_DESCRIPTION);
    H_INFO("PROJECT URL => {}", PROJECT_HOMEPAGE_URL);

    /* Some Log Utils */
    H_TRACE("That's a trace!");
    H_DEBUG("That's a debug.");
    H_INFO("That's an info.");
    H_WARN("That's a warning.");
    H_ERROR("That's an error.");
    H_CRITICAL("That's a critical.");

    return 0;
}
