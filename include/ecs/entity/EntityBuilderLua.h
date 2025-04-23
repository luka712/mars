//
// Created by Erkapic Luka on 22.3.2025.
//

#ifndef ENTITY_BUILDER_LUA_H
#define ENTITY_BUILDER_LUA_H

#include <sol/sol.hpp>
#include "ecs/entity/EntityManager.h"
#include "ecs/transform/RectTransform.h"
#include "ecs/physics2d/RigidBody2D.h"
#include "ecs/sprite/AnimatedSpriteRenderer.h"
#include "ecs/physics2d/BoxCollider2D.h"

namespace mars {

    class Framework;
    class ECSManager;

    //! Builds entities from Lua scripts.
    class EntityBuilderLua {
    public:
        //! Constructs an EntityBuilderLua.
        //! @param framework The framework.
        //! @param ecsManager The enttity component system manager.
        EntityBuilderLua(Framework& framework, ECSManager &ecsManager);

        //! Builds an entity from a Lua script.
        //! @param entityTable The table containing the entity data.
        //! @param layers The layers to add the entity to.
        //! @return The built entity.
        std::shared_ptr<Entity> buildEntity(sol::table &entityTable,
                                            const std::vector<std::shared_ptr<Layer> > &layers) const;

        //! Builds a transform component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param rectTransformTable The table containing the entity data.
        //! @return The built transform component.
        RectTransform* buildRectTransform(Entity& entity, sol::table &rectTransformTable) const;

        //! Builds a sprite renderer component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param spriteRendererTable The table containing the entity data.
        //! @return The built sprite renderer component.
        SpriteRenderer* buildSpriteRenderer(Entity& entity, sol::table &spriteRendererTable) const;

        //! Builds an animated sprite renderer component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param animatedSpriteRendererTable The table containing the entity data.
        //! @return The built animated sprite renderer component.
        AnimatedSpriteRenderer* buildAnimatedSpriteRenderer(Entity& entity, sol::table &animatedSpriteRendererTable) const;

        //! Builds a box collider 2D component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param boxColliderTable The table containing the entity data.
        //! @return The built box collider 2D component.
        BoxCollider2D* buildBoxCollider2D(Entity& entity, const sol::table &boxColliderTable) const;

        //! Builds a rigid body 2D component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param rigidBodyTable The table containing the entity data.
        //! @return The built rigid body 2D component.
        RigidBody2D* buildRigidBody2D(Entity& entity, const sol::table &rigidBodyTable) const;

    private:
        Framework& framework;
        ECSManager &ecsManager;

        //! Helper function to get a value from a Lua table or return a default value.
        //! @tparam T The type of the value.
        //! @param table The Lua table.
        //! @param fieldName The name of the field to get.
        //! @return The value from the table or a default value.
        template<typename T>
       static T getValueOrDefault(const sol::table &table, const std::string &fieldName) {
            if (table[fieldName].valid()) {
                return table[fieldName];
            }
            return T{};
        }
    };
}

#endif //ENTITY_BUILDER_LUA_H
