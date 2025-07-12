//
// Created by luka on 18.1.2025.
//

#ifndef OPEN_GLES_VERTEX_BUFFER_H
#define OPEN_GLES_VERTEX_BUFFER_H

#include "Framework.h"
#include "core/log/Logger.h"
#include "opengles/renderer/opengles_renderer.h"
#include "core/buffers/a_vertex_buffer.h"
#include "gpu_util/opengles/opengles_util.h"

namespace mars {
    //! The OpenGLES implementation of the vertex buffer.
    class OpenGLESVertexBuffer : public AVertexBuffer {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        explicit OpenGLESVertexBuffer(const Framework &framework, const std::string &label = "");

        //! Gets the underlying buffer.
        //! @returns The OpenGLES buffer.
        [[nodiscard]] GLuint getBuffer() const { return buffer; }

        [[nodiscard]] bool isWritable() const override { return glHint != GL_STATIC_DRAW; }

        void initialize(const void *data, uint32_t byteSize, uint32_t byteStride, uint32_t vertexCount, BufferUsage usage) override;

        void initialize(uint32_t byteSize, uint32_t byteStride, uint32_t vertexCount) override;

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

    //! Convert the @ref AVertexBuffer to the @ref OpenGLESVertexBuffer.
    //! @param vertexBuffer The vertex buffer.
    //! @returns The @ref OpenGLESVertexBuffer.
    OpenGLESVertexBuffer *toOpenGLESVertexBuffer(AVertexBuffer *vertexBuffer);
}

#endif //OPEN_GLES_VERTEX_BUFFER_H
