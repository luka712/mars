#! /bin/bash

export VCPKG_ROOT=/Users/lerkapic/Desktop/Development/vcpkg
export PATH=$VCPKG_ROOT:$PATH

vcpkg install
cmake -B cmake-build-debug-macos-xcode -S . -DCMAKE_TOOLCHAIN_FILE=/Users/lerkapic/Desktop/Development/vcpkg/scripts/buildsystems/vcpkg.cmake -DVCPKG_TARGET_TRIPLET=arm64-osx
