//
// Created by lukaa on 1.1.2025.
//

#include "core/input/KeyboardState.h"

namespace mars {
    KeyboardState::KeyboardState(
        const std::map<Key, bool> &downKeys,
        const std::map<Key, bool> &releasedKeys)
        : downKeys(downKeys), releasedKeys(releasedKeys) {
    }

    bool KeyboardState::isKeyDown(const Key key) const {
        return downKeys.contains(key) && downKeys.at(key);
    }

    bool KeyboardState::isKeyUp(const Key key) const {
        return !isKeyDown(key);
    }

    bool KeyboardState::isKeyReleased(const Key key) const {
        return releasedKeys.contains(key) && releasedKeys.at(key);
    }
}
