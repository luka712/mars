//
// Created by lukaa on 1.2.2025..
//

#ifndef COLLISION2DSYSTEM_H
#define COLLISION2DSYSTEM_H

#include <vector>
#include <ecs/camera/Camera2D.h>

#include "ecs/collision/Collider2D.h"


namespace mars {
    class Framework;

    //! The system that handles 2D collisions.
    class Collision2DSystem {

    public:
        //! Construct a new Collision2DSystem object.
        //! @param framework The framework.
        Collision2DSystem(Framework &framework);

        //! Add a collider component to the system.
        //! @param collider The Collider2D component.
        void add(Collider2D *collider);

        //! Remove a collider component from the system.
        //! @param collider The Collider2D component.
        void remove(const Collider2D *collider);

        //! Update the script components.
        //! @param time The game time.
        void update(const Time &time);

        //! Render the sprite components.
        void render(Camera2D& camera) const;

    private:
        Framework &framework;
        std::vector<Collider2D *> colliders;
    };
};


#endif //COLLISION2DSYSTEM_H
