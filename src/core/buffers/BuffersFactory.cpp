//
// Created by Erkapic Luka on 18.1.2025.
//

#include <stdexcept>
#include "Framework.h"
#include "core/buffers/BuffersFactory.h"
#include "opengles/buffers/OpenGLESIndexBuffer.h"
#include "opengles/buffers/OpenGLESInstanceBuffer.h"
#include "opengles/buffers/OpenGLESUniformBuffer.h"
#include "opengles/buffers/OpenGLESVertexBuffer.h"

#if __APPLE__
#include "metal/buffers/metal_vertex_buffer.h"
#endif

namespace mars {
    BuffersFactory::BuffersFactory(Framework &framework) : framework(framework) {
    }

    std::shared_ptr<AVertexBuffer> BuffersFactory::createVertexBuffer(
        const std::vector<float> &data,
        const uint32_t vertexCount,
        const BufferUsage usage,
        const std::string &label) const {
        AVertexBuffer *buffer = nullptr;

        switch (framework.getRenderingBackend()) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESVertexBuffer(framework, label);
                break;
#if __APPLE__
            case RenderingBackend::Metal:
                buffer = new MetalVertexBuffer(framework, label);
                break;
#endif
            default:
                throw std::runtime_error("BuffersFactory::createVertexBuffer: Rendering backend not supported.");
        }
        const float *dataPtr = data.data();
        const uint32_t byteSize = data.size() * sizeof(float);
        buffer->initialize(dataPtr, byteSize, vertexCount, usage);

        return std::shared_ptr<AVertexBuffer>(buffer);
    }

    std::shared_ptr<AIndexBuffer> BuffersFactory::createIndexBuffer(const std::vector<uint16_t> &data,
                                                                    const std::string &label) const {
        AIndexBuffer *buffer = nullptr;

        switch (framework.getRenderingBackend()) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESIndexBuffer(framework, label);
                break;
            default:
                throw std::runtime_error("BuffersFactory::createindexBuffer: Rendering backend not supported.");
        }
        buffer->initialize(data);

        return std::shared_ptr<AIndexBuffer>(buffer);
    }

    std::shared_ptr<AUniformBuffer> BuffersFactory::createUniformBuffer(
        void *data,
        const std::string &label,
        const uint32_t byteSize,
        const BufferUsage bufferUsage) const {

        AUniformBuffer *buffer = nullptr;

        switch ( framework.getRenderingBackend()) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESUniformBuffer(framework, data, label, byteSize, bufferUsage);
                break;
            default:
                throw std::runtime_error("BuffersFactory::createUniformBuffer: Rendering backend not supported.");
        }

        return std::shared_ptr<AUniformBuffer>(buffer);
    }

    std::shared_ptr<AInstanceBuffer> BuffersFactory::createInstanceBuffer(
        const void *data,
        const uint32_t byteSize,
        const uint32_t strideInBytes,
        const uint32_t instanceCount,
        const std::string &label) const {
        AInstanceBuffer *buffer = nullptr;

        switch (framework.getRenderingBackend()) {
            case RenderingBackend::OpenGLES:
                buffer = new OpenGLESInstanceBuffer(framework, label);
                break;
            default:
                const std::string msg = "BuffersFactory::createInstanceBuffer: Rendering backend not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }

        buffer->initialize(data, byteSize, strideInBytes, instanceCount);
        return std::shared_ptr<AInstanceBuffer>(buffer);
    }
}
