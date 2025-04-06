//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef WORLD_2D_H
#define WORLD_2D_H

#include <box2d/box2d.h>
#include "box2d/physics2d/draw/b2DrawImpl.h"
#include "core/physics2d/AWorld2D.h"
#include "core/physics2d/body/ABody2D.h"

namespace mars {

    class Framework;

    //! The 2D physics world.
    class Box2DWorld2D final : public AWorld2D {
    public:
        //! Construct a new APhysicsWorld2D object.
        //! @param framework The framework.
        //! @param worldDef The world definition.
        explicit Box2DWorld2D(Framework& framework, WorldDefinition2D worldDef);

        //! Get the world.
        //! @return The world.
        [[nodiscard]] b2World& getBox2DWorld() const { return *world; }

        //! @copydoc
        void initialize() override;

        //! @copydoc
        void update(const Time& time, uint32_t velocityIterations, uint32_t positionIterations) override;

        //! @copydoc
        void render() override;

        std::shared_ptr<ABody2D> createBody(BodyDefinition2D &bodyDef) override;

    private:
        Framework& framework;
        b2World* world{};
        std::unique_ptr<b2DrawImpl> debugDraw;

        static b2BodyType convertBodyType(BodyType2D type);

    };
}


#endif //WORLD_2D_H
