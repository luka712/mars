//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef A_PHYSICS_WORLD2D_H
#define A_PHYSICS_WORLD2D_H

#include <memory>
#include "core/physics2d/WorldDefinition2D.h"
#include "core/physics2d/body/BodyDefinition2D.h"
#include "core/physics2d/body/ABody2D.h"
#include "core/time/Time.h"

namespace mars {
    //! The 2D physics world.
    class AWorld2D {
    public:
        virtual ~AWorld2D() = default;

        //! Construct a new APhysicsWorld2D object.
        //! @param worldDef The world definition.
        explicit AWorld2D(WorldDefinition2D worldDef);

        //! Initialize the world.
        virtual void initialize() = 0;

        //! Create a new body.
        //! @param bodyDef The body definition.
        //! @return The body.
        virtual std::shared_ptr<ABody2D> createBody(BodyDefinition2D &bodyDef) = 0;

        //! Destroy a body.
        //! @param body The body to destroy or remove from world.
        virtual void destroyBody(std::shared_ptr<ABody2D> &body) = 0;

        //! Update the world.
        //! @param time The time.
        //! @param velocityIterations The velocity iterations.
        //! The higher the number, the more accurate the simulation, but at cost of performance.
        //! Generally, between 6 and 10 is a good range.
        //! @param positionIterations The position iterations.
        //! The higher the number, the more accurate the simulation, but at cost of performance.
        //! Generally, between 2 and 4 is a good range.
        virtual void update(const Time &time, uint32_t velocityIterations, uint32_t positionIterations) = 0;

        //! Renders the draw information. Usually used for debug drawing.
        virtual void render() = 0;

    protected:
        WorldDefinition2D worldDef;
    };
}

#endif //A_PHYSICS_WORLD2D_H
