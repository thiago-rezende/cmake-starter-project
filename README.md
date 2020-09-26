# C-Plus-Plus Starter Project Using CMake
![license-badge] ![cpp-badge] ![cmake-badge]
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
  </p>
</div>

 - Libraries Included
    - [Spdlog][spdlog-url]

 - Project structure
 ```
    .
    ├── .github                  # Repository stuff.
    ├── application              # Application folder.
    |    ├── assets              # Assets folder.
    |    ├── include             # Headers folder.
    |    |    └── pch.h          # Precompiled header file.
    |    ├── source              # Sources folder.
    |    |    └── main.cpp       # Application entry point.
    |    └── CMakeLists.txt      # Application CMake build script.
    ├── vendor                   # Third-party packages will be here.
    |    └── spdlog              # Fast C++ logging library.
    └── CMakeLists.txt           # Main CMake build script.
```
 ## Compatibility

 | Toolset | Windows |  Linux  |   MacOS    |
 | :-----: | :-----: | :-----: | :--------: |
 |   GCC   |    ✔️    |    ✔️    | Not Tested |
 |  Clang   |    ✔️    |    ✔️    | Not Tested |
 |  MSVC   |    ✔️    | ------- | ---------- |

<!-- Links -->
[cmake-url]: https://cmake.org/
[spdlog-url]: https://github.com/gabime/spdlog

<!-- Badges -->
[license-badge]: https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square
[cmake-badge]: https://img.shields.io/badge/CMake-3.16.0-blueviolet.svg?style=flat-square
[cpp-badge]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
