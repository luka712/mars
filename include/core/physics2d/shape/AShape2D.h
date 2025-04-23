//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef A_SHAPE_H
#define A_SHAPE_H

#include "core/physics2d/enums.h"

namespace mars {

    //! The 2D physics shape.
    class AShape2D {
    public:
        //! The constructor.
        AShape2D() : density(0) {}

        virtual ~AShape2D() = default;

        //! Get the shape type.
        //! @return The shape type.
        [[nodiscard]] virtual ShapeType2D getShapeType() const = 0;

        //! Gets or set density of a shape, typically in kg/m^2.
        float density;
    };

}


#endif //A_SHAPE_H
