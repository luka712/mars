//
// Created by Erkapic Luka on 9.4.2025.
//

#ifndef ASSET_BUNDLE_H
#define ASSET_BUNDLE_H

#include "asset_toolkit/asset_bundle/sprite_sheet/SpriteSheet.h"

namespace asset_toolkit {
    //! The AssetBundle
    struct AssetBundle {

        //! All the sprite sheets in the asset bundle.
        std::vector<SpriteSheet> spriteSheets;

        //! Get a sprite sheet by name.
        //! @param name The name of the sprite sheet.
        //! @return The sprite sheet if found, nullptr otherwise.
        SpriteSheet* getSpriteSheet(const std::string& name);

        //! Gets the first sprite under given name. Checks all sprite sheets.
        //! <p>Note: It is possible that name is not unique withing multiple sprite sheets.</p>
        //! @param spriteName The name of the sprite.
        //! @return Sprite if found, nullptr otherwise.
        Sprite* getSprite(const std::string& spriteName);

        //! Destroy the asset bundle.
        void destroy();

    };
}

#endif //ASSET_BUNDLE_H
