cmake_minimum_required(VERSION 3.30)
project(mars)

# C++ STANDARD
set(CMAKE_CXX_STANDARD 20)

# INCLUDE
include(FetchContent)

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
find_package(SDL2 CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(lua CONFIG REQUIRED)

if(APPLE)

    find_library(FOUNDATION_LIBRARY Foundation REQUIRED)
    find_library(QUARTZ_CORE_LIBRARY QuartzCore REQUIRED)
    find_library(METAL_LIBRARY Metal REQUIRED)
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

    set(SDL2_LIBRARY $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
    set(SDL2_IMAGE_LIBRARY $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)

elseif(APPLE)
    set(CMAKE_OSX_ARCHITECTURES "arm64")

    # Set Homebrew paths for macOS
    set(CMAKE_PREFIX_PATH "/opt/homebrew;/usr/local" CACHE PATH "Path to Homebrew libraries")

    find_library(OPENGL_LIBRARY OpenGL REQUIRED) # Find OpenGL framework
    if(NOT OPENGL_LIBRARY)
        message(FATAL_ERROR "OpenGL framework not found")
    endif()
    message(STATUS "OpenGL framework: ${OPENGL_LIBRARY}")

    SET(METAL_INCLUDE_DIR ${CMAKE_BINARY_DIR}/vendor/metal-cpp)

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# PACKAGES
find_package(SDL2_image CONFIG REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(tinyxml2 REQUIRED)
find_package(Catch2 REQUIRED)
find_package(box2d REQUIRED)
find_package(sol REQUIRED)
find_package(Entt REQUIRED)
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
        ${ENTT_INCLUDE_DIR}

        # if APPLE
        ${METAL_INCLUDE_DIR}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC})

# DEFINITIONS
if(WIN32)
target_compile_definitions(mars PUBLIC
        ALLOW_DX11=1
)
endif()

# LINK
target_link_libraries(mars
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        glm::glm
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARIES}
        ${OPENGL_LIBRARY}

        # APPLE DEVICES
        ${QUARTZ_CORE_LIBRARY}
        ${FOUNDATION_LIBRARY}
        ${METAL_LIBRARY}

        # WINDOWS DEVICES
        ${DX11}
)

# COPY SHARED LIBS
if(WIN32)
    #file(COPY shared_libs/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    #file(COPY shared_libs/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
    # file(COPY shared_libs/lua54.dll DESTINATION ${CMAKE_BINARY_DIR})
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
        include/entt_ecs/entt_ecs.h
        include/entt_ecs/transform/rect_transform.h
        include/entt_ecs/transform/rect_transform_system.h
        src/entt_ecs/transform/rect_transform_system.cpp
        include/entt_ecs/sprite/sprite_renderer.h
        src/entt_ecs/entt_ecs.cpp
        include/entt_ecs/sprite/sprite_renderer_system.h
        src/entt_ecs/sprite/sprite_renderer_system.cpp
        include/metal/buffers/metal_vertex_buffer.h
        include/metal/util/metal_util.h
        include/metal/util/metal_buffer_util.h
        src/metal/util/metal_buffer_util.cpp
        src/metal/buffers/metal_vertex_buffer.cpp
        include/metal/util/metal_converter.h
        src/metal/util/metal_converter.cpp
        include/metal/buffers/metal_index_buffer.h
        src/metal/buffers/metal_index_buffer.cpp
        include/entt_ecs/layer/layer_tag.h
        include/entt_ecs/entity_builder/entity_builder.h)

target_link_libraries(tests
        ${CATCH2_LIBRARY}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARIES}
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
        glm::glm
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
        ${LUA_LIBRARIES}
        ${OPENGL_LIBRARY}

        # APPLE DEVICES
        ${QUARTZ_CORE_LIBRARY}
        ${FOUNDATION_LIBRARY}
        ${METAL_LIBRARY}
)
