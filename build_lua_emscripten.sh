#! /bin/bash

FOLDER=$(pwd)
LUA_SRC="$(pwd)/cmake-build-debug/_deps/lua-src/"

if [ -d "$LUA_SRC" ]; then
  # Move to lua folder
  cd "$LUA_SRC"
  # Build lua
  make
  # Move back and exit
  cd "$FOLDER" || exit
else
  echo "Cannot find 'lua' directory under '$LUA_SRC'. Make sure that cmake was run."
fi

