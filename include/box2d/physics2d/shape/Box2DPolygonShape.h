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
    class Box2DPolygonShape final : public ABox2DShape<b2PolygonShape>, public APolygonShape {
    public:
        //! Construct a new Box2DPolygonShape object.
        explicit Box2DPolygonShape();

        //! @copydoc
        void setAsBox(float halfWidth, float halfHeight) override;

        //! @copydoc
        [[nodiscard]] ShapeType2D getShapeType() const override {
            return ShapeType2D::Polygon;
        }
    };
}


#endif //BOX2D_POLYGON_SHAPE_H
