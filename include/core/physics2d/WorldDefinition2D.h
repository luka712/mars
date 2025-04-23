//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef WORLD_DEFINITION_2D_H
#define WORLD_DEFINITION_2D_H

#include <glm/glm.hpp>

namespace mars {

    //! The world definition for the 2D physics world.
    struct WorldDefinition2D {

        //! Construct a new WorldDefinition2D object.
        WorldDefinition2D()
            : gravity(0.0f, 9.81f) {}

        //! The gravity.
        glm::vec2 gravity;
    };
}

#endif //WORLD_DEFINITION_2D_H
