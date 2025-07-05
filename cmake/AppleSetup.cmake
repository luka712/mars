# This cmake files sets APPLE_INCLUDE and APPLE_LIBRARIES
# These are additional include and libraries file required for MacOS, iPadOS or iOS setup.

if(APPLE)
    # We need metal
    SET(APPLE_INCLUDE
            ${CMAKE_BINARY_DIR}/vendor/metal-cpp)

    FIND_LIBRARY(FOUNDATION_LIBRARY Foundation REQUIRED)
    FIND_LIBRARY(QUARTZ_CORE_LIBRARY QuartzCore REQUIRED)
    FIND_LIBRARY(METAL_LIBRARY Metal REQUIRED)

    SET(APPLE_LIBRARIES
            ${QUARTZ_CORE_LIBRARY}
            ${FOUNDATION_LIBRARY}
            ${METAL_LIBRARY}
            libEGL.dylib
            libGLESv2.dylib
            "-framework Metal" "-framework QuartzCore"
    )
endif()