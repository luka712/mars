FetchContent_Declare(
        glm
        GIT_REPOSITORY	https://github.com/g-truc/glm.git
        GIT_TAG 	1.0.1
)

FetchContent_MakeAvailable(glm)

SET(GLM_LIBRARY glm::glm)
SET(GLM_INCLUDE_DIR ${glm_SOURCE_DIR})