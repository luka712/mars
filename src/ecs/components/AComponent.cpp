//
// Created by lukaa on 8.12.2024.
//

#include "Framework.h"
#include "ecs/components/AComponent.h"

#include <ecs/entity/Entity.h>

namespace mars {

    AComponent::AComponent(Entity* entity)
        : framework(entity->getFramework()), entity(entity) {
    }

    Entity& AComponent::getEntity() const {
        return *entity;
    }

    void AComponent::initialize() {
        state = INITIALIZED;
    }

    void AComponent::destroy() {
        state = DESTROYED;
    }

    std::string AComponent::toString() {
        return typeid(*this).name();
    }
}
