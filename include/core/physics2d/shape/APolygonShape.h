//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef A_POLYGON_SHAPE_H
#define A_POLYGON_SHAPE_H

#include "core/physics2d/shape/AShape.h"

namespace mars {
    //! The 2D physics polygon shape.
    class APolygonShape : public AShape {

    public:

        //! Build vertices to represent an axis-aligned box centered on the local origin.
        //! @param halfWidth The half width.
        //! @param halfHeight The half height.
        virtual void setAsBox(float halfWidth, float halfHeight) = 0;
    };
}

#endif //A_POLYGON_SHAPE_H
