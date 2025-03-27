//
// Created by Erkapic Luka on 27.3.2025.
//

#include "ecs/physics2d/RigidBody2D.h"
#include "ecs/entity/Entity.h"
#include "box2d/physics2d/body/Box2DBody.h"

namespace mars {
    RigidBody2D::RigidBody2D(Entity *entity): AComponent(entity), rectTransform(nullptr) {
    }

    void RigidBody2D::initialize() {
        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            const std::string msg = "SpriteRenderer component requires RectTransform component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }

    void RigidBody2D::createBodyOnSelf(const Physics2DSystem &system) {
        // Check if body is already created.
        if (body != nullptr) {
            const std::string msg =
                    "'Body2D::body' is already created. 'Body2D::createBodyOnSelf' cannot be called twice.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        BodyDefinition2D groundBodyDef{};
        groundBodyDef.position = rectTransform->getPosition();
        body = system.getWorld().createBody(groundBodyDef);
    }

    void RigidBody2D::update(const Time &time) {
        const glm::vec2 position = body->getPosition();
        rectTransform->setPosition(position);
    }
}
