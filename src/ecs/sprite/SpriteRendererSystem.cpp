//
// Created by Erkapic Luka on 10.12.2024.
//

#include "Framework.h"
#include "ecs/sprite/SpriteRendererSystem.h"
#include <ecs/entity/Entity.h>

namespace mars {
    SpriteRendererSystem::SpriteRendererSystem(Framework &framework)
        : framework(framework) {
    }

    void SpriteRendererSystem::add(SpriteRenderer *spriteRenderer) {
        spriteRendererComponents.emplace_back(spriteRenderer);
    }

    void SpriteRendererSystem::remove(const SpriteRenderer *sprite) {
        for (int i = 0; i < spriteRendererComponents.size(); i++) {
            if (spriteRendererComponents[i] == sprite) {
                spriteRendererComponents.erase(spriteRendererComponents.begin() + i);
                break;
            }
        }
    }

    void SpriteRendererSystem::moveToLayerMap(SpriteRenderer *spriteRenderer) {
        const Entity &entity = spriteRenderer->getEntity();
        const Layer &layer = entity.getLayer();

        // If it's not safe to map, we need to add it.
        if (const uint32_t layerOrder = layer.getOrder(); !layerOrderSpritesMap.contains(layerOrder)) {
            layerOrderSpritesMap[layerOrder] = {spriteRenderer};
            layerOrderSpriteCountMap[layerOrder] = 1;
        } else {
            uint32_t currentIndex = layerOrderSpriteCountMap[layerOrder];
            layerOrderSpritesMap[layerOrder][currentIndex] = spriteRenderer;
            layerOrderSpriteCountMap[layerOrder] = currentIndex + 1;
        }
    }

    void SpriteRendererSystem::frameStart() {
        // Reset the layer count map.
        for (auto &kvp: layerOrderSpriteCountMap) {
            kvp.second = 0;
        }

        // Update the sprite renderers.
        for (SpriteRenderer *spriteRenderer: spriteRendererComponents) {
            moveToLayerMap(spriteRenderer);
        }
    }


    void SpriteRendererSystem::update(const Time &time, const uint32_t currentLayerOrder) {
        if (!layerOrderSpritesMap.contains(currentLayerOrder)) {
            return;
        }
        // Update the sprite renderers.
        const uint32_t count = layerOrderSpriteCountMap[currentLayerOrder];
        const std::vector<SpriteRenderer*>& components = layerOrderSpritesMap[currentLayerOrder];
        for (uint32_t i = 0; i < count; i++) {
            components[i]->update(time);
        }
    }

    void SpriteRendererSystem::render(const uint32_t currentLayerOrder, Camera2D& camera) {

        // Check if we have layer to render. If not just return.
        if (!layerOrderSpritesMap.contains(currentLayerOrder)) {
            return;
        }

        // Get camera.
        const Rect cameraRect = camera.getRectTransform()->getDrawRectangle();
        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        // Get count of components and components.
        const uint32_t count = layerOrderSpriteCountMap[currentLayerOrder];
        const std::vector<SpriteRenderer*>& components = layerOrderSpritesMap[currentLayerOrder];

        for (uint32_t i = 0; i < count; i++) {

            const SpriteRenderer *spriteRenderer = components[i];
            const RectTransform *rectTransform = spriteRenderer->getRectTransform();
            Rect drawRect = rectTransform->getDrawRectangle();

            if (spriteRenderer->isFixed == false) {
                drawRect.x -= cameraRect.x;
                drawRect.y -= cameraRect.y;
            }

            // If there is a sprite.
            if (const GameSprite *sprite = spriteRenderer->getSprite(); sprite != nullptr) {

                const Rect& sourceRect = sprite->getSourceRect();
                spriteBatch.draw(&sprite->getTexture(),
                                 drawRect,
                                 sourceRect,
                                 spriteRenderer->color);
            } else {
                spriteBatch.draw(drawRect, spriteRenderer->color);
            }
        }

    }
}
