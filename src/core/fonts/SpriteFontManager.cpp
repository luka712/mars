//
// Created by luka on 04/01/25.
//

#include "../../../include/Framework.h"
#include "../../../include/core/fonts/SpriteFontManager.h"


namespace  mars {
    SpriteFontManager::SpriteFontManager(Framework &framework)
        : framework(framework), state(CREATED) {
    }

    std::shared_ptr<SpriteFont> SpriteFontManager::getDefaultFont() {
        return getSnowBSpriteFont(std::string(DEFAULT_FONT_PATH));
    }

    void SpriteFontManager::initialize() {
        state = INITIALIZED;
        // Load default font into cache.
        getSnowBSpriteFont(std::string(DEFAULT_FONT_PATH));
    }

    std::shared_ptr<SpriteFont> SpriteFontManager::getSnowBSpriteFont(const std::string &xmlPath, const std::string &texturePath) {
        const std::string key = xmlPath + "_" + texturePath;
        if (fonts.contains(key) && fonts[key]->getState() != DESTROYED) {
            return fonts[key];
        }

        // Load sprite font.
        std::shared_ptr<SpriteFont> spriteFont = framework
            .getSpriteFontLoader()
            .loadSnowBSpriteFont(xmlPath, texturePath);

        fonts[key] = spriteFont;

        return spriteFont;
    }

    void SpriteFontManager::destroy() {
        for (auto& kvp : fonts) {
            kvp.second->destroy();
        }
        fonts.clear();
        state = DESTROYED;
    }
}
