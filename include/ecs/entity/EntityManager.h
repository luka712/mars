//
// Created by lukaa on 8.12.2024.
//

#ifndef ENTITYMANAGER_H
#define ENTITYMANAGER_H

#include <memory>
#include <vector>

#include "ecs/layering/Layer.h"

namespace mars {

    class Framework;
    class Entity;
    class ECSManager;

    //! The EntityManager class.
    //! Manages all the entities in the ECS part of the engine.
    class EntityManager {

    public:
        //! Construct a new EntityManager object.
        //! @param ecsManager The systems' manager.
        explicit EntityManager(ECSManager& ecsManager);

        //! Gets the framework.
        //! @return The reference to the @see Framework.
        [[nodiscard]] Framework& getFramework() const;

        //! Create a new entity with a given name.
        //! @param entityName The name of the entity.
        //! @return The reference to the @see Entity.
        std::shared_ptr<Entity> createEntity(const std::string& entityName);

        //! Get all the entities.
        //! @return The vector of entities.
        [[nodiscard]] const std::vector<std::shared_ptr<Entity>>& getEntities() { return entities; }

    private:
        Framework& framework;
        ECSManager& ecsManager;
        std::vector<std::shared_ptr<Entity>> entities;
    };
}

#endif //ENTITYMANAGER_H
