//
// Created by Erkapic Luka on 4.5.2025.
//

#include "entt_ecs/sprite/sprite_renderer_system.h"

#include <Framework.h>

#include "entt_ecs/transform/rect_transform.h"
#include "entt_ecs/sprite/sprite_renderer.h"
#include "entt_ecs/entt_ecs.h"

namespace mars_entt_ecs {
    SpriteRendererSystem::SpriteRendererSystem(EnttEcs &ecs)
        : ecs(ecs) {
    }

    void SpriteRendererSystem::render() {

        auto spriteBatch = ecs.getFramework().getSpriteBatch();
        const auto view = ecs.getRegistry().view<SpriteRenderer, RectTransform>();

        view.each([&](auto entity, const SpriteRenderer& renderer, const RectTransform& rectTransform) {

            auto drawRect = mars::Rect();
            drawRect.x = rectTransform.position.x;
            drawRect.y = rectTransform.position.y;
            drawRect.width = rectTransform.size.x;
            drawRect.height = rectTransform.size.y;

            auto& sprite = renderer.sprite;

            if (sprite.get() != nullptr) {
                const mars::Rect sourceRect = sprite->getSourceRect();
                spriteBatch.draw(&sprite->getTexture(), drawRect, sourceRect, renderer.color);
            } else {
                spriteBatch.draw(drawRect, renderer.color);
            }
        });
    }
}
