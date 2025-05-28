//
// Created by Luka Erkapic on 19.05.25.
//

#if __APPLE__

#include "Framework.h"
#include "metal/buffers/metal_instance_buffer.h"
#include "metal/util/metal_util.h"

namespace mars {
    MetalInstanceBuffer::MetalInstanceBuffer(Framework &framework, std::string label)
      : framework(framework),
        renderer(dynamic_cast<MetalRenderer&>(framework.getRenderer())),
        logger(framework.getLogger()),
        usage(BufferUsage::Vertex),
        buffer(nullptr),
        label(std::move(label)) {
    }

    void MetalInstanceBuffer::initialize(const void *data, const uint32_t byteSize, const uint32_t strideInBytes,

        const uint32_t instanceCount) {
        this->instanceCount = instanceCount;
        this->byteSize = byteSize;
        this->byteStride = strideInBytes;

        buffer = MetalUtil::getBufferUtil().create(renderer.getDevice(), data, byteSize, label);
    }

    void MetalInstanceBuffer::destroy() {
        buffer->release();
    }

    MetalInstanceBuffer* toMetalInstanceBuffer(AInstanceBuffer* instanceBuffer) {
        return dynamic_cast<MetalInstanceBuffer*>(instanceBuffer);
    }

    std::shared_ptr<MetalInstanceBuffer> toMetalInstanceBuffer(const std::shared_ptr<AInstanceBuffer> &instanceBuffer) {
        return std::dynamic_pointer_cast<MetalInstanceBuffer>(instanceBuffer);
    }
}

#endif