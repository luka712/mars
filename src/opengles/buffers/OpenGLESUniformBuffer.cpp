//
// Created by luka on 09.02.25.
//

#include <sstream>
#include "opengles/buffers/OpenGLESUniformBuffer.h"


namespace mars
{
    OpenGLESUniformBuffer::OpenGLESUniformBuffer(Framework &framework, const std::string &label, const uint32_t byteSize, const BufferUsage bufferUsage)
        : AUniformBuffer(framework, label, byteSize, bufferUsage)
    {
        bufferData = malloc(byteSize);
    }

    OpenGLESUniformBuffer::OpenGLESUniformBuffer(Framework& framework, const void* data, const std::string& label,
        uint32_t byteSize, BufferUsage bufferUsage)
            : AUniformBuffer(framework, label, byteSize, bufferUsage)
    {
        bufferData = malloc(byteSize);
        std::memcpy(bufferData, data, byteSize);
    }

    void OpenGLESUniformBuffer::update(void *data, uint32_t byteSize)
    {
        std::memcpy(bufferData, data, byteSize);
    }

    std::string OpenGLESUniformBuffer::printInfo()
    {
        std::ostringstream oss;
        oss << "OpenGLESUniformBuffer INFO.\n";
        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: UniformBuffer\n";
        oss << "\t\tLabel: " << label << "\n";
        oss << "\t\tByte Size: " << byteSize << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    void OpenGLESUniformBuffer::destroy()
    {
        free(bufferData);
    }

    OpenGLESUniformBuffer* toOpenGLESUniformBuffer(AUniformBuffer* uniformBuffer) {
        return dynamic_cast<OpenGLESUniformBuffer*>(uniformBuffer);
    }

    std::shared_ptr<OpenGLESUniformBuffer> toOpenGLESUniformBuffer(const std::shared_ptr<AUniformBuffer> &uniformBuffer) {
        return std::dynamic_pointer_cast<OpenGLESUniformBuffer>(uniformBuffer);
    }
}
