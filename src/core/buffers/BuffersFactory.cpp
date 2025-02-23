//
// Created by lukaa on 18.1.2025..
//

#include <stdexcept>
#include "Framework.h"
#include "core/buffers/BuffersFactory.h"
#include "opengles/buffers/OpenGLESIndexBuffer.h"
#include "opengles/buffers/OpenGLESUniformBuffer.h"
#include "opengles/buffers/OpenGLESVertexBuffer.h"

namespace mars {
    BuffersFactory::BuffersFactory(Framework &framework) : framework(framework) {
    }

    std::shared_ptr<AVertexBuffer> BuffersFactory::createVertexBuffer(
        const std::vector<float>& data,
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
                throw std::runtime_error("BuffersFactory::createVertexBuffer: Rendering backend not supported.");
        }
        const float *dataPtr = data.data();
        uint32_t byteSize = data.size() * sizeof(float);
        buffer->initialize(dataPtr, byteSize, vertexCount, usage);

        return std::shared_ptr<AVertexBuffer>(buffer);
    }

    std::shared_ptr<AIndexBuffer> BuffersFactory::createIndexBuffer(const std::vector<uint16_t>& data,  const std::string& label) {

        AIndexBuffer *buffer = nullptr;
        RenderingBackend renderingBackend = framework.getRenderingBackend();

        switch (renderingBackend) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESIndexBuffer(framework, label);
            break;
            default:
                throw std::runtime_error("BuffersFactory::createindexBuffer: Rendering backend not supported.");
        }
        buffer->initialize(data);

        return std::shared_ptr<AIndexBuffer>(buffer);
    }

    std::shared_ptr<AUniformBuffer> BuffersFactory::createUniformBuffer(void* data, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage)
    {
        AUniformBuffer *buffer = nullptr;
        RenderingBackend renderingBackend = framework.getRenderingBackend();

        switch (renderingBackend)
        {
        case RenderingBackend::OpenGLES:
            buffer = new OpenGLESUniformBuffer(framework, data, label, byteSize, bufferUsage);
            break;
        default:
            throw std::runtime_error("BuffersFactory::createUniformBuffer: Rendering backend not supported.");
        }

        return std::shared_ptr<AUniformBuffer>(buffer);
    }


}
