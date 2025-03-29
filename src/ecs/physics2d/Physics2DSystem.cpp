//
// Created by lukaa on 27.3.2025..
//

#include "Framework.h"
#include "ecs/physics2d/Physics2DSystem.h"
#include "box2d/physics2d/Box2DWorld2D.h"

namespace mars {
    Physics2DSystem::Physics2DSystem(Framework &framework)
        : framework(framework) {
        WorldDefinition2D worldDef{};
        // The default gravity is 9.8 m/s^2.
        worldDef.gravity = glm::vec2(0, -9.8f);

        world = std::make_unique<Box2DWorld2D>(worldDef);
    }

    void Physics2DSystem::add(RigidBody2D *body) {
        bodies.emplace_back(body);
        body->createBodyOnSelf(*this);
    }

    void Physics2DSystem::remove(const RigidBody2D *body) {
        for (int i = 0; i < bodies.size(); i++) {
            if (bodies[i].get() == body) {
                bodies.erase(bodies.begin() + i);
                break;
            }
        }
    }

    void Physics2DSystem::add(ACollider2D *collider) {
        colliders.emplace_back(collider);
    }

    void Physics2DSystem::remove(const ACollider2D *collider) {
        for (int i = 0; i < colliders.size(); i++) {
            if (colliders[i].get() == collider) {
                colliders.erase(colliders.begin() + i);
                break;
            }
        }
    }

    void Physics2DSystem::update(const Time &time) {
        for (const auto &body: bodies) {
            body->update(time);
        }
    }
}
