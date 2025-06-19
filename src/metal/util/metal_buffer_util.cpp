//
// Created by Luka Erkapic on 11.05.25.
//

#if __APPLE__

#include "metal/util/metal_buffer_util.h"

#include <memory>

namespace mars {

    MTL::Buffer *MetalBufferUtil::create(
        MTL::Device *device,
        const void *data,
        const uint32_t byteSize,
        const std::string &label,
        const MTL::ResourceOptions resourceOptions
        ) {

        // Create autorelease pool
        NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();

        MTL::Buffer* buffer = device->newBuffer(data, byteSize, resourceOptions);

        if (buffer == nullptr) {
            const std::string msg = "MetalBufferUtil::create: Failed to create buffer.";
            logger.error(msg);
            pool->release();
            throw std::runtime_error(msg);
        }

        const NS::String *nsLabel = NS::String::string(label.c_str(), NS::StringEncoding::UTF8StringEncoding);
        buffer->setLabel(nsLabel);

        pool->release();

        return buffer;
    }

    MTL::Buffer *MetalBufferUtil::create(
       MTL::Device *device,
       MTL::CommandQueue *queue,
       const void *data,
       const uint32_t byteSize,
       const std::string &label,
       const MTL::ResourceOptions resourceOptions,
       bool waitForCopyToFinish
       ) {

        // Create autorelease pool
        NS::AutoreleasePool* pool = NS::AutoreleasePool::alloc()->init();

        // Can be written to from CPU and GPU.
        MTL::Buffer* stagingBuffer = device->newBuffer(data, byteSize, MTL::ResourceStorageModeShared);

        if (stagingBuffer == nullptr) {
            const std::string msg = "MetalBufferUtil::create: Failed to create buffer.";
            logger.error(msg);
            pool->release();
            throw std::runtime_error(msg);
        }

        // Destination buffer.
        MTL::Buffer *buffer = device->newBuffer(byteSize, resourceOptions);

        if (buffer == nullptr) {
            const std::string msg = "MetalBufferUtil::create: Failed to create buffer.";
            logger.error(msg);
            pool->release();
            throw std::runtime_error(msg);
        }

        const NS::String *nsLabel = NS::String::string(label.c_str(), NS::StringEncoding::UTF8StringEncoding);
        stagingBuffer->setLabel(nsLabel);

        // Copy data from staging buffer to the destination buffer. Start by creating command buffer.
        MTL::CommandBuffer* commandBuffer = queue->commandBuffer();

        // Create blit command encoder and encode copy command
        MTL::BlitCommandEncoder* blitEncoder = commandBuffer->blitCommandEncoder();
        blitEncoder->copyFromBuffer(stagingBuffer, 0, buffer, 0, byteSize);
        blitEncoder->endEncoding();

        // Commit and wait for completion
        commandBuffer->commit();

        commandBuffer->waitUntilCompleted();

        pool->release();

        return buffer;
    }

    void MetalBufferUtil::updateSharedBuffer(MTL::Buffer *buffer, void* data, const uint32_t byteSize) {
        memcpy(buffer->contents(), data, byteSize);
    }
}

#endif
