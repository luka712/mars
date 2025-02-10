SET(GLAD_INCLUDE_DIR ${CMAKE_BINARY_DIR}/vendor/glad/include)
SET(GLAD_SRC ${CMAKE_BINARY_DIR}/vendor/glad/src/glad.c)

if(WIN32)
    SET(GLAD_LIBRARY opengl32)
else ()
    SET(GLAD_LIBRARY)
endif ()