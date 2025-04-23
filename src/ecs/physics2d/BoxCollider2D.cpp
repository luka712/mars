//
// Created by Erkapic Luka on 29.3.2025.
//

#include "ecs/physics2d/BoxCollider2D.h"
#include "ecs/entity/Entity.h"

namespace mars {

    BoxCollider2D::BoxCollider2D(Entity *entity)
        : ACollider2D(entity), rectTransform(nullptr) {
    }

    AShape2D * BoxCollider2D::getShape() {
        return shape.get();
    }

    void BoxCollider2D::initialize() {

        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>( "BoxCollider2D component requires RectTransform component.");

        // Create shape
        shape = std::make_shared<Box2DPolygonShape>();
        const Rect rect = rectTransform->getDrawRectangle();
        // By default, set to dimensions of the transform rect.
        shape->setAsBox(static_cast<float>(rect.width) / 2.0f, static_cast<float>(rect.height) / 2.0f);
    }

}
