//
// Created by luka on 12.02.25.
//

#ifndef CAMERAFACTORY_H
#define CAMERAFACTORY_H
#include "core/OrthographicCamera.h"

namespace mars {
    class Framework;

    //! The camera factory.
    class CameraFactory {
    public:
        //! The constructor.
        //! @param framework The framework.
        explicit CameraFactory(Framework &framework);

        //! Create orthographic camera.
        //! @param left The left edge of the camera volume.
        //! @param right The right edge of the camera volume.
        //! @param top The top edge of the camera volume.
        //! @param bottom The bottom edge of the camera volume.
        //! @param nearPlane The near plane.
        //! @param farPlane The far plane.
        //! @return The orthographic camera.
        std::shared_ptr<OrthographicCamera> createOrthographicCamera(
            float left,
            float right,
            float top,
            float bottom,
            float nearPlane,
            float farPlane) const;

    private:
        Framework &framework;
    };
}

#endif //CAMERAFACTORY_H
