//
// Created by Erkapic Luka on 27.2.2025.
//

#ifndef BOX2D_POLYGON_SHAPE_H
#define BOX2D_POLYGON_SHAPE_H

#include "box2d/b2_polygon_shape.h"
#include "box2d/physics2d/shape/ABox2DShape.h"
#include "core/physics2d/shape/APolygonShape.h"

namespace mars {

    //! The Box2D implementation of the 2D physics polygon shape.
    class Box2DPolygonShape final : public ABox2DShape, public APolygonShape {
    public:

        //! @copydoc
        [[nodiscard]] b2Shape* getBox2DShape() override { return &polygonShape; }

        //! @copydoc
        void setAsBox(float halfWidth, float halfHeight) override;

    protected:
        void initShape() override;

    private:
        b2PolygonShape polygonShape;
    };
}


#endif //BOX2D_POLYGON_SHAPE_H
