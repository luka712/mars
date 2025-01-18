//
// Created by lukaa on 18.1.2025..
//

#include "Framework.h"
#include "core/buffers/BuffersFactory.h"

#include "opengles/buffers/OpenGLESIndexBuffer.h"
#include "opengles/buffers/OpenGLESVertexBuffer.h"

namespace mars {
    BuffersFactory::BuffersFactory(Framework &framework) : framework(framework) {
    }

    std::shared_ptr<AVertexBuffer> BuffersFactory::createVertexBuffer(
        std::vector<float> data,
        uint32_t vertexCount,
        BufferUsage usage,
        const std::string& label) const {

        AVertexBuffer *buffer = nullptr;
        RenderingBackend renderingBackend = framework.getRenderingBackend();

        switch (renderingBackend) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESVertexBuffer(framework, label);
                break;
            default:
                throw std::runtime_error("Rendering backend not supported.");
        }
        void *dataPtr = data.data();
        uint32_t byteSize = data.size() * sizeof(float);
        buffer->initialize(dataPtr, byteSize, vertexCount, usage);

        return std::shared_ptr<AVertexBuffer>(buffer);
    }

    std::shared_ptr<AIndexBuffer> BuffersFactory::createindexBuffer(std::vector<uint16_t> data,  const std::string& label) {

        AIndexBuffer *buffer = nullptr;
        RenderingBackend renderingBackend = framework.getRenderingBackend();

        switch (renderingBackend) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESIndexBuffer(framework, label);
            break;
            default:
                throw std::runtime_error("Rendering backend not supported.");
        }
        buffer->initialize(data);

        return std::shared_ptr<AIndexBuffer>(buffer);
    }
}
