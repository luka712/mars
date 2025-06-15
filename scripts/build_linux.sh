#!/bin/bash

# Create build directory
mkdir -p cmake-build-debug-linux
cd cmake-build-debug-linux

# Install dependencies via Conan (with build missing to compile any missing libs)
conan install .. --build=missing

# Configure project with CMake, specify Ninja generator if you want
cmake .. -G Ninja

# Build
cmake --build .
