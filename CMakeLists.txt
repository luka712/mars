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
endif()

# PACKAGES
find_package(SDL2 REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
        ${SPDLOG_INCLUDE_DIR}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp ${COMMON_SOURCES}
        src/core/log/SpdLogger.cpp
        include/core/log/SpdLogger.h
        src/core/log/Logger.cpp
        include/core/log/BrowserLogger.h
        src/core/log/BrowserLogger.cpp)

# LINK
target_link_libraries(mars ${SDL2_LIBRARY} ${GLM_LIBRARY} ${SPDLOG_LIBRARY})

# COPY DLLS
if(WIN32)
    add_custom_command(TARGET mars POST_BUILD
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
           "${SDL2_PATH}/bin/SDL2.dll"
           $<TARGET_FILE_DIR:mars>)
endif()

