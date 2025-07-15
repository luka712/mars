//
// Created by Erkapic Luka on 1.1.2025.
//

#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include <map>
#include <SDL3/SDL.h>
#include "core/input/KeyboardState.h"

namespace mars {
    class Framework;

    class InputManager {
    public:
        //! Construct a new InputManager object.
        //! @param framework The framework.
        explicit InputManager(Framework &framework);

        //! Get the keyboard state.
        KeyboardState getKeyboardState();

        //! Initialize the input manager.
        void initialize();

        //! Update the input manager.
        void update();

        //! Process the SDL_event event.
        //! @param event The event.
        void processEvent(const SDL_Event &event);

        //! To be called after all the updates are done.
        //! Ideally at the end of the update frame.
        void afterUpdate();

    private:
        Framework &framework;
        std::map<SDL_Keycode, Key> mapSDLKeyToMarsKey;

        //! Keys that are pressed down.
        std::map<Key, bool> downKeys;

        //! Keys that are released in current frame.
        std::map<Key, bool> releasedKeys;

        //! Tries to map key to Mars key. Returns null if the key is not found.
        //! @param keyCode The key code from SDL.
        //! @param isDown Is the key down. If false it can be considered as up.
        Key mapKey(SDL_Keycode keyCode, bool isDown);

    };
}

#endif //INPUTMANAGER_H
