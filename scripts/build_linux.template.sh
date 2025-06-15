#! /bin/bash

export VCPKG_ROOT=/path/to/vcpkg
export PATH=$VCPKG_ROOT:$PATH

vcpkg install
# Add your own path to vcpkg.cmake
# Should be {{YOUR_PATH_TO_VCPKG}}/scripts/buildsystems/vcpkg.cmake
cmake -B cmake-build-debug-linux -G "Unix Makefiles" -S . -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

