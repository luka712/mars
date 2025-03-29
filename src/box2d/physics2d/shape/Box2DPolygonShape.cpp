//
// Created by Erkapic Luka on 27.2.2025.
//

#include "box2d/physics2d/shape/Box2DPolygonShape.h"

namespace mars {

    void Box2DPolygonShape::setAsBox(const float halfWidth, const float halfHeight) {
        polygonShape.SetAsBox(halfWidth, halfHeight);
    }

    void Box2DPolygonShape::initShape() {
        type = Box2DShapeType::Polygon;
    }
}
