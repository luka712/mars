//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_SHAPE_H
#define BOX2D_SHAPE_H

#include <box2d/b2_shape.h>

namespace mars {

    enum class Box2DShapeType {
        Polygon,
    };

    //! The 2D physics polygon shape.
    class ABox2DShape {
    public:
        virtual ~ABox2DShape() = default;

        //! Get the shape.
        //! @return The shape.
        [[nodiscard]] virtual b2Shape* getBox2DShape() = 0;

        //! Get the shape type.
        //! @return The shape type.
        [[nodiscard]] Box2DShapeType getShapeType() const { return type; }

    protected:
        Box2DShapeType type{};

        //! Initialize the shape.
        //! Can be set just to pointer of the shape implementation.
        virtual void initShape() = 0;

    };
}

#endif //BOX2D_SHAPE_H
