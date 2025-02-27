//
// Created by Erkapic Luka on 27.2.2025.
//

#include "box2d/physics2d/body/Box2DBody.h"
#include "box2d/physics2d/fixture/Box2DFixture.h"
#include "box2d/physics2d/shape/ABox2DShape.h"

namespace mars {
    Box2DBody::Box2DBody(AWorld2D &world, const BodyDefinition2D &bodyDef)
        : world(dynamic_cast<Box2DWorld2D &>(world)) {
        // Get pointer to the box 2d world.
        box2DWorld = &this->world.getBox2DWorld();

        // Create body definition.
        b2BodyDef box2DBodyDef{};
        box2DBodyDef.position.Set(bodyDef.position.x, bodyDef.position.y);

        // Create box 2d body.
        body = box2DWorld->CreateBody(&box2DBodyDef);
    }

    std::shared_ptr<AFixture> Box2DBody::createFixture(AShape *shape, float density) {
        auto *shapeImpl = reinterpret_cast<ABox2DShape *>(shape);
        b2Fixture *fixture;
        switch (shapeImpl->getShapeType()) {
            case Box2DShapeType::Polygon:
                b2PolygonShape *b2Shape = (b2PolygonShape *) shapeImpl->getBox2DShape();
                fixture = body->CreateFixture(b2Shape, density);
        }


        return std::make_shared<Box2DFixture>(fixture);
    }
}
