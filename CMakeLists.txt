cmake_minimum_required(VERSION 3.30)
project(mars)

SET(TARGET_NAME mars)

# C++ STANDARD
SET(CMAKE_CXX_STANDARD 20)
SET(CMAKE_OSX_ARCHITECTURES "arm64")

# INCLUDE
# include(FetchContent)
INCLUDE(cmake/AppleSetup.cmake) # guards are already in file
if(APPLE OR WIN32)
    INCLUDE(cmake/VcpkgDependencies.cmake)
else ()
    INCLUDE(cmake/ConanDependencies.cmake)
endif ()
INCLUDE(cmake/VendorDependencies.cmake)

# PRE-SETUP
if(WIN32)
    # Find and set the manifest tool path
    find_program(CMAKE_MT mt.exe
            PATHS
            "C:/Program Files (x86)/Windows Kits/10/bin/10.0.22621.0/x64"
            DOC "Path to mt.exe"
    )

    if(NOT CMAKE_MT)
        message(WARNING "mt.exe not found - manifest embedding may fail")
    endif()
endif()

# Define a macro in debug mode
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    add_compile_definitions(DEBUG)
endif()

# SYSTEM PACKAGES ( OR INSTALLED THROUGH HOME-BREW, VCPKG, etc. )
if(WIN_32)
find_package(SDL2 CONFIG REQUIRED)
set(SDL2_LIBRARY $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
find_package(SDL2_image CONFIG REQUIRED)
set(SDL2_IMAGE_LIBRARY $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
find_package(glm CONFIG REQUIRED)
find_package(lua CONFIG REQUIRED)
find_package(boost CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(tinyxml2 CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)
endif()

# MODULES - we set modules in cmake_modules folder.
# Pattern is `Find<module>.cmake`
list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

# VARIABLES
if(WIN32)

    set(DX11 d3d11 dxgi d3dcompiler)

    # set(LUA_PATH "D:\\_Windows\\lua")
    # set(LUA_INCLUDE_DIR "${LUA_PATH}")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
elseif(APPLE)

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

        # if APPLE
        ${APPLE_INCLUDE}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${PACKAGES_SOURCES}
        include/util/metal/metal_library_utility.h
        src/util/metal/metal_library_utility.cpp
        include/util/metal/metal_function_utility.h
        src/util/metal/metal_function_utility.cpp
        src/util/metal/metal_utility.cpp
        src/util/logger.cpp)

# DEFINITIONS
if(WIN32)
    target_compile_definitions(mars PUBLIC
        ALLOW_DX11=1
)
elseif (APPLE)
    target_compile_definitions(mars PUBLIC
            ALLOW_METAL=1
    )
endif()

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
        ${DX11}
)

# COPY SHARED LIBS
if(WIN32)
    #file(COPY shared_libs/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    #file(COPY shared_libs/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
    # file(COPY shared_libs/lua54.dll DESTINATION ${CMAKE_BINARY_DIR})
endif()

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
