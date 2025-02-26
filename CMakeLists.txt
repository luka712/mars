cmake_minimum_required(VERSION 3.30)
project(mars)

# C++ STANDARD
set(CMAKE_CXX_STANDARD 20)

# INCLUDE
include(FetchContent)

# MODULES - we set modules in cmake_modules folder.
# Pattern is `Find<module>.cmake`
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules")

# VARIABLES
if(WIN32)
    # NOTE: SET DIFFERENT PATH FOR YOUR SDL2 INSTALLATION
    set(SDL2_PATH "D:/_Windows/Libs/SDL2-devel-2.30.9-mingw/SDL2/x86_64-w64-mingw32")
    set(SDL2_IMAGE_PATH "D:/_Windows/Libs/SDL2_image-devel-2.8.3-mingw/SDL2_image-2.8.3/x86_64-w64-mingw32")

    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static -static-libgcc -static-libstdc++ -pthread")
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
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC}
        include/core/camera/core/OrthographicCamera.h)

# LINK
target_link_libraries(mars
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
)

# COPY DLLS
if(WIN32)
    file(COPY shared_libs/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY shared_libs/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
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
target_link_libraries(tests
        ${CATCH2_LIBRARY}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
)

# GAMES
add_executable(chopper-shooter chopper-shooter.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC}
        include/core/geometry/Geometry.h
        src/core/geometry/Geometry.cpp
        include/core/mesh/MeshFactory.h
        include/core/geometry/GeometryBuilder.h
        src/core/geometry/GeometryBuilder.cpp
        include/core/physics2d/AWorld2D.h
        include/core/physics2d/body/ABody2D.h
        include/core/physics2d/body/BodyDefinition2D.h
        include/box2d/physics2d/Box2DWorld2D.h
        src/core/physics2d/AWorld2D.cpp
        src/box2d/physics2d/Box2DWorld2D.cpp
        include/core/physics2d/WorldDefinition2D.h
        src/opengles/util/OpenGLESProgramUtil.cpp
        src/core/sprite/SpriteBatch.cpp)
target_link_libraries(chopper-shooter
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
        ${BOX2D_LIBRARY}
)
