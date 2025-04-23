//
// Created by Erkapic Luka on 27.3.2025.
//

#include "ecs/physics2d/RigidBody2D.h"
#include "ecs/entity/Entity.h"
#include "box2d/physics2d/body/Box2DBody.h"
#include "ecs/physics2d/BoxCollider2D.h"
#include "ecs/physics2d/Physics2DSystem.h"

namespace mars {
    RigidBody2D::RigidBody2D(Entity *entity): AComponent(entity),
                                              rectTransform(nullptr),
                                              collider(nullptr) {
        bodyType = BodyType2D::StaticBody;
    }

    void RigidBody2D::setBodyType(const BodyType2D type) {
        if (bodyType != type) {

            // If type is changed we must destroy and re-create the body.
            destroyBodyOnSelf();
            bodyType = type;
            createBodyOnSelf(physics2DSystem);
        }
    }

    void RigidBody2D::initialize() {
        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>(
            "SpriteRenderer component requires RectTransform component.");

        // Entity must have any of the collider components.
        collider = tryFindCollider();
        if (collider == nullptr) {
            const std::string msg = "RigidBody2D component requires Collider2D component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }

    void RigidBody2D::createBodyOnSelf(Physics2DSystem *system) {

        if (system == nullptr) {
            const std::string msg = "'RigidBody2D::createBodyOnSelf' cannot be called with nullptr 'system' argument.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        physics2DSystem = system;

        // Check if body is already created.
        if (body != nullptr) {
            const std::string msg = "'Body2D::body' is already created. 'Body2D::createBodyOnSelf' cannot be called twice.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        glm::vec2 pos = rectTransform->getPosition();
        const glm::vec2 size = rectTransform->getSize();
        pos += size / 2.0f;

        BodyDefinition2D bodyDef{};
        bodyDef.type = bodyType;
        bodyDef.position = pos;
        body = system->getWorld().createBody(bodyDef);

        // We need to get underlying shape.
        AShape2D* shape = collider->getShape();
        // Fixture is created from shape and collider density.
        body->createFixture(shape, collider->getDensity());
    }

    void RigidBody2D::update(const Time &time) {
        const glm::vec2 position = body->getPosition() - rectTransform->getSize() / 2.0f;
        rectTransform->setPosition(position);
    }

    ACollider2D *RigidBody2D::tryFindCollider() const {
        // Try all implementations of colliders.

        // BoxCollider2D
        if (auto *collider = entity->getComponentOrNull<BoxCollider2D>(); collider != nullptr) {
            return collider;
        }

        // TODO: other types of colliders.

        return nullptr;
    }

    void RigidBody2D::destroyBodyOnSelf() {
       physics2DSystem->getWorld().destroyBody(body);
        body = nullptr;

    }
}
