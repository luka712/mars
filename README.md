# Mars

### What is Mars?

Mars is C++ game framework created to run on variety of devices with different rendering backends.
It can be used as low-level or as high level ECS framework.

### Build

It is tested with C-Lion as IDE.
CMakeLists.txt should be build.
This will download all required dependencies in `cmake-build-debug` folder.
Main project is called `mars`.

#### Linux 
From `cmake-build-debug` folder run `.. cmake`

### EMSCRIPTEN

For emscripten build, `Makefile` is provided in root directory.
If building from new folder make sure to download **EMSCRIPTEN** and then override
`load_emscripten.sh.template`. Simply set `EMSDK_FOLDER` to appropriate folder and run `load_emscripten.sh`.
Of course delete `.template` from your file.

Use `make all` to compile to emscripten.
Use `make run` to run in browser.

#### EMSCRIPTEN DEPENDENCIES 

##### LUA 
It can be build by running `make compile_lua`.
This will create `static_libs/emscripten/liblua.a` file.
Note that `cmake-build-debug/_deps/lua-src/lua.c` will cause issues and should be removed before build.

### TROUBLESHOOTING BUILD

#### Windows

Cmake should be using:
- Toolchain: MinGW
- Generator: MinGW Makefiles