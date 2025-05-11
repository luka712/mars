//
// Created by Luka Erkapic on 11.05.25.
//

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


}
