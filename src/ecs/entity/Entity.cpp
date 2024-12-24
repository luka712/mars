//
// Created by lukaa on 8.12.2024..
//

#include <utility>

#include "ecs/entity/Entity.h"
#include "ecs/ECSManager.h"

namespace  mars {

    Entity::Entity(ECSManager& ecsManager, std::string name)
        :  ecsManager(ecsManager), name(std::move(name))
    {
    }

    std::string Entity::getName() const {
        return name;
    }

    void Entity::setName(const std::string &name) {
        this->name = name;
    }

    std::string Entity::toString() const {
        std::string result;
        result += "Entity: " + name + "\n";
        result += "Components: \n";
        for (std::pair<std::string, std::shared_ptr<AComponent>> keyPair : componentsMap) {
            result += "\t" + keyPair.second->toString() + "\n";
        }
        return result;
    }
}
