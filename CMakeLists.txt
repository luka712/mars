cmake_minimum_required(VERSION 3.30)
project(mars)

include(FetchContent)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

# VARIABLES
if(WIN32)
    # NOTE: SET DIFFERENT PATH FOR YOUR SDL2 INSTALLATION
    set(SDL2_PATH "D:/_Windows/Libs/SDL2-devel-2.30.9-mingw/SDL2/x86_64-w64-mingw32")
endif()

# PACKAGES
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIR}
       "D:/Projects/mars/cmake-build-debug/_deps/glm-src"
        ${GLM_INCLUDE_DIR}
)

file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)


# EXECUTABLE
add_executable(mars ${COMMON_SOURCES} main.cpp
        include/core/math/Color.h
        include/core/math/Rect.h
        include/sdl/sprite/SDLSpriteBatch.h
        include/core/mesh/Mesh.h
        include/core/mesh/SpriteBatchMesh.h
        include/core/sprite/SpriteBatchDrawable.h
        include/core/time/Time.h
        include/core/time/TimeManager.h
        src/core/time/TimeManager.cpp
)

target_link_libraries(mars ${SDL2_LIBRARY} ${GLM_LIBRARY})
