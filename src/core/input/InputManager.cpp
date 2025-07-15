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
            { SDLK_A, Key::A },
            { SDLK_D, Key::D },
            { SDLK_S, Key::S },
            { SDLK_W, Key::W },
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
        if (event.type == SDL_EVENT_KEY_DOWN) {
            SDL_Keycode sdlKeyCode = event.key.key;
            mapKey(sdlKeyCode, true);
        } else if (event.type == SDL_EVENT_KEY_UP) {
            SDL_Keycode sdlKeyCode = event.key.key;
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
