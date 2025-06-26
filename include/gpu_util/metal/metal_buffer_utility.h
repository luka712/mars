//
// Created by Luka Erkapic on 11.05.25.
//

#if __APPLE__

#ifndef METAL_BUFFER_UTIL_H
#define METAL_BUFFER_UTIL_H

#include "metal/metal.h"
#include "gpu_util/logger.h"

namespace gpu_util {
    //! The utility class for working with MTL::Buffer.
    class MetalBufferUtility {
    public:
        //! Construct a new MetalBufferUtil object.
        //! @param logger The logger.
        explicit MetalBufferUtility(Logger &logger) : logger(logger) {
        }

        //! Create a new Metal buffer. Use this overload only if creating buffers that can be written to from CPU.
        //! In most scenarios that means using <code>MTL::ResourceStorageModeShared</code>.
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

        //! Create a new Metal buffer.
        //! <h3>Implementation notes</h3>
        //! Creates temporary buffer to shared(CPU/GPU) buffer to copy data from to whatever destination is.
        //! @param device The metal device.
        //! @param queue The metal queue.
        //! @param data The pointer to the data.
        //! @param byteSize The size of buffer in bytes.
        //! @param label The optional label for Metal resource.
        //! @param resourceOptions The resource options. For more @see https://developer.apple.com/documentation/metal/mtlresourceoptions?language=objc
        //! @param waitForCopyToFinish Wait for copy operation to finish. By default, it is <code>false</code>.
        MTL::Buffer *create(MTL::Device *device,
                            MTL::CommandQueue *queue,
                            const void *data,
                            const uint32_t byteSize,
                            const std::string &label = "",
                            const MTL::ResourceOptions resourceOptions = MTL::ResourceStorageModeShared,
                            bool waitForCopyToFinish = false
        );

        //! Update the buffer which is created as shared buffer with MTL::ResourceStorageModeShared.
        //! @param buffer The buffer to update.
        //! @param data The data of buffer.
        //! @param byteSize The size of buffer in bytes.
        void updateSharedBuffer(MTL::Buffer *buffer, void* data, const uint32_t byteSize);

    private:
        Logger &logger;
    };
}

#endif //METAL_BUFFER_UTIL_H

#endif