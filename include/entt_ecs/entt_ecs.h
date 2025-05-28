//
// Created by Erkapic Luka on 4.5.2025.
//

#ifndef ENTT_ECS_H
#define ENTT_ECS_H

#include "Framework.h"
#include <memory>
#include "entt_ecs/entity_builder/entity_builder.h"
#include "entt_ecs/transform/rect_transform_system.h"
#include "entt_ecs/sprite/sprite_renderer_system.h"

namespace mars_entt_ecs {

    class EnttEcs {
    public:
        //! The constructor.
        //! @param framework The framework.
        explicit EnttEcs(mars::Framework &framework);

        //! Gets the framework.
        mars::Framework& getFramework() const {
            return framework;
        }

        //! Gets the entt registry.
        entt::registry &getRegistry() {
            return registry;
        }

        //! Gets the entity builder.
        //! @return Reference to the EntityBuilder instance.
        EntityBuilder& getEntityBuilder() const {
            return *entityBuilder;
        }

        //! Gets the T component from the entity.
        //! @tparam T The component type.
        //! @param entity The entity.
        //! @return Reference to the component.
        template <typename T>
        T& getComponent(const entt::entity& entity) {
            return registry.get<T>(entity);
        }

        //! Initializes the ECS.
        void initialize();

        //! Renders the ECS.
        void render();

    private:
        mars::Framework &framework;
        entt::registry registry;
        std::unique_ptr<EntityBuilder> entityBuilder;
        std::unique_ptr<RectTransformSystem> rectTransformSystem;
        std::unique_ptr<SpriteRendererSystem> spriteRendererSystem;
    };
}

#endif //ENTT_ECS_H
