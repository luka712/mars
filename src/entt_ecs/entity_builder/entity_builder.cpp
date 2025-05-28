//
// Created by Erkapic Luka on 27.5.2025.
//

#include "entt_ecs/entt_ecs.h"
#include "entt_ecs/entity_builder/entity_builder.h"

namespace mars_entt_ecs {

    EntityBuilder::EntityBuilder(EnttEcs &enttEcs)
        : registry(enttEcs.getRegistry()) {
    }

    entt::entity EntityBuilder::create2DEntity() {
        auto entity = registry.create();
        addComponent<mars_entt_ecs::RectTransform>(entity);
        addComponent<mars_entt_ecs::SpriteRenderer>(entity);
        return entity;
    }
}