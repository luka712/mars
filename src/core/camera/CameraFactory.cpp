//
// Created by luka on 12.02.25.
//

#include "Framework.h"
#include "core/camera/CameraFactory.h"


namespace mars {
    CameraFactory::CameraFactory(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<OrthographicCamera> CameraFactory::createOrthographicCamera(
        float left,
        float right,
        float top,
        float bottom,
        float nearPlane,
        float farPlane) const {
        return std::make_shared<OrthographicCamera>(framework, left, right, top, bottom, nearPlane, farPlane);
    }
}
