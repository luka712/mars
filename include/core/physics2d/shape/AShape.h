//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef A_SHAPE_H
#define A_SHAPE_H

namespace mars {

    //! The shape type for 2D physics.
    enum class ShapeType2D {
        Polygon
    };

    //! The 2D physics shape.
    class AShape {
    public:
        virtual ~AShape() = default;

        //! Get the shape type.
        //! @return The shape type.
        [[nodiscard]] virtual ShapeType2D getShapeType() const = 0;
    };

}


#endif //A_SHAPE_H
