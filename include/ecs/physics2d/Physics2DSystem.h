//
// Created by Erkapic Luka on 27.3.2025.
//

#ifndef PHYSICS2D_SYSTEM_H
#define PHYSICS2D_SYSTEM_H

#include <vector>
#include "RigidBody2D.h"
#include "core/physics2d/AWorld2D.h"

namespace mars {

    class Framework;

    //! The Physics2DManager class.
    class Physics2DSystem {

    public:
        //! The constructor of the Physics2DSystem object.
        //! @param framework The framework.
        Physics2DSystem(Framework& framework);

        //! Get the world.
        //! @return The world.
        [[nodiscard]] AWorld2D& getWorld() const { return *world; }

        //! Add a body 2d to the system.
        //! @param body The body 2d.
        void add(RigidBody2D* body);

        //! Remove a body 2d from the system.
        //! @param body The body 2d.
        void remove(const RigidBody2D* body);

        //! Update the physics 2d components.
        //! @param time The game time.
        void update(const Time& time);

    private:
        Framework& framework;
        std::unique_ptr<AWorld2D> world;
        std::vector<std::shared_ptr<RigidBody2D>> bodies;
    };

}

#endif //PHYSICS2D_SYSTEM_H
