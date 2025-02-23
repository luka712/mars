# Mars

### What is Mars?

Mars is C++ game framework created to run on variety of devices with different rendering backends.
It can be used as low-level or as high level ECS framework.

### Build

It is tested with C-Lion as IDE.
CMakeLists.txt should be build.
This will download all required dependencies in `cmake-build-debug` folder.
Main project is called `mars`.

### EMSCRIPTEN

For emscripten build, `Makefile` is provided in root directory.
If building from new folder make sure to download **EMSCRIPTEN** and then override
`load_emscripten.sh.template`. Simply set `EMSDK_FOLDER` to appropriate folder and run `load_emscripten.sh`.
Of course delete `.template` from your file.

Use `make all` to compile to emscripten.
Use `make run` to run in browser.

