//
// Created by Erkapic Luka on 9.4.2025.
//

#ifndef SPRITE_SHEET_H
#define SPRITE_SHEET_H

#include <string>
#include <vector>
#include "asset_toolkit/asset_bundle/sprite_sheet/Sprite.h"

namespace asset_toolkit {

    //! The Sprite Sheet, which contains a collection of sprites.
    struct SpriteSheet {
        //! The sprite sheet name.
        std::string spriteSheetName;

        //! The name of the image file containing the sprite sheet.
        std::string spriteSheetImage;

        //! The sprites in the sprite sheet.
        std::vector<Sprite> sprites;
    };
}

#endif //SPRITE_SHEET_H
