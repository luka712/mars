//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef BODY_DEFINITION_2D_H
#define BODY_DEFINITION_2D_H

#include <glm/glm.hpp>
#include "core/physics2d/enums.h"

namespace mars {
    //! The 2D body definition.
    struct BodyDefinition2D {
        //! Construct a new BodyDefinition2D object.
        BodyDefinition2D()
            : type(BodyType2D::StaticBody), position(glm::vec2(0.0f, 0.0f)), angle(0.0f) {
        }

        //! The body type.
        BodyType2D type;

        //! The position.
        glm::vec2 position;

        //! The world angle of the body in radians.
        float angle;
    };
}


#endif //BODY_DEFINITION_2D_H
