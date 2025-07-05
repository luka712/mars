//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESINDEXBUFFER_H
#define OPENGLESINDEXBUFFER_H

#include "opengles/renderer/opengles_renderer.h"
#include "opengles/opengles.h"
#include "core/buffers/AIndexBuffer.h"

namespace mars {
    class Framework;

    //! The OpenGLES implementation of the index buffer.
    class OpenGLESIndexBuffer : public AIndexBuffer {
    public:
        //! Construct a new OpenGLESIndexBuffer object.
        //! @param framework The framework.
        //! @param label The label of the buffer.
        OpenGLESIndexBuffer(const Framework& framework, const std::string &label);

        //! Gets the underlying buffer.
        //! @returns The OpenGLES buffer.
        [[nodiscard]] GLuint getBuffer() const { return buffer; }

        void initialize(const std::vector<uint16_t>& data) override;

        void initialize(const std::vector<uint32_t>& data) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        OpenGLESRenderer& renderer;
        Logger& logger;
        GLuint buffer;
    };

    //! Converts the @ref AIndexBuffer to @ref OpenGLESIndexBuffer.
    //! @param indexBuffer The index buffer.
    //! @returns The @ref OpenGLESIndexBuffer.
    OpenGLESIndexBuffer* toOpenGLESIndexBuffer(AIndexBuffer* indexBuffer);
}


#endif //OPENGLESINDEXBUFFER_H
