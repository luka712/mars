$env:VCPKG_ROOT = "C:\path\to\vcpkg"
$env:PATH = "$env:VCPKG_ROOT;$env:PATH"
vcpkg install
cmake -B cmake-build-debugvisualstudio -S . -DCMAKE_TOOLCHAIN_FILE={{PATH_TO_VCPKG}}/vcpkg/scripts/buildsystems/vcpkg.cmake