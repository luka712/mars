//
// Created by lukaa on 1.1.2025..
//

#include "ecs/script/ScriptSystem.h"

namespace mars {
    ScriptSystem::ScriptSystem(Framework &framework)
           : framework(framework) {
    }

    void ScriptSystem::add(AScript *script) {
        scripts.emplace_back(script);
    }

    void ScriptSystem::remove(AScript *script) {
        for (int i = 0; i < scripts.size(); i++) {
            if (scripts[i] == script) {
                scripts.erase(scripts.begin() + i);
                break;
            }
        }
    }

    void ScriptSystem::update(const Time &time) {
        for (AScript* script: scripts) {
            script->update(time);
        }
    }

    void ScriptSystem::render() {
        for (AScript* script: scripts) {
            script->render();
        }
    }
}