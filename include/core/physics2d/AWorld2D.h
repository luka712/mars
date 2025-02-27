//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef A_PHYSICS_WORLD2D_H
#define A_PHYSICS_WORLD2D_H

#include <memory>
#include "core/physics2d/WorldDefinition2D.h"
#include "core/physics2d/body/BodyDefinition2D.h"
#include "core/physics2d/body/ABody2D.h"

namespace mars {
    //! The 2D physics world.
    class AWorld2D {
    public:
        virtual ~AWorld2D() = default;

        //! Construct a new APhysicsWorld2D object.
        //! @param worldDef The world definition.
        explicit AWorld2D(WorldDefinition2D worldDef);

        //! Create a new body.
        //! @param bodyDef The body definition.
        //! @return The body.
        virtual std::shared_ptr<ABody2D> createBody(BodyDefinition2D &bodyDef) = 0;

    protected:
        WorldDefinition2D worldDef;
    };
}

#endif //A_PHYSICS_WORLD2D_H
