#! /bin/bash

export VCPKG_ROOT=/Users/lerkapic/Desktop/Development/vcpkg
export PATH=$VCPKG_ROOT:$PATH

vcpkg install
cmake -G Xcode -DCMAKE_C_COMPILER=/usr/bin/clang -DCMAKE_CXX_COMPILER=/usr/bin/clang++ -DCMAKE_TOOLCHAIN_FILE=/Users/lerkapic/Desktop/Development/vcpkg/scripts/buildsystems/vcpkg.cmake
