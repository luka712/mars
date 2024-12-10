//
// Created by lukaa on 8.12.2024..
//

#include <utility>

#include "ecs/components/AComponent.h"

namespace mars {

    AComponent::AComponent(std::shared_ptr<Entity> entity)
        : entity(std::move(entity)) {
    }

    Entity& AComponent::getEntity() const {
        return *entity;
    }

}
