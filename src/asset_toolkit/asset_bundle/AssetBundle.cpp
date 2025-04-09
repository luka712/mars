#include "asset_toolkit/asset_bundle/AssetBundle.h"

namespace asset_toolkit {


    SpriteSheet* AssetBundle::getSpriteSheet(const std::string& name) {
        for (auto& spriteSheet : spriteSheets) {
            if (spriteSheet.spriteSheetName == name) {
                return &spriteSheet;
            }
        }
        return nullptr;
    }

    Sprite* AssetBundle::getSprite(const std::string& spriteName) {
        for (auto& spriteSheet : spriteSheets) {
            for (auto& sprite : spriteSheet.sprites) {
                if (sprite.spriteName == spriteName) {
                    return &sprite;
                }
            }
        }
        return nullptr;
    }

    void AssetBundle::destroy() {
        spriteSheets.clear();
    }
}
