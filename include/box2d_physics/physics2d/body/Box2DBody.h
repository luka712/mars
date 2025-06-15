//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_BODY_H
#define BOX2D_BODY_H

#include <box2d/box2d.h>
#include "box2d_physics/physics2d/Box2DWorld2D.h"
#include "core/physics2d/body/ABody2D.h"

namespace mars {

    //! The Box2D implementation of the 2D body.
    class Box2DBody : public ABody2D {
    public:
        //! The constructor.
        //! @param world The world.
        //! @param bodyDef The body definition.
        Box2DBody(AWorld2D& world, const BodyDefinition2D& bodyDef);

        //! @copydoc
        glm::vec2 getPosition() override;

        //! Gets the underlying Box2D body.
        [[nodiscard]] b2BodyId* getBox2DBody() const { return body; }

        //! @copydoc
        std::shared_ptr<AFixture2D> createFixture(AShape2D* shape, float density) override;

        //! @copydoc
        std::shared_ptr<AFixture2D> createFixture(FixtureDefinition2D& fixtureDef) override;

    private:
        Box2DWorld2D& world;
        b2World* box2DWorld;
        b2Body *body{};

    };
}


#endif //BOX2D_BODY_H
