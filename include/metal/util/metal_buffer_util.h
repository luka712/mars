//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_BUFFER_UTIL_H
#define METAL_BUFFER_UTIL_H

#include "core/log/Logger.h"
#include "metal/metal.h"

namespace mars {
    class MetalBufferUtil {
    public:
        //! Construct a new MetalBufferUtil object.
        //! @param logger The logger.
        explicit MetalBufferUtil(Logger &logger) : logger(logger) {
        }

        //! Create a new Metal buffer.
        //! @param device The metal device.
        //! @param data The pointer to the data.
        //! @param byteSize The size of buffer in bytes.
        //! @param label The optional label for Metal resource.
        //! @param resourceOptions The resource options. For more @see https://developer.apple.com/documentation/metal/mtlresourceoptions?language=objc
        MTL::Buffer *create(MTL::Device *device,
                            const void *data,
                            const uint32_t byteSize,
                            const std::string &label = "",
                            const MTL::ResourceOptions resourceOptions = MTL::ResourceStorageModeShared
        );

    private:
        Logger &logger;
    };
}

#endif //METAL_BUFFER_UTIL_H
