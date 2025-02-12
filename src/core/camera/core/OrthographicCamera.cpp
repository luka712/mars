//
// Created by luka on 09.02.25.
//
#include <sstream>
#include "Framework.h"
#include "core/math/Matrix.h"
#include "core/camera/core/OrthographicCamera.h"

namespace mars {
    OrthographicCamera::OrthographicCamera(Framework& framework,
        float left, float right, float top, float bottom,
        float nearPlane, float farPlane,
        bool adjustForAppropriateRenderer
        ): framework(framework){

        // If OpenGL z space is 2 units, otherwise 1 unit.
        zSpaceLength = framework.getRenderingBackend() == RenderingBackend::OpenGL
            || framework.getRenderingBackend() == RenderingBackend::OpenGLES ? 2 : 1;

        isDirty = true;
        this->left = left;
        this->right = right;
        this->bottom = bottom;
        this->top = top;
        this->nearPlane = nearPlane;
        this->farPlane = farPlane;
        eye = glm::vec3(0,0,1);
        target = glm::vec3(0,0,0);
        updateMatrices();

        // Create buffers.
        viewMatrixBuffer = framework.getBuffersFactory().createUniformBuffer(&viewMatrix,
            "OrthographicCamera.viewMatrix",
            sizeof(viewMatrix),
            BufferUsage::Uniform);
        projectionMatrixBuffer = framework.getBuffersFactory().createUniformBuffer(&projectionMatrix,
            "OrthographicCamera.projectionMatrix",
            sizeof(projectionMatrix),
            BufferUsage::Uniform);
        projectionViewMatrixBuffer = framework.getBuffersFactory().createUniformBuffer(&projectionViewMatrix,
            "OrthographicCamera.projectionViewMatrix",
            sizeof(projectionViewMatrix),
            BufferUsage::Uniform);
    }

    void OrthographicCamera::updateMatrices() {
        viewMatrix = lookAt(eye, target, glm::vec3(0,1,0));
        // TODO: account for different z space, right now it's setup for OpenGL
        projectionMatrix = glm::ortho(left, right, bottom, top, nearPlane, farPlane);
        projectionViewMatrix = viewMatrix * projectionMatrix;
    }

    void OrthographicCamera::updateBuffers() {
        updateMatrices();
        projectionMatrixBuffer->update(&projectionMatrix, sizeof(projectionMatrix));
        viewMatrixBuffer->update(&viewMatrix, sizeof(viewMatrix));
        projectionViewMatrixBuffer->update(&projectionViewMatrix, sizeof(projectionViewMatrix));
    }

    void OrthographicCamera::update(Time time) {
        if (isDirty) {
            isDirty = false;
            updateBuffers();
        }
    }

    void OrthographicCamera::destroy() const {
        projectionMatrixBuffer->destroy();
        viewMatrixBuffer->destroy();
        projectionViewMatrixBuffer->destroy();
    }

    std::string OrthographicCamera::printInfo() const {

        std::ostringstream oss;
        oss << "OrthographicCamera.\n";
        oss << "\tViewMatrix: \n";
        oss << toPrettyString(viewMatrix) << "\n";
        oss << "\tProjectionMatrix: \n";
        oss <<  toPrettyString(projectionMatrix) << "\n";
        oss << "\tProjectionViewMatrix: \n";
        oss <<  toPrettyString(projectionViewMatrix) << "\n";

        framework.getLogger().info(oss.str());

        return oss.str();
    }

}
