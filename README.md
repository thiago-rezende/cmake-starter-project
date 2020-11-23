# C-Plus-Plus Starter Project Using CMake
![build-status-badge] ![license-badge] ![cpp-badge] ![cmake-badge]
<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/thiago-rezende/cmake-starter-project">
    <img src=".github/logo.png" alt="Logo" width="100" height="100">
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
    - [GoogleTest][googletest-url]

 - Project structure
 ```
    .
    ├── .github                     # Repository stuff.
    ├── application                 # Application folder.
    |    ├── assets                 # Assets folder.
    |    ├── core                   # Core functionalities folder.
    |    |    ├── logger.h          # Logger utils.
    |    |    └── logger.cpp        # Logger utils implementation.
    |    ├── pch.h                  # Pre-compiled header.
    |    ├── main.cpp               # Application entrypoint.
    |    └── CMakeLists.txt         # Application CMake build script.
    ├── tests                       # Tests folder.
    |    ├── application            # Application tests.
    |    |    ├── CMakeLists.txt    # Application tests CMake script.
    |    |    ├── main.cpp          # Application main test file.
    |    |    └── never_fails.cpp   # Application test file.
    |    └── CMakeLists.txt         # Main CMake tests script.
    ├── vendor                      # Third-party packages will be here.
    |    ├── spdlog                 # Fast C++ logging library.
    |    └── googletest             # Google testing and mocking framework.
    └── CMakeLists.txt              # Main CMake build script.
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
[googletest-url]: https://github.com/google/googletest

<!-- Badges -->
[build-status-badge]: https://github.com/thiago-rezende/cmake-starter-project/workflows/build/badge.svg
[license-badge]: https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square
[cmake-badge]: https://img.shields.io/badge/CMake-3.16.0-blueviolet.svg?style=flat-square
[cpp-badge]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
