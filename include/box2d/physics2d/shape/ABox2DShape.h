//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_SHAPE_H
#define BOX2D_SHAPE_H

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
        b2Shape* getBox2DShape() {  return shape; }

        //! Get the shape type.
        //! @return The shape type.
        Box2DShapeType getShapeType() { return type; }

    protected:

        //! Initialize the shape.
        //! Can be set just to pointer of the shape implementation.
        virtual void initShape() = 0;
        b2Shape* shape{};
        Box2DShapeType type{};
    };
}

#endif //BOX2D_SHAPE_H
