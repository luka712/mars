//
// Created by lukaa on 10.12.2024..
//

#include "Framework.h"
#include "ecs/sprite/SpriteRendererSystem.h"

namespace mars {
    SpriteRendererSystem::SpriteRendererSystem(Framework &framework)
        : framework(framework) {
    }

    void SpriteRendererSystem::add(const std::shared_ptr<SpriteRenderer> &spriteRenderer) {
        sprites.emplace_back(spriteRenderer);
    }

    void SpriteRendererSystem::remove(SpriteRenderer *spriteRenderer) {
        for (int i = 0; i < sprites.size(); i++) {
            if (sprites[i].get() == spriteRenderer) {
                sprites.erase(sprites.begin() + i);
                break;
            }
        }
    }

    void SpriteRendererSystem::render() {
        SpriteBatch &spriteBatch = framework.getSpriteBatch();
        spriteBatch.begin();
        for (const std::shared_ptr<SpriteRenderer> &spriteRenderer: sprites) {
            Rect drawRect = spriteRenderer->getRectTransform()->getDrawRectangle();
            spriteBatch.draw(drawRect, spriteRenderer->color);
        }
        spriteBatch.end();
    }
}
