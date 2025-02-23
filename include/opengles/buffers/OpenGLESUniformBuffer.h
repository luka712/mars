//
// Created by luka on 09.02.25.
//

#ifndef OPENGLESUNIFORMBUFFER_H
#define OPENGLESUNIFORMBUFFER_H

#include <Framework.h>
#include "core/buffers/AUniformBuffer.h"

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
        OpenGLESUniformBuffer(Framework& framework, void* inputData, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

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
}

#endif //OPENGLESUNIFORMBUFFER_H
