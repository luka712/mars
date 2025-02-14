//
// Created by luka erkapic on 18.1.2025.
//

#include <sstream>
#include "opengles/buffers/OpenGLESVertexBuffer.h"


namespace mars {
    OpenGLESVertexBuffer::OpenGLESVertexBuffer(const Framework &framework, const std::string &label)
        : AVertexBuffer(label),
          renderer(dynamic_cast<OpenGLESRenderer &>(framework.getRenderer())),
          logger(framework.getLogger()){
    }

    void OpenGLESVertexBuffer::initialize(void *data, const uint32_t byteSize, const uint32_t vertexCount,
                                          const BufferUsage usage) {
        this->byteSize = byteSize;
        this->vertexCount = vertexCount;
        glHint = OpenGLESUtil::getConverter()->convertToGLHint(usage);
        buffer = OpenGLESUtil::getBuffer()->createBuffer(
            glTarget,
            data,
            byteSize,
            label,
            glHint
        );
    }

    void OpenGLESVertexBuffer::initialize(const uint32_t byteSize, const uint32_t vertexCount) {
        glHint = GL_DYNAMIC_DRAW;
        this->byteSize = byteSize;
        this->vertexCount = vertexCount;
        buffer = OpenGLESUtil::getBuffer()->createBuffer(
            glTarget,
            nullptr,
            byteSize,
            label,
            glHint
        );
    }

    void OpenGLESVertexBuffer::update(void *data, const uint32_t byteSize, const uint32_t offset) {
        OpenGLESUtil::getBuffer()->writeBuffer(buffer, GL_VERTEX_ARRAY, data, byteSize, offset);
    }

    std::string OpenGLESVertexBuffer::printInfo() {

        std::string hint;
        switch (glHint) {
            case GL_STATIC_DRAW:
                hint = "GL_STATIC_DRAW";
            break;
            case GL_DYNAMIC_DRAW:
                hint = "GL_DYNAMIC_DRAW";
            break;
            case GL_STREAM_DRAW:
                hint = "GL_STREAM_DRAW";
            break;
            default:
                throw std::runtime_error("Unknown buffer hint.");
        }


        std::ostringstream oss;
        oss << "OpenGLESVertexBuffer INFO.\n";
        oss << "\tOpenGLES DATA:\n";
        oss << "\t\tLabel: " << label << ",\n";
        oss << "\t\tTarget: GL_ARRAY_BUFFER\n";
        oss << "\t\tHint: " << hint << "\n";

        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: VertexBuffer\n";
       //  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
        oss << "\t\tVertex Count: " << vertexCount << "\n";
        oss << "\t\tByte Size: " << byteSize << "\n";
        oss << "\t\tByte Stride: " << byteStride << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    void OpenGLESVertexBuffer::destroy()  {
        glDeleteBuffers(1, &buffer);
    }

    OpenGLESVertexBuffer* toOpenGLESVertexBuffer(AVertexBuffer* vertexBuffer) {
        return dynamic_cast<OpenGLESVertexBuffer *>(vertexBuffer);
    }
}
