//
// Created by lukaa on 1.1.2025..
//

#include "Framework.h"
#include "core/input/InputManager.h"

namespace mars
    {
    InputManager::InputManager(Framework &framework)
        : framework(framework) {

        mapSDLKeyToMarsKey = {
            { SDLK_a, Key::A },
            { SDLK_d, Key::D },
            { SDLK_s, Key::S },
            { SDLK_w, Key::W },
            { SDLK_SPACE, Key::Space },
           // { SDLK_ESCAPE, Key:: },
           // { SDLK_RETURN, Key:: },
            { SDLK_UP, Key::UpArrow },
            { SDLK_DOWN, Key::DownArrow },
            { SDLK_LEFT, Key::LeftArrow },
            { SDLK_RIGHT, Key::RightArrow },
        };
    }

    KeyboardState InputManager::getKeyboardState() {
        return { downKeys, releasedKeys };
    }

    void InputManager::initialize() {
    }

    void InputManager::update() {

    }

    void InputManager::processEvent(const SDL_Event &event) {
        if (event.type == SDL_KEYDOWN) {
            SDL_Keycode sdlKeyCode = event.key.keysym.sym;
            mapKey(sdlKeyCode, true);
        } else if (event.type == SDL_KEYUP) {
            SDL_Keycode sdlKeyCode = event.key.keysym.sym;
            mapKey(sdlKeyCode, false);
        }
    }

    void InputManager::afterUpdate() {

        // Clear released keys.
        for (auto& pair: releasedKeys) {
            releasedKeys[pair.first] = false;
        }
    }

    Key InputManager::mapKey(SDL_Keycode keyCode, bool isDown) {
        if (mapSDLKeyToMarsKey.contains(keyCode)) {
            Key key = mapSDLKeyToMarsKey[keyCode];
            downKeys[key] = isDown;
            return key;
        }
        return Key::Unknown;
    }
}
