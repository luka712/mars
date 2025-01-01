//
// Created by lukaa on 1.1.2025..
//

#ifndef KEYBOARDSTATE_H
#define KEYBOARDSTATE_H

#include <map>
#include "core/input/Key.h"

namespace mars {
    //! The keyboard state.
    //! Shows which keys are pressed or released in the current frame.
    class KeyboardState {
    public:
        //! Construct a new KeyboardState object.
        //! @param downKeys The keys that are pressed.
        //! @param releasedKeys The keys that are released.
        KeyboardState(const std::map<Key, bool>& downKeys, const std::map<Key, bool>& releasedKeys);

        //! Check if the key is down.
        //! @param key The key.
        //! @return True if the key is down, false otherwise.
        [[nodiscard]] bool isKeyDown(Key key) const;

        //! Check if the key is up.
        //! @param key The key.
        //! @return True if the key is up, false otherwise.
        [[nodiscard]] bool isKeyUp(Key key) const;

        //! Check if the key is released.
        //! @param key The key.
        //! @return True if the key is released, false otherwise.
        [[nodiscard]] bool isKeyReleased(Key key) const;

    private:
        std::map<Key, bool> downKeys;
        std::map<Key, bool> releasedKeys;
    };
}

#endif //KEYBOARDSTATE_H
