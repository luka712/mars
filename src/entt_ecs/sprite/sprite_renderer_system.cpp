//
// Created by Erkapic Luka on 4.5.2025.
//

#include "entt_ecs/sprite/sprite_renderer_system.h"
#include "entt_ecs/entt_ecs.h"

namespace mars_entt_ecs {
    SpriteRendererSystem::SpriteRendererSystem(EnttEcs &ecs)
        : ecs(ecs), framework(ecs.getFramework()), registry(ecs.getRegistry()), spriteBatch(nullptr) {
    }

    void SpriteRendererSystem::render(const RectTransform &rect_transform, const SpriteRenderer &sprite_renderer) const {

        auto drawRect = mars::Rect();
        drawRect.x = rect_transform.position.x;
        drawRect.y = rect_transform.position.y;
        drawRect.width = rect_transform.size.x;
        drawRect.height = rect_transform.size.y;

        auto& sprite = sprite_renderer.sprite;

        if (sprite.get() != nullptr) {
            const mars::Rect sourceRect = sprite->getSourceRect();
            spriteBatch->draw(&sprite->getTexture(), drawRect, sourceRect, sprite_renderer.color);
        } else {
            spriteBatch->draw(drawRect, sprite_renderer.color);
        }
    }
}
