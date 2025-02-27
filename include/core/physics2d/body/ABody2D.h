//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef A_PHYSICS_BODY2D_H
#define A_PHYSICS_BODY2D_H

#include "core/physics2d/fixture/AFixture.h"
#include "core/physics2d/shape/AShape.h"

namespace mars {
    //! The 2D physics body.
    class ABody2D {

    public:
        //! The destructor
        virtual ~ABody2D() = default;

        //! Creates a fixture from a shape and attach it to this body.
        //! @param shape The shape to be cloned.
        //! @param density The shape density (set to zero for static bodies).
        virtual std::shared_ptr<AFixture> createFixture(AShape *shape, float density) = 0;
    };
}

#endif //A_PHYSICS_BODY2D_H
