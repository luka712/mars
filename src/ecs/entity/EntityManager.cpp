//
// Created by lukaa on 8.12.2024..
//

#include "ecs/ECSManager.h"
#include "ecs/entity/EntityManager.h"
#include "ecs/entity/Entity.h"

namespace  mars {

    EntityManager::EntityManager(ECSManager& ecsManager)
        : ecsManager(ecsManager) {
    }

    std::shared_ptr<Entity> EntityManager::createEntity(std::string entityName) {
        auto entity = std::make_shared<Entity>(ecsManager, entityName);
        entities.push_back(entity);
        return entity;
  }



}