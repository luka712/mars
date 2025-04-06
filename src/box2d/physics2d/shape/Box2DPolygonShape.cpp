//
// Created by Erkapic Luka on 27.2.2025.
//

#include "box2d/physics2d/shape/Box2DPolygonShape.h"

namespace mars {

    Box2DPolygonShape::Box2DPolygonShape() {
        shape = new b2PolygonShape();
    }


    void Box2DPolygonShape::setAsBox(const float halfWidth, const float halfHeight) {
        shape->SetAsBox(halfWidth, halfHeight);
    }
}
