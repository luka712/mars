if(WIN32)
    SET(OPENGL opengl32)
else ()
    SET(OPENGL)
endif ()

set(PACKAGES_LIBRARIES
        ${PACKAGES_LIBRARIES}
        ${OPENGL}
)

set(PACKAGES_INCLUDE
        ${PACKAGES_INCLUDE}
        ${CMAKE_BINARY_DIR}/vendor/glad/include
        ${CMAKE_BINARY_DIR}/vendor/catch2
        ${CMAKE_BINARY_DIR}/vendor
)

set(PACKAGES_SOURCES
        ${PACKAGES_SOURCES}
        ${CMAKE_BINARY_DIR}/vendor/glad/src/glad.c
)