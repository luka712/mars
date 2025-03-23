//
// Created by Erkapic Luka on 23.2.2025.
//

#include "box2d/physics2d/Box2DWorld2D.h"

#include "box2d/physics2d/body/Box2DBody.h"

namespace mars {
    Box2DWorld2D::Box2DWorld2D(WorldDefinition2D worldDef)
        : AWorld2D(worldDef) {
        world = new b2World(b2Vec2(worldDef.gravity.x, worldDef.gravity.y));
    }

    void Box2DWorld2D::update(const Time &time, const uint32_t velocityIterations, const uint32_t positionIterations) {
        world->Step(
            time.getDeltaTimeMS(),
            static_cast<int32_t>(velocityIterations),
            static_cast<int32_t>(positionIterations));
    }

    std::shared_ptr<ABody2D> Box2DWorld2D::createBody(BodyDefinition2D &bodyDef) {
        b2BodyDef box2DBodyDef{};
        box2DBodyDef.type = convertBodyType(bodyDef.type);
        box2DBodyDef.position.Set(bodyDef.position.x, bodyDef.position.y);
        return std::make_shared<Box2DBody>(*this, bodyDef);
    }

    b2BodyType Box2DWorld2D::convertBodyType(BodyType2D type) {
        switch (type) {
            case BodyType2D::StaticBody:
                return b2_staticBody;
            case BodyType2D::DynamicBody:
                return b2_dynamicBody;
            case BodyType2D::KinematicBody:
                return b2_kinematicBody;

            default:
                const std::string msg = "Unknown body type: " + std::to_string(static_cast<int>(type));
                throw std::invalid_argument(msg);
        }
    }
}
