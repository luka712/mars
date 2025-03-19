//
// Created by Erkapic Luka on 18.3.2025.
//

#ifndef OPEN_GLES_INSTANCE_BUFFER_H
#define OPEN_GLES_INSTANCE_BUFFER_H

#include "opengles/opengles.h"
#include "core/buffers/AInstanceBuffer.h"

namespace mars {
    class Framework;

    //! The Open GLES implementation of the instance buffer.
    class OpenGLESInstanceBuffer final : public AInstanceBuffer {
    public:
        //! Construct a new OpenGLESInstanceBuffer object.
        //! @param framework The framework.
        //! @param label The label of the buffer.
        explicit OpenGLESInstanceBuffer(Framework &framework, std::string label = "");

        //! Get the underlying OpenGLES buffer.
        //! @return The underlying OpenGLES buffer.
        [[nodiscard]] GLuint getBuffer() const { return buffer; }

        uint32_t getInstanceCount() override { return instanceCount; }

        uint32_t getByteSize() override { return byteSize; }

        uint32_t getByteStride() override { return byteStride; }

        const std::string &getLabel() override { return label; }

        void initialize(const void *data, uint32_t byteSize, uint32_t strideInBytes, uint32_t instanceCount) override;

        void destroy() override;

    private:
        Framework &framework;
        GLuint buffer = 0;
        uint32_t instanceCount = 1;
        uint32_t byteSize = 0;
        uint32_t byteStride = 0;
        std::string label;
    };

    //! Converts the @ref AInstanceBuffer to @ref OpenGLESInstanceBuffer.
    //! @param instanceBuffer The instance buffer.
    //! @returns The @ref OpenGLESInstanceBuffer.
    OpenGLESInstanceBuffer* toOpenGLESInstanceBuffer(AInstanceBuffer* instanceBuffer);

    //! Converts the @ref AInstanceBuffer to @ref OpenGLESInstanceBuffer.
    //! @param instanceBuffer The instance buffer.
    //! @returns The @ref OpenGLESInstanceBuffer.
    std::shared_ptr<OpenGLESInstanceBuffer> toOpenGLESInstanceBuffer(const std::shared_ptr<AInstanceBuffer> &instanceBuffer);
}

#endif //OPEN_GLES_INSTANCE_BUFFER_H
