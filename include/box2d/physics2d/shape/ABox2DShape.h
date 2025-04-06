//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_SHAPE_H
#define BOX2D_SHAPE_H

namespace mars {
    //! The 2D physics polygon shape.
    //! T must be one of b2Shape implementations.
    template<typename T>
    class ABox2DShape {
    public:
        //! Get the shape.
        //! @return The shape.
        [[nodiscard]] T *getBox2DShape() { return shape; }

    protected :
        T *shape{};
    };
}

#endif //BOX2D_SHAPE_H
