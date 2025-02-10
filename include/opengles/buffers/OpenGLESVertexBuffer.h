//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESVERTEXBUFFER_H
#define OPENGLESVERTEXBUFFER_H

#include "opengles/opengles.h"
#include "Framework.h"
#include "core/log/Logger.h"
#include "opengles/renderer/OpenGLESRenderer.h"
#include "core/buffers/AVertexBuffer.h"
#include "opengles/util/OpenGLESUtil.h"

namespace mars {

    //! The OpenGLES implementation of the vertex buffer.
    class OpenGLESVertexBuffer : public AVertexBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        explicit OpenGLESVertexBuffer(const Framework &framework, const std::string &label = "");

        [[nodiscard]] bool isWritable() const override { return glHint != GL_STATIC_DRAW; }

        void initialize(void *data, uint32_t byteSize, uint32_t vertexCount, BufferUsage usage) override;

        void initialize(uint32_t byteSize, uint32_t vertexCount) override;

        void update(void *data, uint32_t byteSize, uint32_t offset) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        OpenGLESRenderer &renderer;
        Logger &logger;
        BufferUsage usage = BufferUsage::Vertex;
        GLuint buffer{};
        GLenum glHint = GL_STATIC_DRAW;
        GLenum glTarget = GL_ARRAY_BUFFER;

    };
}

#endif //OPENGLESVERTEXBUFFER_H
