# Mars

## What is Mars?

Mars is C++ game framework created to run on variety of devices with different rendering backends.
It can be used as low-level or as high level ECS framework.

### Install

#### Windows

Windows is configured for usage with **Visual Studio 17 2022**.

Cmake should be using
- Toolchain: Visual Studio 17 2022
- Generator: Visual Studio 17 2022

For **Windows** or **WIN32** we use `vcpkg` to install dependencies.
To install it see [here](https://learn.microsoft.com/hr-hr/vcpkg/get_started/get-started?pivots=shell-powershell).

First we need to install vcpkg dependencies.
Run `vcpkg install` to install dependencies.

If you need to set up a path to vcpkg, try setting up `script/set-vcpkg.ps1` script. There is template for it.
Make sure to modify path in template to your vcpkg installation path.

Then run
`cmake -B cmake-build-debugvisualstudio -S . -DCMAKE_TOOLCHAIN_FILE={{PATH_TO_VCPKG}}/vcpkg/scripts/buildsystems/vcpkg.cmake`

for example:

`cmake -B cmake-build-debugvisualstudio -S . -DCMAKE_TOOLCHAIN_FILE=D:/_Windows/vcpkg/scripts/buildsystems/vcpkg.cmake`

### Build

It is tested with C-Lion as IDE.
CMakeLists.txt should be built.

To build simply run `cmake`.

This will download all required dependencies in `cmake-build-debug` folder.

Main project is called `mars`.

#### Linux 

For Linux CLion integration with `conan` is used.
For more see https://www.jetbrains.com/help/clion/conan-plugin.html#add-lib
After integration is done, simply run `DebugLinux` from CLion.

Then to build run 
`ninja -C /datadisk1/Projects/mars/cmake-build-debuglinux`

### EMSCRIPTEN

For emscripten build, `Makefile` is provided in root directory.
If building from new folder make sure to download **EMSCRIPTEN** and then override
`load_emscripten.sh.template`. Simply set `EMSDK_FOLDER` to appropriate folder and run `load_emscripten.sh`.
Of course delete `.template` from your file.

Use `make all` to compile to emscripten.
Use `make run` to run in browser.

### LUA
> [!WARNING]
> Use system Lua for everything except for EMSCRIPTEN.

#### EMSCRIPTEN DEPENDENCIES 

##### LUA 
It can be build by running `make compile_lua`.
This will create `static_libs/emscripten/liblua.a` file.
Note that `cmake-build-debug/_deps/lua-src/lua.c` will cause issues and should be removed before build.

### TROUBLESHOOTING BUILD



### RENDERERS

 | rendering backend | Windows | MacOS | Linux | Android | iOS | Browser |
 |  opengles         |   [x]   |  [ ]  |  [x]  |  [ ]    | [ ] |  [x]    |
 |   metal           |   [ ]   |  [x]  |  [ ]  |  [ ]    | [ ] |  [ ]    |
 |   d3d11           |   [x]   |  [ ]  |  [ ]  |  [ ]    | [ ] |  [ ]    |