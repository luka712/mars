//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef WORLD_2D_H
#define WORLD_2D_H

#include <box2d/box2d.h>
#include "core/physics2d/AWorld2D.h"
#include "core/physics2d/body/ABody2D.h"

namespace mars {

    //! The 2D physics world.
    class Box2DWorld2D final : public AWorld2D {
    public:
        //! Construct a new APhysicsWorld2D object.
        //! @param worldDef The world definition.
        explicit Box2DWorld2D(WorldDefinition2D worldDef);

        //! Get the world.
        //! @return The world.
        [[nodiscard]] b2World& getBox2DWorld() const { return *world; }

        void update(const Time& time, uint32_t velocityIterations, uint32_t positionIterations) override;

        std::shared_ptr<ABody2D> createBody(BodyDefinition2D &bodyDef) override;

    private:
        b2World* world{};

        static b2BodyType convertBodyType(BodyType2D type);

    };
}


#endif //WORLD_2D_H
