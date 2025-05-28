#include <stdexcept>
#include "box2d/physics2d/body/Box2DBody.h"
#include "box2d/physics2d/shape/Box2DPolygonShape.h"
#include "box2d/physics2d/fixture/Box2DFixture.h"
#include "box2d/physics2d/shape/ABox2DShape.h"
#include "box2d/physics2d/util/Box2DUtil.h"

namespace mars {
    Box2DBody::Box2DBody(AWorld2D &world, const BodyDefinition2D &bodyDef)
        : world(dynamic_cast<Box2DWorld2D &>(world)) {
        // Get pointer to the box 2d world.
        box2DWorld = &this->world.getBox2DWorld();

        // Create body definition.
        b2BodyDef box2DBodyDef{};
        box2DBodyDef.type = Box2DUtil::convertBodyType(bodyDef.type);
        box2DBodyDef.position.Set(bodyDef.position.x, bodyDef.position.y);
        box2DBodyDef.angle = bodyDef.angle;

        // Create box 2d body.
        body = box2DWorld->CreateBody(&box2DBodyDef);
    }

    glm::vec2 Box2DBody::getPosition() {
        b2Vec2 pos = body->GetPosition();
        return {pos.x, pos.y};
    }

    std::shared_ptr<AFixture2D> Box2DBody::createFixture(AShape2D *shape, float density) {

        b2Fixture *fixture;
        ShapeType2D shapeType = shape->getShapeType();
        if (shapeType == ShapeType2D::Polygon) {
            const auto shapeImpl = reinterpret_cast<Box2DPolygonShape *>(shape);
            const auto b2Shape = shapeImpl->getBox2DShape();
            if (b2Shape == nullptr) {
                const std::string msg = "Box2DBody::createFixture: Shape is not a polygon shape.";
                throw std::runtime_error(msg);
            }
            fixture = body->CreateFixture(b2Shape, density);
        }
        // TODO: other types
        else {
            const std::string msg = "Box2DBody::createFixture: Uknown shape type.";
            throw std::runtime_error(msg);
        }

        return std::make_shared<Box2DFixture>(fixture);
    }

    std::shared_ptr<AFixture2D> Box2DBody::createFixture(FixtureDefinition2D &fixtureDef) {
        b2FixtureDef def;
        AShape2D* shape = fixtureDef.shape;
        def.density = fixtureDef.density;
        def.friction = fixtureDef.friction;

        if (shape == nullptr) {
            const std::string msg = "Box2DBody::createFixture: Shape is null.";
            throw std::runtime_error(msg);
        }
        b2Fixture *fixture;
        switch (shape->getShapeType()) {
            case ShapeType2D::Polygon:
                auto *shapeImpl = reinterpret_cast<Box2DPolygonShape *>(shape);
                b2PolygonShape *b2Shape = shapeImpl->getBox2DShape();
                if (b2Shape == nullptr) {
                    const std::string msg = "Box2DBody::createFixture: Shape is not a polygon shape.";
                    throw std::runtime_error(msg);
                }
                def.shape = b2Shape;
                fixture = body->CreateFixture(&def);
                if (fixture == nullptr) {
                    const std::string msg = "Box2DBody::createFixture: Fixture is null.";
                    throw std::runtime_error(msg);
                }
        }

        return std::make_shared<Box2DFixture>(fixture);
    }
}
