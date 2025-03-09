include(FetchContent)


if(WIN32)
SET(LUA_LIBRARY ${LUA_PATH}/lua54.dll)
endif()

SET(LUA_INCLUDE_DIR ${LUA_PATH}/include)

