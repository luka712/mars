//
// Created by lukaa on 1.1.2025..
//

#ifndef SCRIPTSYSTEM_H
#define SCRIPTSYSTEM_H

#include <vector>
#include "ecs/script/AScript.h"

namespace mars {

    class Framework;

    class ScriptSystem {
    public:
        //! Construct a new ScriptSystem object.
        //! @param framework The framework.
        explicit ScriptSystem(Framework& framework);

        //! Add a script component to the system.
        //! @param script The script component.
        void add(AScript* script);

        //! Update the script components.
        //! @param time The game time.
        void update(const Time &time);

        //! Remove a script component from the system.
        //! @param script The script component.
        void remove(const AScript *script);

        //! Render the sprite components.
        void render();
    private:
        Framework& framework;
        std::vector<AScript*> scripts;
    };

}





#endif //SCRIPTSYSTEM_H
