cmake_minimum_required(VERSION 3.30)
project(mars)

# C++ STANDARD
set(CMAKE_CXX_STANDARD 20)

# INCLUDE
include(FetchContent)

# SYSTEM PACKAGES
find_package(lua)

# MODULES - we set modules in cmake_modules folder.
# Pattern is `Find<module>.cmake`
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

# VARIABLES
if(WIN32)
    # NOTE: SET DIFFERENT PATH FOR YOUR SDL2 INSTALLATION
    set(SDL2_PATH "D:/_Windows/Libs/SDL2-devel-2.30.9-mingw/SDL2/x86_64-w64-mingw32")
    set(SDL2_IMAGE_PATH "D:/_Windows/Libs/SDL2_image-devel-2.8.3-mingw/SDL2_image-2.8.3/x86_64-w64-mingw32")

    set(LUA_PATH "D:/_Windows/lua")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++ -pthread")
elseif(APPLE)
    # Set Homebrew paths for macOS
    set(CMAKE_PREFIX_PATH "/opt/homebrew;/usr/local" CACHE PATH "Path to Homebrew libraries")

    find_library(OPENGL_LIBRARY OpenGL REQUIRED) # Find OpenGL framework
    if(NOT OPENGL_LIBRARY)
        message(FATAL_ERROR "OpenGL framework not found")
    endif()
    message(STATUS "OpenGL framework: ${OPENGL_LIBRARY}")
endif()

# PACKAGES
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(tinyxml2 REQUIRED)
find_package(Catch2 REQUIRED)
find_package(box2d REQUIRED)
find_package(sol REQUIRED)
if(EMSCRIPTEN)
    find_package(lua REQUIRED)
endif()

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
        ${SPDLOG_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        ${TINYXML2_INCLUDE_DIR}
        ${CATCH2_INCLUDE_DIR}
        ${BOX2D_INCLUDE_DIR}
        ${LUA_INCLUDE_DIR}
        ${SOL_INCLUDE_DIR}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC})

# LINK
target_link_libraries(mars
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARY}
        ${OPENGL_LIBRARY}
)

# COPY SHARED LIBS
if(WIN32)
    file(COPY shared_libs/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY shared_libs/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY shared_libs/lua54.dll DESTINATION ${CMAKE_BINARY_DIR})
endif()

# COPY ASSETS/CONTENT/SHADERS
file(COPY content DESTINATION ${CMAKE_BINARY_DIR})
file(COPY content/shaders DESTINATION ${CMAKE_BINARY_DIR})

# COPY VENDOR
file(COPY vendor DESTINATION ${CMAKE_BINARY_DIR})

# TESTS
add_executable(tests tests/tests.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC}
        tests/geometry_tests.cpp)

# ASSET TOOLKIT TESTS
file(GLOB ASSET_TOOLKIT_SOURCES src/asset_toolkit/*.cpp src/asset_toolkit/**/*.cpp src/asset_toolkit/**/**/*.cpp)
add_executable(asset_toolkit_tests ${ASSET_TOOLKIT_SOURCES} tests/asset_toolkit/ldtk_tests.cpp
        include/asset_toolkit/asset_bundle/AssetBundle.h
        include/asset_toolkit/asset_bundle/sprite_sheet/SpriteSheet.h
        include/asset_toolkit/asset_bundle/AssetBundleLoader.h
        src/asset_toolkit/asset_bundle/AssetBundleLoader.cpp
        tests/asset_toolkit/asset_bundle_loader.cpp)

target_link_libraries(tests
        ${CATCH2_LIBRARY}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARY}
)

# GAMES
add_executable(chopper-shooter chopper-shooter.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC}
)

target_link_libraries(chopper-shooter
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARY}
        ${OPENGL_LIBRARY}
)
