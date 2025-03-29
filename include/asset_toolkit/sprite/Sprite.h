//
// Created by Erkapic Luka on 29.3.2025.
//

#ifndef SPRITE_H
#define SPRITE_H
#include <string>

#include "asset_toolkit/sprite/Rectangle.h"

namespace asset_toolkit {
    //! The Sprite class.
    struct Sprite {
        //! The sprite name.
        std::string spriteName;

        //! The source rectangle.
        Rectangle sourceRectangle;
    };
}

#endif //SPRITE_H
