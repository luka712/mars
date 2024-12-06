FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.12.0  # Replace with a valid tag
)
FetchContent_MakeAvailable(spdlog)


SET(SPDLOG_LIBRARY spdlog::spdlog)
SET(SPDLOG_INCLUDE_DIR ${spdlog_SOURCE_DIR})