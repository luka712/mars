
#include "box2d/physics2d/util/Box2DUtil.h"

namespace mars {

    b2BodyType Box2DUtil::convertBodyType(const BodyType2D type) {
        switch (type) {
            case BodyType2D::StaticBody:
                return b2_staticBody;
            case BodyType2D::DynamicBody:
                return b2_dynamicBody;
            case BodyType2D::KinematicBody:
                return b2_kinematicBody;

            default:
                throw std::runtime_error("Unknown body type.");
        }
    }
}