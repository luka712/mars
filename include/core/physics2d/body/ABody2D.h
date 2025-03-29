//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef A_PHYSICS_BODY2D_H
#define A_PHYSICS_BODY2D_H

#include <memory>
#include "core/physics2d/fixture/AFixture2D.h"
#include "core/physics2d/shape/AShape.h"
#include "core/physics2d/fixture/FixtureDefinition2D.h"

namespace mars {
    //! The 2D physics body.
    class ABody2D {

    public:
        //! The destructor
        virtual ~ABody2D() = default;

        //! Get the position of the body.
        //! @return The position of the body.
        virtual glm::vec2 getPosition() = 0;

        //! Creates a fixture from a shape and attach it to this body.
        //! @param shape The shape to be cloned.
        //! @param density The shape density (set to zero for static bodies).
        virtual std::shared_ptr<AFixture2D> createFixture(AShape *shape, float density) = 0;

        //! Creates a fixture from a fixture definition and attach it to this body.
        //! @param fixture The fixture definition.
        virtual std::shared_ptr<AFixture2D> createFixture(FixtureDefinition2D &fixture) = 0;
    };
}

#endif //A_PHYSICS_BODY2D_H
