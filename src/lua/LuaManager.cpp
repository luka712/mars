//
// Created by Erkapic Luka on 9.3.2025.
//

#include "Framework.h"
#include "lua/LuaManager.h"

namespace mars {
    LuaManager::LuaManager(Framework& framework): framework(framework) {
        luaState.open_libraries(sol::lib::base, sol::lib::os, sol::lib::math);
    }
}
