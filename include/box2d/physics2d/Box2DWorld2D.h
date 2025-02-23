//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef WORLD_2D_H
#define WORLD_2D_H

#include <box2d/box2d.h>
#include "core/physics2d/AWorld2D.h"

namespace mars {

    //! The 2D physics world.
    class Box2DWorld2D final : public AWorld2D{
    public:
        //! Construct a new APhysicsWorld2D object.
        //! @param worldDef The world definition.
        explicit Box2DWorld2D(WorldDefinition2D worldDef);

        void createBody(BodyDefinition2D &bodyDef) override;

    private:
        b2World* world{};
    };
}


#endif //WORLD_2D_H
