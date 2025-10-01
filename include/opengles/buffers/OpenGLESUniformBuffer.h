//
// Created by Erkapic Luka on 09.02.25.
//

#ifndef OPENGLESUNIFORMBUFFER_H
#define OPENGLESUNIFORMBUFFER_H

#include <Framework.h>
#include "core/buffers/a_uniform_buffer.h"

namespace mars
{
    class Framework;

    //! The OpenGLES implementation of the uniform buffer.
    class OpenGLESUniformBuffer : public AUniformBuffer {

    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        OpenGLESUniformBuffer(Framework& framework, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

        //! The constructor.
        //! @param framework The framework.
        //! @param inputData The data.
        //! @param label The label.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        OpenGLESUniformBuffer(Framework& framework, const void* inputData, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

        //! Gets the buffer data.
        //! @return The buffer data.
        [[nodiscard]] void* getBufferData() const { return bufferData; }

        //! @inheritDoc
        void update(void *data, uint32_t byteSize) override;

        //! @inheritDoc
        std::string printInfo() override;

        //! @inheritDoc
        void destroy() override;

    protected:
        // There is no actual buffer for OpenGLES, instead uniform can be used instead. So we just keep chunk of memory,
        // to be passed as glUniformXX.
        void* bufferData{};
    };

    //! Converts the @ref AUniformBuffer to @ref OpenGLESUniformBuffer.
    //! @param uniformBuffer The uniform buffer.
    //! @returns The @ref OpenGLESUniformBuffer.
    OpenGLESUniformBuffer* toOpenGLESUniformBuffer(AUniformBuffer* uniformBuffer);

    //! Converts the @ref AUniformBuffer to @ref OpenGLESUniformBuffer.
    //! @param uniformBuffer The uniform buffer.
    //! @returns The @ref OpenGLESUniformBuffer.
    std::shared_ptr<OpenGLESUniformBuffer> toOpenGLESUniformBuffer(const std::shared_ptr<AUniformBuffer> &uniformBuffer);
}

#endif //OPENGLESUNIFORMBUFFER_H
