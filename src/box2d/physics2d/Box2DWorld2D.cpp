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

    std::shared_ptr<ABody2D> Box2DWorld2D::createBody(BodyDefinition2D &bodyDef) {

        b2BodyDef box2DBodyDef{};
        box2DBodyDef.position.Set(bodyDef.position.x, bodyDef.position.y);
        return std::make_shared<Box2DBody>(*this, bodyDef);
    }
}
