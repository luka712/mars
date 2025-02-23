//
// Created by Erkapic Luka on 1.2.2025.
//

#include <stdexcept>
#include "ecs/collision/Collider2D.h"
#include "ecs/entity/Entity.h"

namespace mars {
    Collider2D::Collider2D(Entity *entity)
        : AComponent(entity), debug(false), debugColor(Color::red()) {
    }

    void Collider2D::initialize() {
        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            const std::string msg = "Collider2D component requires RectTransform component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        collisionRectangle = rectTransform->getDrawRectangle();
    }

    void Collider2D::update(const Time &time) {
        // Update the collision rectangle.
        const Rect transformRect = rectTransform->getDrawRectangle();
        collisionRectangle.x = transformRect.x;
        collisionRectangle.y = transformRect.y;
    }
}