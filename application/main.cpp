/**
 * @file main.cpp
 * @brief Application Entry Point
 *
 */

/* Application Entry Point */
int main(int argc, char **argv)
{
    /* Starts Profile Session */
    H_PROFILE_BEGIN_SESSION("Application Profile", "profile_results.json");

    {
        /* Profiles the Main Function */
        H_PROFILE_FUNCTION();

        /* Initialize Logger */
        Horus::Logger::init();

        {
            /* Profiles the Logging ShowCase Scope */
            H_PROFILE_SCOPE("Logging Showcase");

            /* CMake Configured File Defines */
            H_INFO("[PROJECT_NAME] {}", PROJECT_NAME);
            H_INFO("[PROJECT_VERSION] {}", PROJECT_VERSION);
            H_INFO("[PROJECT_DESCRIPTION] {}", PROJECT_DESCRIPTION);
            H_INFO("[PROJECT_URL] {}", PROJECT_HOMEPAGE_URL);

            /* Platform Detection Utils */
#if defined(H_PLATFORM_WINDOWS)
            H_INFO("[PLATFORM] {}", "Windows");
#elif defined(H_PLATFORM_IOS)
            H_INFO("[PLATFORM] {}", "IOS");
#elif defined(H_PLATFORM_MACOS)
            H_INFO("[PLATFORM] {}", "MACOS");
#elif defined(H_PLATFORM_ANDROID)
            H_INFO("[PLATFORM] {}", "Android");
#elif defined(H_PLATFORM_LINUX)
            H_INFO("[PLATFORM] {}", "Linux");
#endif

            /* Log Utils */
            H_TRACE("That's a trace!");
            H_DEBUG("That's a debug.");
            H_INFO("That's an info.");
            H_WARN("That's a warning.");
            H_ERROR("That's an error.");
            H_CRITICAL("That's a critical.");

            /* CLI Args */
            if (argc > 1)
            {
                H_INFO("[CLI] Args");
                for (size_t i = 1; i < argc; i++)
                    H_INFO(" - [{}] {}", i - 1, argv[i]);
            }
        }
    }

    /* Ends Profile Session */
    H_PROFILE_END_SESSION();

    /* Assertions Examples */
    H_ASSERT(true);                                  // Assertion with default message
    H_ASSERTM(true, "Assertion with {}", "message"); // Assertion with user defined message

    return 0;
}
