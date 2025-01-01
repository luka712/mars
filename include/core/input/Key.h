//
// Created by lukaa on 1.1.2025..
//

#ifndef KEY_H
#define KEY_H

namespace mars
{
    //! The keys on the keyboard.
    enum class Key {
        // No result.
        None,

        A,
        D,
        S,
        W,
        L,

        // Arrow keys.
        LeftArrow,
        RightArrow,
        UpArrow,
        DownArrow,

        // Special keys.
        Space,
        ControlLeft,
        ControlRight,
        ShiftLeft,
        ShiftRight,
        NumpadSubtract,
        NumpadAdd,

        Minus,
        Equal,
        Delete,
    };
}

#endif //KEY_H
