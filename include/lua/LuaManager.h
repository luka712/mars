//
// Created by Erkapic Luka on 9.3.2025.
//

#ifndef LUA_MANAGER_H
#define LUA_MANAGER_H

#include <sol/sol.hpp>

namespace mars {

    class Framework;

    //! The Lua manager. This class is responsible for managing the Lua state and executing Lua scripts.
    class LuaManager {
    public:
        //! Construct new LuaManager.
        //! @param framework The framework.
        LuaManager(Framework& framework);

        //! Get the Lua state.
        //! @return The Lua state.
        sol::state& getLuaState() { return luaState; }

    private:
        Framework& framework;
        sol::state luaState{};
    };
}


#endif //LUA_MANAGER_H
