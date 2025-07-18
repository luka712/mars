# This cmake files sets APPLE_INCLUDE and APPLE_LIBRARIES
# These are additional include and libraries file required for MacOS, iPadOS or iOS setup.

if(APPLE)
    # We need metal
    SET(APPLE_INCLUDE
            ${CMAKE_BINARY_DIR}/vendor/metal-cpp)

    # Find required Apple frameworks
    FIND_LIBRARY(FOUNDATION_LIBRARY Foundation REQUIRED)
    FIND_LIBRARY(QUARTZ_CORE_LIBRARY QuartzCore REQUIRED)
    FIND_LIBRARY(METAL_LIBRARY Metal REQUIRED)
    IF(NOT FOUNDATION_LIBRARY OR NOT QUARTZ_CORE_LIBRARY OR NOT METAL_LIBRARY)
        MESSAGE(FATAL_ERROR "Foundation, QuartzCore or Metal frameworks not found. Please install Xcode and the command line tools.")
    ENDIF()

    # Find Cocoa framework
    FIND_LIBRARY(COCOA_FRAMEWORK Cocoa REQUIRED)
    IF(NOT COCOA_FRAMEWORK)
        MESSAGE(FATAL_ERROR "Cocoa framework not found. Please install Xcode and the command line tools.")
    ENDIF()

    # Find EGL
    SET(EGL_LIBRARY
            ${CMAKE_SOURCE_DIR}/vendor/angle/libEGL.dylib
            CACHE FILEPATH "Path to libEGL.dylib"
    )
    IF(NOT EGL_LIBRARY)
        MESSAGE(FATAL_ERROR "libEGL.dylib not found. Please ensure ANGLE is built and the path is correct.")
    ENDIF()

    # Find GLESv2
    SET(GLESV2_LIBRARY
            ${CMAKE_SOURCE_DIR}/vendor/angle/libGLESv2.dylib
            CACHE FILEPATH "Path to libGLESv2.dylib"
    )
    IF(NOT GLESV2_LIBRARY)
        MESSAGE(FATAL_ERROR "libGLESv2.dylib not found. Please ensure ANGLE is built and the path is correct.")
    ENDIF()

    SET(APPLE_LIBRARIES
            ${QUARTZ_CORE_LIBRARY}
            ${FOUNDATION_LIBRARY}
            ${METAL_LIBRARY}
            ${COCOA_FRAMEWORK}
            ${EGL_LIBRARY}
            ${GLESV2_LIBRARY}
            # "-framework Metal" "-framework QuartzCore" "-framework Foundation" "-framework Cocoa"
    )

    # COPY libEGL.dylib and libGLESv2.dylib to the build directory
    add_custom_command(
            OUTPUT ${CMAKE_BINARY_DIR}/libEGL.dylib
                   ${CMAKE_BINARY_DIR}/libGLESv2.dylib
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_SOURCE_DIR}/vendor/angle/libEGL.dylib
                    ${CMAKE_BINARY_DIR}/libEGL.dylib
            COMMAND ${CMAKE_COMMAND} -E copy_if_different
                    ${CMAKE_SOURCE_DIR}/vendor/angle/libGLESv2.dylib
                    ${CMAKE_BINARY_DIR}/libGLESv2.dylib
            COMMENT "Copying ANGLE libraries to build directory"
    )

endif()