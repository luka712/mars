FetchContent_Declare(
        Entt
        GIT_REPOSITORY	https://github.com/skypjack/entt.git
        GIT_TAG 	v3.15.0
)

FetchContent_MakeAvailable(Entt)

SET(ENTT_INCLUDE_DIR ${EnTT_SOURCE_DIR}/src)