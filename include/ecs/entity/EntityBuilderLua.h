//
// Created by Erkapic Luka on 22.3.2025.
//

#ifndef ENTITY_BUILDER_LUA_H
#define ENTITY_BUILDER_LUA_H

#include "ecs/entity/EntityManager.h"
#include "ecs/transform/RectTransform.h"
#include "ecs/physics2d/RigidBody2D.h"
#include <sol/sol.hpp>

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

        //! Builds a rigid body 2D component from a Lua script.
        //! @param entity The entity to add the component to.
        //! @param rigidBodyTable The table containing the entity data.
        //! @return The built rigid body 2D component.
        RigidBody2D* buildRigidBody2D(Entity& entity, sol::table &rigidBodyTable) const;

    private:
        Framework& framework;
        ECSManager &ecsManager;
    };
}

#endif //ENTITY_BUILDER_LUA_H
