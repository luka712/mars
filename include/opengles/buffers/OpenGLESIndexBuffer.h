//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESINDEXBUFFER_H
#define OPENGLESINDEXBUFFER_H

#include "opengles/opengles.h"
#include "core/buffers/AIndexBuffer.h"

namespace mars {
    class Framework;

    class OpenGLESIndexBuffer : public AIndexBuffer {
    public:
        //! Construct a new OpenGLESIndexBuffer object.
        //! @param framework The framework.
        //! @param label The label of the buffer.
        OpenGLESIndexBuffer(const Framework& framework, const std::string &label);

        void initialize(const std::vector<uint16_t>& data) override;

        void initialize(const std::vector<uint32_t>& data) override;

        std::string printInfo() override;

        void destroy() override;

    private:
        OpenGLESRenderer& renderer;
        Logger& logger;
        GLuint buffer;
    };
}


#endif //OPENGLESINDEXBUFFER_H
