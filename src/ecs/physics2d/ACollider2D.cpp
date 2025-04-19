//
// Created by Erkapic Luka on 29.3.2025.
//

#include "ecs/entity/Entity.h"
#include "ecs/physics2d/ACollider2D.h"

namespace mars {

    ACollider2D::ACollider2D(Entity *entity)
        : AComponent(entity) {
    }

    float ACollider2D::getDensity() {
        return getShape()->density;
    }

    void ACollider2D::setDensity(const float density) {
        getShape()->density = density;
    }
}
