include(FetchContent)

# For MacOS simple find_package is used.
if(APPLE)
    find_package(lua)
else()
    # NOTE: We only need it for EMSCRIPTEN, otherwise use Lua from system.
    FetchContent_Declare(
            lua
            GIT_REPOSITORY	https://github.com/lua/lua.git
            GIT_TAG 	v5-2
    )

    FetchContent_MakeAvailable(lua)

    # We need to copy dll.
    if(WIN32)
    SET(LUA_LIBRARY ${LUA_PATH}/lua54.dll)
    endif()

    SET(LUA_INCLUDE_DIR ${LUA_PATH}/include)
endif ()
