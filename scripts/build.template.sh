#! /bin/bash

export VCPKG_ROOT=/path/to/vcpkg
export PATH=$VCPKG_ROOT:$PATH

vcpkg install
# Add your own path to vcpkg.cmake
# Should be {{YOUR_PATH_TO_VCPKG}}/scripts/buildsystems/vcpkg.cmake
cmake -G Xcode -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_TOOLCHAIN_FILE=/path/to/vcpkg/scripts/buildsystems/vcpkg.cmake

