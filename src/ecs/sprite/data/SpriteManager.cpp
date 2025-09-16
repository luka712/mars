//
// Created by Erkapic Luka on 29.3.2025.
//

#include <stdexcept>
#include "Framework.h"
#include "ecs/sprite/data/SpriteManager.h"

namespace mars {
    SpriteManager::SpriteManager(Framework &framework)
        :framework(framework)
    {
    }

    std::shared_ptr<GameSprite> SpriteManager::getSprite(const std::string& name) {
        return sprites.find(name)->second;
    }

    void SpriteManager::addSprite(const std::shared_ptr<ATexture2D> &texture, const std::string &spriteName) {

        // We cannot add new one if it already exists.
        if (sprites.contains(spriteName)) {
            const std::string& msg = "SpriteManager::addSprite: Sprite with name " + spriteName + " already exists.";
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        sprites[spriteName] = std::make_shared<GameSprite>(texture);
    }


}
