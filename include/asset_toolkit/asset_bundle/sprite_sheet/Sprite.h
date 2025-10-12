//
// Created by Erkapic Luka on 29.3.2025.
//

#ifndef ASSET_TOOLKIT_SPRITE_H
#define ASSET_TOOLKIT_SPRITE_H

#include <string>
#include "asset_toolkit/common/Rectangle.h"

namespace asset_toolkit {
    //! The Sprite class.
    struct Sprite {
        //! The sprite name.
        std::string spriteName;

        //! The source rectangle.
        Rectangle sourceRectangle;
    };
}

#endif //ASSET_TOOLKIT_SPRITE_H
