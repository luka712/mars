//
// Created by lukaa on 10.12.2024..
//

#include "Framework.h"
#include "ecs/sprite/SpriteRendererSystem.h"

namespace mars {
    SpriteRendererSystem::SpriteRendererSystem(Framework &framework)
        : framework(framework) {
    }

    void SpriteRendererSystem::add(SpriteRenderer *spriteRenderer) {
        sprites.emplace_back(spriteRenderer);
    }

    void SpriteRendererSystem::remove(const SpriteRenderer *spriteRenderer) {
        for (int i = 0; i < sprites.size(); i++) {
            if (sprites[i] == spriteRenderer) {
                sprites.erase(sprites.begin() + i);
                break;
            }
        }
    }

    void SpriteRendererSystem::update(const Time &time) {
        for (SpriteRenderer* spriteRenderer: sprites) {
            spriteRenderer->update(time);
        }
    }

    void SpriteRendererSystem::render() {
        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        for (SpriteRenderer* spriteRenderer: sprites) {
            const RectTransform *rectTransform = spriteRenderer->getRectTransform();
            Rect drawRect = rectTransform->getDrawRectangle();
            Sprite *sprite = spriteRenderer->getSprite();
            if (sprite != nullptr) {
                spriteBatch.draw(&sprite->getTexture(), drawRect, sprite->getSourceRect(), spriteRenderer->color);
            } else {
                spriteBatch.draw(drawRect, spriteRenderer->color);
            }
        }
    }
}
