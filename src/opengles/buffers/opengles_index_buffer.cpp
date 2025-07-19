//
// Created by Erkapic Luka on 18.1.2025.
//

#include <sstream>
#include "Framework.h"
#include "opengles/buffers/opengles_index_buffer.h"
#include "gpu_util/opengles/opengles_util.h"

using namespace gpu_util;

namespace mars {
    OpenGLESIndexBuffer::OpenGLESIndexBuffer(const Framework &framework, const std::string &label)
        : AIndexBuffer(label),
          renderer(dynamic_cast<OpenGLESRenderer &>(framework.getRenderer())),
          logger(framework.getLogger()), buffer(0) {
    }

    void OpenGLESIndexBuffer::initialize(const std::vector<uint16_t>& data) {
        type = IndexBufferType::Uint16;
        indicesCount = data.size();
        byteSize = indicesCount * sizeof(uint16_t);

        buffer = OpenGLESUtil::getBuffer()->createBuffer(
            GL_ELEMENT_ARRAY_BUFFER,
            data.data(),
            byteSize,
            label,
            GL_STATIC_DRAW
        );
    }

    void OpenGLESIndexBuffer::initialize(const std::vector<uint32_t>& data) {
        type = IndexBufferType::Uint32;
        indicesCount = data.size();
        byteSize = indicesCount * sizeof(uint32_t);

        buffer = OpenGLESUtil::getBuffer()->createBuffer(
            GL_ELEMENT_ARRAY_BUFFER,
            data.data(),
            byteSize,
            label,
            GL_STATIC_DRAW
        );
    }

    std::string OpenGLESIndexBuffer::printInfo() {
        std::ostringstream oss;
        oss << "OpenGLESIndexBuffer INFO.\n";
        oss << "\tOpenGLES DATA:\n";
        oss << "\t\tLabel: " << label << ",\n";
        oss << "\t\tTarget: GL_ELEMENT_ARRAY_BUFFER\n";
        oss << "\t\tHint: GL_STATIC_DRAW\n";

        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: IndexBuffer\n";
        //  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
        oss << "\t\tIndices Count: " << indicesCount << "\n";
        oss << "\t\tByte Size: " << byteSize << "\n";
        oss << "\t\tElement Size: " << getElementByteSize() << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    void OpenGLESIndexBuffer::destroy()  {
        glDeleteBuffers(1, &buffer);
    }

    OpenGLESIndexBuffer* toOpenGLESIndexBuffer(AIndexBuffer* indexBuffer) {
        return dynamic_cast<OpenGLESIndexBuffer *>(indexBuffer);
    }
}
