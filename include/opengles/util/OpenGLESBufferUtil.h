//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESBUFFERUTIL_H
#define OPENGLESBUFFERUTIL_H

#include "opengles/opengles.h"
#include <string>
#include "core/log/Logger.h"

namespace mars {
    //! The OpenGLESBufferUtil class for working with OpenGLES buffers.
    class OpenGLESBufferUtil {
    public:
        //! Construct a new OpenGLESBufferUtil object.
        //! @param logger The logger.
        explicit OpenGLESBufferUtil(Logger &logger) : logger(logger) {
        }

        //! Create a new buffer.
        //! @param target The target of the buffer. (GL_ARRAY_BUFFER, GL_ELEMENT_ARRAY_BUFFER, ...)
        //! @param data The data to initialize the buffer with. If nullptr, creates empty buffer.
        //! @param byteSize The size of the buffer in bytes.
        //! @param label The label of the buffer.
        //! @param bufferHint The hint for the buffer. By default, GL_STATIC_DRAW.
        GLuint createBuffer(const GLenum target,
                            const void *data,
                            const uint32_t byteSize,
                            const std::string& label = "",
                            const GLenum bufferHint = GL_STATIC_DRAW) const;

        //! Write data to the buffer.
        //! @param buffer The buffer to write to.
        //! @param bufferTarget The target of the buffer.
        //! @param data The data to write.
        //! @param byteSize The size of the data in bytes.
        //! @param byteOffset The offset in the buffer. By default, <code>0</code>.
        void writeBuffer(const GLuint buffer,
                const GLenum bufferTarget,
                const void *data,
                const uint32_t byteSize,
                const uint32_t byteOffset = 0);

    private:
        Logger &logger;
    };
}


#endif //OPENGLESBUFFERUTIL_H
