
# See https://github.com/leethomason/tinyxml2/blob/master/readme.md
# With tiny xml we just include
# - the tinyxml2.h header file
# - the tinyxml2.cpp source file
# and compile with it.


FetchContent_Declare(
        tinyxml2
        GIT_REPOSITORY	https://github.com/leethomason/tinyxml2.git
        GIT_TAG 	10.0.0
)

FetchContent_MakeAvailable(tinyxml2)

SET(TINYXML2_INCLUDE_DIR ${tinyxml2_SOURCE_DIR})
SET(TINYXML2_SRC ${tinyxml2_SOURCE_DIR}/tinyxml2.cpp)
