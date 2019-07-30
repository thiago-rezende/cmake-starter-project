# C-Plus-Plus Starter Project Using CMake

<!--[![Build Status][build-shield]][build-url]-->
[![CircleCI](https://circleci.com/gh/thiago-rezende/ci-study.svg?style=svg)](https://circleci.com/gh/thiago-rezende/ci-study)
[![Build status](https://ci.appveyor.com/api/projects/status/oo46hf6k7cugb3wd?svg=true)](https://ci.appveyor.com/project/thiago-rezende/cmake-starter-project)
[![MIT License][license-shield]][license-url]
[![CMake 3.10.0][cmake-shield]][cmake-url]
[![C++ 17][cpp-shield]][cpp-url]
[![LinkedIn][linkedin-shield]][linkedin-url]



<!-- PROJECT LOGO -->
<br />
<p align="center">
  <a href="https://github.com/thiago-rezende/cmake-starter-project">
    <img src=".github/logo.png" alt="Logo" width="100" height="100">
  </a>

  <h3 align="center">CMake Starter Project</h3>

  <p align="center">
    A Simple C++ Starter Project Using CMake
    <br />
    <a href="#how-to-use"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Report Bug</a>
    ·
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Request Feature</a>
  </p>
</p>

 - Project structure
 ```
    .
    ├── .github                  # Repository stuff.
    ├── bin                      # Binaries will be here.
    ├── src                      # Source folder.
    |    ├── assets              # Assets folder.
    |    ├── main.cpp            # Application entry point.
    |    ├── pch.h               # Precompiled header file.
    |    ├── pch.cpp             # Procompiled deader source file.
    |    └── CMakeLists.txt      # Project CMake build script.
    ├── vendor                   # Third-party packages will be here.
    |    └── cmake-pch           # CMake precompiled hearder tool.
    └── CMakeLists.txt           # Main CMake build script.
```
 ### How to Use
 - first download and install CMake [here][cmake-url], is highly recommended to read the documentation [here](https://cmake.org/cmake-tutorial/) to extend the project.
 - execute the following commands

     ```
     git clone https://github.com/thiago-rezende/cmake-starter-project.git
     cd cmake-starter-project
     mkdir build
     cd build
     cmake ..
     make && make install
     ```

 - Compatibility

 | Toolset  |    Windows    |     Linux     |     MacOS     |
 |:--------:|:-------------:|:-------------:|:-------------:|
 | GCC      |       ✔️      |    ✔️        |   Not Tested  |
 | LLVM     |       ✔️      |    ✔️        |   Not Tested  |
 | MSVC     |       ✔️      |    -------   |   ----------  |

[build-shield]: https://img.shields.io/badge/build-passing-brightgreen.svg?style=flat-square
[build-url]: #
[license-shield]: https://img.shields.io/badge/license-MIT-blue.svg?style=flat-square
[license-url]: https://opensource.org/licenses/MIT
[cmake-shield]: https://img.shields.io/badge/CMake-3.10.0-blueviolet.svg?style=flat-square
[cmake-url]: https://cmake.org/
[cpp-shield]: https://img.shields.io/badge/C++-17-orange.svg?style=flat-square
[cpp-url]: https://cmake.org/
[linkedin-shield]: https://img.shields.io/badge/-LinkedIn-black.svg?style=flat-square&logo=linkedin&colorB=555
[linkedin-url]: https://www.linkedin.com/in/thiago-horus-rezende/
