# C-Plus-Plus Starter Project Using CMake

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
    <a href="#how-to-use"><strong>Explore the docs »</strong></a>
    <br />
    <br />
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Report Bug</a>
    ·
    <a href="https://github.com/thiago-rezende/cmake-starter-project/issues">Request Feature</a>
  </p>
</div>

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

## Contributors ✨

Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):

<!-- ALL-CONTRIBUTORS-LIST:START - Do not remove or modify this section -->
<!-- prettier-ignore-start -->
<!-- markdownlint-disable -->
<table>
  <tr>
    <td align="center"><a href="https://gitlab.com/thiago-rezende"><img src="https://assets.gitlab-static.net/uploads/-/system/user/avatar/4377814/avatar.png" width="100px;" alt="Thiago Rezende"/><br /><sub><b>Thiago Rezende</b></sub></a><br /><a href="https://gitlab.com/thiago-rezende/cmake-starter-project/commits/master" title="Code">💻</a> <a href="https://gitlab.com/thiago-rezende/cmake-starter-project/commits/master" title="Tests">⚠️</a> <a href="https://gitlab.com/thiago-rezende/cmake-starter-project/commits/master" title="Documentation">📖</a> <a href="#example-thiago-rezende" title="Examples">💡</a> <a href="#ideas-thiago-rezende" title="Ideas, Planning, & Feedback">🤔</a> <a href="#infra-thiago-rezende" title="Infrastructure (Hosting, Build-Tools, etc)">🚇</a> <a href="#maintenance-thiago-rezende" title="Maintenance">🚧</a> <a href="#security-thiago-rezende" title="Security">🛡️</a> <a href="#review-thiago-rezende" title="Reviewed Pull Requests">👀</a> <a href="https://gitlab.com/thiago-rezende/cmake-starter-project/issues?author_username=thiago-rezende" title="Bug reports">🐛</a></td>
  </tr>
</table>

<!-- markdownlint-enable -->
<!-- prettier-ignore-end -->
<!-- ALL-CONTRIBUTORS-LIST:END -->

This project follows the [all-contributors](https://github.com/all-contributors/all-contributors) specification. Contributions of any kind welcome!