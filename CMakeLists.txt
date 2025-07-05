cmake_minimum_required(VERSION 3.30)
project(mars)

SET(TARGET_NAME mars)

# C++ STANDARD
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_OSX_ARCHITECTURES "arm64")

# INCLUDE
# include(FetchContent)
INCLUDE(cmake/AppleSetup.cmake) # guards are already in file
INCLUDE(cmake/WindowsSetup.cmake) # guards are already in file
if(APPLE OR WIN32)
    INCLUDE(cmake/VcpkgDependencies.cmake)
else ()
    INCLUDE(cmake/ConanDependencies.cmake)
endif ()
INCLUDE(cmake/VendorDependencies.cmake)


# Define a macro in debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

# MODULES - we set modules in cmake_modules folder.
# Pattern is `Find<module>.cmake`
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

# VARIABLES
if(APPLE)

    # Set Homebrew paths for macOS
    SET(CMAKE_PREFIX_PATH "/opt/homebrew;/usr/local" CACHE PATH "Path to Homebrew libraries")

    FIND_LIBRARY(OPENGL_LIBRARY OpenGL REQUIRED) # Find OpenGL framework
    if(NOT OPENGL_LIBRARY)
        MESSAGE(FATAL_ERROR "OpenGL framework not found")
    endif()
    MESSAGE(STATUS "OpenGL framework: ${OPENGL_LIBRARY}")
endif()

# PACKAGES

if(EMSCRIPTEN)
    find_package(lua REQUIRED)
endif()

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${PACKAGES_INCLUDE}
        ${GLAD_INCLUDE_DIR}
        ${CATCH2_INCLUDE_DIR}
        ${BOX2D_INCLUDE_DIR}
        ${LUA_INCLUDE_DIR}
        ${SOL_INCLUDE_DIR}
        ${ENTT_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
        vendor/ldtk
        vendor/nlohmann
        vendor/angle

        # if APPLE
        ${APPLE_INCLUDE}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${PACKAGES_SOURCES}
        include/gpu_util/dx11/dx11_util.h
        include/gpu_util/dx11/dx11_util.h)

# LINK
target_link_libraries(mars
        ${PACKAGES_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        glm::glm
        # spdlog::spdlog_header_only
        tinyxml2::tinyxml2
        EnTT::EnTT
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARIES}
        ${OPENGL_LIBRARY}

        # APPLE DEVICES
        ${APPLE_LIBRARIES}

        # WINDOWS DEVICES
        ${WINDOWS_LIBRARIES}
)

# Copy 'contents' and 'vendor' files.
INCLUDE(cmake/CopyContents.cmake)

# Copy 'contents' as post build script to executable directory.
INCLUDE(cmake/CopyContentsAfterBuild.cmake)

# TESTS
add_executable(tests
        tests/tests.cpp
        ${COMMON_SOURCES}
        ${PACKAGES_SOURCES}
        tests/geometry_tests.cpp)

# ASSET TOOLKIT TESTS
file(GLOB ASSET_TOOLKIT_SOURCES src/asset_toolkit/*.cpp src/asset_toolkit/**/*.cpp src/asset_toolkit/**/**/*.cpp)
# add_executable(asset_toolkit_tests ${ASSET_TOOLKIT_SOURCES})

target_link_libraries(tests
        ${PACKAGES_LIBRARIES}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        # spdlog::spdlog_header_only
        tinyxml2::tinyxml2
        EnTT::EnTT
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARIES}
)

# GAMES

# add_executable(chopper-shooter chopper-shooter.cpp
#        ${COMMON_SOURCES}
#        ${GLAD_SRC}
#)

#target_link_libraries(chopper-shooter)
