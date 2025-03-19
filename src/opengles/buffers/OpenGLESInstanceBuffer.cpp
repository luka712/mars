//
// Created by Erkapic Luka on 18.3.2025.
//

#include <utility>

#include "Framework.h"
#include "opengles/buffers/OpenGLESInstanceBuffer.h"
#include "opengles/util/OpenGLESUtil.h"

namespace  mars {
    OpenGLESInstanceBuffer::OpenGLESInstanceBuffer(Framework &framework, std::string label)
        : framework(framework), label(std::move(label)) {
    }

    void OpenGLESInstanceBuffer::initialize(const void *data, const uint32_t byteSize, const uint32_t strideInBytes,
        const uint32_t instanceCount) {
        this->instanceCount = instanceCount;
        this->byteSize = byteSize;
        this->byteStride = strideInBytes;

        buffer = OpenGLESUtil::getBuffer()->createBuffer(GL_ARRAY_BUFFER, data, byteSize, label);
    }

    void OpenGLESInstanceBuffer::destroy() {
        glDeleteBuffers(1, &buffer);
    }


    OpenGLESInstanceBuffer* toOpenGLESInstanceBuffer(AInstanceBuffer* instanceBuffer) {
        return dynamic_cast<OpenGLESInstanceBuffer*>(instanceBuffer);
    }

    std::shared_ptr<OpenGLESInstanceBuffer> toOpenGLESInstanceBuffer(const std::shared_ptr<AInstanceBuffer> &instanceBuffer) {
        return std::dynamic_pointer_cast<OpenGLESInstanceBuffer>(instanceBuffer);
    }

}
