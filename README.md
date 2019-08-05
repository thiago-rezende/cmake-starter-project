# C-Plus-Plus Starter Project Using CMake

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
     git clone --recursive https://github.com/thiago-rezende/cmake-starter-project.git
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

[cmake-url]: https://cmake.org/
