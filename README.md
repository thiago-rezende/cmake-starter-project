# C++ Starter Project Using CMake
![build-status-badge] ![license-badge] ![cpp-badge] ![cmake-badge]
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/thiago-rezende/cmake-starter-project">
    <img src="https://github.com/thiago-rezende/cmake-starter-project/raw/main/.github/logo.png" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">CMake Starter Project</h3>
  <p align="center">
    A Simple C++ Starter Project Using CMake
    <br />
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Report Bug</a>
    ·
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Request Feature</a>
    .
    <a href="https://github.com/thiago-rezende/cmake-starter-project/actions">Continuous Integration</a>
  </p>
</div>

 - Libraries Included
    - [Spdlog][spdlog-url]
    - [Catch2][catch2-url]

 - Features
    - Full featured logger
    - Assertion utilities compatible with the logger
    - Instrumentation for profiling [compatible with chromium tracing]
    - Platform detection utilities
    - Documentation generation with Doxygen
    - Unit testing with Catch2 and CTest
    - CI with GitHub Actions
    - Pre-compiled headers to improve build times

 - Project structure
 ```
    .
    ├── .github                         # Repository stuff.
    ├── application                     # Application folder.
    |    ├── share                      # Assets folder [DATADIR].
    |    ├── core                       # Core functionalities folder.
    |    |    ├── logger.h              # Logger utils.
    |    |    ├── logger.cpp            # Logger utils implementation.
    |    |    └── platform_detection.h  # Platform detection macros.
    |    ├── debug                      # Debug functionalities folder.
    |    |    ├── assert.h              # Assertion utils.
    |    |    └── instrumentor.h        # Profiling utils.
    |    ├── pch.hpp                    # Pre-compiled header.
    |    ├── config.h                   # Populated at config time.
    |    ├── config.h.in                # Template for config.h.
    |    ├── main.cpp                   # Application entrypoint.
    |    └── CMakeLists.txt             # Application CMake build script.
    ├── tests                           # Tests folder.
    |    ├── application                # Application tests.
    |    |    ├── CMakeLists.txt        # Application tests CMake script.
    |    |    └── never_fails.cpp       # Application test file.
    |    └── CMakeLists.txt             # Main CMake tests script.
    ├── vendor                          # Third-party packages will be here.
    |    ├── spdlog                     # Fast C++ logging library.
    |    └── catch2                     # A modern, C++-native, header-only, test framework.
    └── CMakeLists.txt                  # Main CMake build script.
```
 ## Compatibility

 | Toolset | Windows |  Linux  |   MacOS    |
 | :-----: | :-----: | :-----: | :--------: |
 |   GCC   |    ✔️    |    ✔️    |    ✔️    |
 |  Clang   |    ✔️    |    ✔️    |    ✔️    |
 |  MSVC   |    ✔️    | ------- | ---------- |

<!-- Links -->
[cmake-url]: https://cmake.org/
[spdlog-url]: https://github.com/gabime/spdlog
[catch2-url]: https://github.com/catchorg/Catch2

<!-- Badges -->
[build-status-badge]: https://github.com/thiago-rezende/cmake-starter-project/workflows/build/badge.svg
[license-badge]: https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square
[cmake-badge]: https://img.shields.io/badge/CMake-3.16.0-blueviolet.svg?style=flat-square
[cpp-badge]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
