//
// Created by Erkapic Luka on 23.2.2025.
//

#ifndef A_PHYSICS_BODY2D_H
#define A_PHYSICS_BODY2D_H

#include "core/physics2d/body/BodyDefinition2D.h"

namespace mars {
    //! The 2D physics body.
    class ABody2D {

    public:
        //! Set the position.
        //! @param position The position.
        virtual void setPosition(glm::vec2 position) = 0;

    };
}

#endif //A_PHYSICS_BODY2D_H
