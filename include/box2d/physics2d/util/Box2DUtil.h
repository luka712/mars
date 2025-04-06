//
// Created by Erkapic Luka on 4.4.2025.
//

#ifndef BOX2D_UTIL_H
#define BOX2D_UTIL_H

#include <box2d/b2_body.h>
#include "box2d/physics2d/Box2DWorld2D.h"

namespace mars {
    //! Utility class for Box2D.
    //! Mainly provides type conversion functions.
    struct Box2DUtil {

        //! Convert the body type from BodyType2D to b2BodyType.
        //! @param type The body type.
        //! @return The converted body type.
        static b2BodyType convertBodyType(BodyType2D type);
      };
}

#endif //BOX2D_UTIL_H
