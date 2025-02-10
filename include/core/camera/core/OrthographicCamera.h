//
// Created by luka on 09.02.25.
//

#ifndef ORTHOGRAPHICCAMERA_H
#define ORTHOGRAPHICCAMERA_H

#include <glm/glm.hpp>

namespace mars
{
    class Framework;

    //! The orthographic or 2D camera.
    class OrthographicCamera
    {
    public:
        //! Creates  a new instance of the @see OrthographicCamera class with the specified parameters.
        //! @param framework The framework.
        //! @param left The left edge of the camera volume.
        //! @param right The right edge of the camera volume.
        //! @param top The top edge of the camera volume.
        //! @param bottom The bottom edge of the camera volume.
        //! @param adjustForAppropriateRenderer If render is OpenGL or OpenGLES we need to adjust Z space.
        OrthographicCamera(Framework& framework,
                           float left,
                           float right,
                           float top,
                           float bottom,
                           float near,
                           float far,
                           bool adjustForAppropriateRenderer = true);

        //! Gets the projection matrix.
        //! @returns The projection matrix.
        glm::mat4 getProjectionMatrix();

        //! Gets the view matrix.
        //! @returns The view matrix.
        glm::mat4 getViewMatrix();

        //! Gets the projection view matrix.
        //! @returns The projection view matrix.
        glm::mat4 getProjectionViewMatrix();




    protected:
        Framework& framework;
    };
}

#endif //ORTHOGRAPHICCAMERA_H
