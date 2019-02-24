# C-Plus-Plus Sample Project Using CMake

![](https://img.shields.io/badge/build-passing-green.svg) ![](https://img.shields.io/badge/CMake-3.14.0-blue.svg) ![](https://img.shields.io/badge/C++-17-orange.svg)

 - A simple c-plus-plus project using CMake.
 
 - Project structure
 ```
    .
    ├── bin                      # Binaries will be here.
    ├── proj-test                # The main project.
    │   ├── include              # Headers folder.
    │   └── src                  # Source folder.
    │       ├── main.cpp         # Your code goes here.
    |       └── CMakeLists.txt   # Project CMake build script.
    └── CMakeLists.txt           # Main CMake build script.
```
 ### How to Use
 - first download and install CMake [here](https://cmake.org/download/), is highly recommended to read the documentation [here](https://cmake.org/cmake-tutorial/) to extend the project.
 - execute the following commands
 
     ```
     git clone https://github.com/thiago-rezende/cmake_sample_proj.git
     cd cmake_sample_proj
     mkdir build
     cd build
     cmake .. -DCMAKE_INSTALL_PREFIX=..
     ```
 - if you want a specific generator just use the following command
     ```
     cmake .. -DCMAKE_INSTALL_PREFIX=.. -G"YOUR-GENERATOR-HERE"
     ```
 
 - Compatibility
 
 | Toolset  |    Windows    |     Linux     |     MacOS     |
 |:--------:|:-------------:|:-------------:|:-------------:|
 | GCC      |    Passing    |    Passing    |   Not Tested  |
 | LLVM     |   Not Tested  |   Not Tested  |   Not Tested  |
 | MSVC     |    Passing    |    -------    |   ----------  |
