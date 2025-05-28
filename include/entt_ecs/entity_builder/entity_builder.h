//
// Created by lukaa on 27.5.2025.
//

#ifndef ENTITY_BUILDER_H
#define ENTITY_BUILDER_H

#include <entt/entt.hpp>

namespace mars_entt_ecs  {

    class EnttEcs;

    class EntityBuilder {

    public:
        //! The constructor.
        //! @param enttEcs Reference to the EnttEcs instance.
        explicit EntityBuilder(EnttEcs &enttEcs);

        //! Create entity which is ready for 2d rendering.
        //! By default, adds 'RectTransform', 'SpriteRenderer' components.
        entt::entity create2DEntity();

        template <typename T>
        T& addComponent(const entt::entity entity) {
            registry.emplace<T>(entity);
            return registry.get<T>(entity);
        }

      private:
        entt::registry& registry;
      };
};

#endif //ENTITY_BUILDER_H
