//
// Created by luka on 04/01/25.
//

#ifndef QUAD_H
#define QUAD_H

#include <glm/vec2.hpp>

namespace mars {

    //! The quad structure.
    struct Quad {

        //! The first point.
        glm::vec2 a;

        //! The second point.
        glm::vec2 b;

        //! The third point.
        glm::vec2 c;

        //! The fourth point.
        glm::vec2 d;
    };
}


#endif //QUAD_H
