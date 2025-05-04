//
// Created by Erkapic Luka on 4.5.2025.
//

#include "Framework.h"
#include "entt_ecs/entt_ecs.h"

namespace mars_entt_ecs {
    EnttEcs::EnttEcs(mars::Framework &framework)
        : framework(framework) {
        rectTransformSystem = std::make_unique<RectTransformSystem>(*this);
        spriteRendererSystem = std::make_unique<SpriteRendererSystem>(*this);
    }

    void EnttEcs::initialize() {
    }

    void EnttEcs::render() {

        auto spriteBatch = framework.getSpriteBatch();

        spriteBatch.begin();
        spriteRendererSystem->render();
        spriteBatch.end();
    }
}
