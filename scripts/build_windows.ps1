$env:VCPKG_ROOT = "D:\_Windows\vcpkg"
$env:PATH = "$env:VCPKG_ROOT;$env:PATH"
vcpkg install
cmake -B cmake-build-debugvisualstudio -S . -DCMAKE_TOOLCHAIN_FILE=D:/_Windows/vcpkg/scripts/buildsystems/vcpkg.cmake