# C-Plus-Plus Starter Project Using CMake

<!-- PROJECT LOGO -->
<br />
<div align="center">
  <a href="https://github.com/thiago-rezende/cmake-starter-project">
    <img src=".gitlab/logo.png" alt="Logo" width="100" height="100">
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
</div>

 - Libraries Included
   - [CMakePCH][cmake-pch-url]
   - [CMake Lua][cmake-lua-url]
   - [Sol3][sol3-url]

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
    |    └── cmake-lua           # CMake script to build lua.
    |    └── sol3                # Sol3 Lib.
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
[cmake-pch-url]: https://github.com/larsch/cmake-precompiled-header.git
[cmake-lua-url]: https://gitlab.com/thiago-rezende/cmake-lua.git
[sol3-url]: https://github.com/thephd/sol2

## Contributors ✨

[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/0)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/0)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/1)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/1)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/2)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/2)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/3)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/3)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/4)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/4)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/5)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/5)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/6)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/6)[![](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/images/7)](https://sourcerer.io/fame/thiago-rezende/thiago-rezende/cmake-starter-project/links/7)
