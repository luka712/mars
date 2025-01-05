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
endif()

# PACKAGES
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(glm REQUIRED)
find_package(spdlog REQUIRED)
find_package(glad REQUIRED)
find_package(tinyxml2 REQUIRED)

include_directories(
        ${CMAKE_SOURCE_DIR}/include
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${GLM_INCLUDE_DIR}
        ${SPDLOG_INCLUDE_DIR}
        ${GLAD_INCLUDE_DIR}
        ${TINYXML2_INCLUDE_DIR}
)

# SOURCES
file(GLOB COMMON_SOURCES src/*.cpp src/**/*.cpp src/**/**/*.cpp src/**/**/**/*.cpp)

# EXECUTABLE
add_executable(mars main.cpp
        ${COMMON_SOURCES}
        ${GLAD_SRC}
        ${TINYXML2_SRC}
        src/core/log/SpdLogger.cpp
        include/core/log/SpdLogger.h
        src/core/log/Logger.cpp
        include/core/log/BrowserLogger.h
        src/core/log/BrowserLogger.cpp
        include/ecs/transform/RectTransform.h
        src/ecs/sprite/SpriteRendererSystem.cpp
        include/core/loaders/ImageLoader.h
        include/core/data/SDLImageData.h
        include/sdl/texture/SDLTexture2D.h
        include/core/texture/TextureEnums.h
        include/sdl/util/SDLConverter.h
        src/sdl/util/SDLConverter.cpp
        include/core/sprite/Sprite.h
        src/core/sprite/Sprite.cpp
        include/core/sprite/AnimatedSprite.h
        src/core/sprite/AnimatedSprite.cpp
        include/core/content/ContentManager.h
        include/core/input/InputManager.h
        src/core/input/InputManager.cpp
        include/core/input/KeyboardState.h
        src/core/input/KeyboardState.cpp
        include/opengles/renderer/OpenGLESRenderer.h
        src/opengles/renderer/OpenGLESRenderer.cpp
        src/core/fonts/SpriteFontManager.cpp
        include/core/fonts/SpriteFontManager.h
        include/core/fonts/SpriteFont.h
        src/core/fonts/SpriteFontCharacter.cpp
        include/core/fonts/SpriteFontCharacter.h
        include/core/math/Quad.h
        src/core/loaders/SpriteFontLoader.cpp)

# LINK
target_link_libraries(mars
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARY}
        ${GLM_LIBRARY}
        ${SPDLOG_LIBRARY}
        ${GLAD_LIBRARY}
)

# COPY DLLS
if(WIN32)
    file(COPY shared_libs/SDL2.dll DESTINATION ${CMAKE_BINARY_DIR})
    file(COPY shared_libs/SDL2_image.dll DESTINATION ${CMAKE_BINARY_DIR})
endif()

# COPY ASSETS/CONTENT
file(COPY content DESTINATION ${CMAKE_BINARY_DIR})

# COPY VENDOR
file(COPY vendor DESTINATION ${CMAKE_BINARY_DIR})
