//
// Created by Erkapic Luka on 23.2.2025.
//

#include "Framework.h"
#include "box2d/physics2d/Box2DWorld2D.h"
#include "box2d/physics2d/body/Box2DBody.h"

namespace mars {
    Box2DWorld2D::Box2DWorld2D(Framework& framework, const WorldDefinition2D worldDef)
        : AWorld2D(worldDef), framework(framework) {
        world = new b2World(b2Vec2(worldDef.gravity.x, worldDef.gravity.y));
        debugDraw = std::make_unique<b2DrawImpl>(framework);
    }

    void Box2DWorld2D::initialize() {
        debugDraw->initialize();
        world->SetDebugDraw(debugDraw.get());
    }

    void Box2DWorld2D::update(const Time &time, const uint32_t velocityIterations, const uint32_t positionIterations) {
        world->Step(
            time.getDeltaTimeMS(),
            static_cast<int32_t>(velocityIterations),
            static_cast<int32_t>(positionIterations));
    }

    void Box2DWorld2D::render() {
        world->DebugDraw();
        debugDraw->render();
    }

    std::shared_ptr<ABody2D> Box2DWorld2D::createBody(BodyDefinition2D &bodyDef) {
        return std::make_shared<Box2DBody>(*this, bodyDef);
    }


}
