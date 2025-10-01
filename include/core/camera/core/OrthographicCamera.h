//
// Created by luka on 09.02.25.
//

#ifndef ORTHOGRAPHIC_CAMERA_H
#define ORTHOGRAPHIC_CAMERA_H

#include <memory>
#include <glm/glm.hpp>
#include "core/buffers/a_uniform_buffer.h"
#include "core/time/Time.h"

namespace mars
{
    class Framework;

    //! The orthographic or 2D camera.
    class OrthographicCamera {
    public:
        //! Creates  a new instance of the @see OrthographicCamera class with the specified parameters.
        //! @param framework The framework.
        //! @param left The left edge of the camera volume.
        //! @param right The right edge of the camera volume.
        //! @param top The top edge of the camera volume.
        //! @param bottom The bottom edge of the camera volume.
        //! @param nearPlane The near plane.
        //! @param farPlane The far plane.
        //! @param adjustForAppropriateRenderer If render is OpenGL or OpenGLES we need to adjust Z space.
        OrthographicCamera(Framework& framework,
                           float left,
                           float right,
                           float top,
                           float bottom,
                           float nearPlane,
                           float farPlane,
                           bool adjustForAppropriateRenderer = true);

        //! Gets the projection matrix.
        //! @returns The projection matrix.
        [[nodiscard]] glm::mat4 getProjectionMatrix() const { return projectionMatrix; }

        //! Gets the view matrix.
        //! @returns The view matrix.
        [[nodiscard]] glm::mat4 getViewMatrix() const { return  viewMatrix; }

        //! Gets the projection view matrix.
        //! @returns The projection view matrix.
        [[nodiscard]] glm::mat4& getProjectionViewMatrix() { return  projectionViewMatrix; }

        //! Gets the view matrix buffer.
        //! @return The view matrix buffer.
        [[nodiscard]] AUniformBuffer& getViewBuffer() const { return *viewMatrixBuffer; }

        //! Gets the projection matrix buffer.
        //! @return The projection matrix buffer.
        [[nodiscard]] AUniformBuffer& getProjectionBuffer() const { return *projectionMatrixBuffer; }

        //! Gets the projection view matrix buffer.
        //! @return The projection view matrix buffer.
        [[nodiscard]] AUniformBuffer& getProjectionViewBuffer() const { return *projectionViewMatrixBuffer; }

        //! Update the buffers of this camera.
        void updateBuffers();

        //! Updates the orthographic camera.
        //! @param time The time
        void update(Time time);

        //! Destroy the camera object.
        void destroy() const;

        //! Print information about the camera.
        //! @return Returns string information about the camera.
        std::string printInfo() const;

    protected:
        Framework& framework;
        bool isDirty;
        int32_t zSpaceLength;
        glm::vec3 eye{};
        glm::vec3 target{};
        std::shared_ptr<AUniformBuffer> projectionViewMatrixBuffer;
        std::shared_ptr<AUniformBuffer> viewMatrixBuffer;
        std::shared_ptr<AUniformBuffer> projectionMatrixBuffer;
        glm::mat4 projectionMatrix{}, viewMatrix{}, projectionViewMatrix{};
        float left{}, right{}, top{}, bottom{}, nearPlane{}, farPlane{};

        //! Update the matrices.
        void updateMatrices();

    };
}

#endif //ORTHOGRAPHIC_CAMERA_H
