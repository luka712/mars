//
// Created by lukaa on 18.1.2025..
//

#include "opengles/util/OpenGLESBufferUtil.h"

namespace mars {
    GLuint OpenGLESBufferUtil::createBuffer(const GLenum target,
                              const void *data,
                              const uint32_t byteSize,
                              const std::string& label,
                              const GLenum bufferHint) const {
        GLuint buffer = 0;
        glGenBuffers(1, &buffer);
        if (buffer == 0) {
            const std::string msg = "Failed to create OpenGLES buffer.";
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        glBindBuffer(target, buffer);
        glBufferData(target, byteSize, data, bufferHint);

        if (!label.empty()) {
            glObjectLabel(GL_BUFFER, buffer, label.size(), label.c_str());
        }

        return buffer;
    }

    void OpenGLESBufferUtil::writeBuffer(const GLuint buffer,
                const GLenum bufferTarget,
                const void *data,
                const uint32_t byteSize,
                const uint32_t byteOffset) {
        glBindBuffer(bufferTarget, buffer);
        glBufferSubData(bufferTarget, byteOffset, byteSize, data);
    }
}