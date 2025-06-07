//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_UTIL_H
#define METAL_UTIL_H

#if __APPLE__

#include "metal/util/metal_buffer_util.h"
#include "metal/util/metal_converter.h"
#include "metal/util/metal_texture_util.h"
#include "util/metal/metal_sampler_state_util.h"

namespace mars {
    static MetalConverter *metalConverter = nullptr;
    static MetalBufferUtil *metalBufferUtil = nullptr;
    static MetalTextureUtil *metalTextureUtil = nullptr;
    static gpu_util::MetalSamplerStateUtil metalSamplerStateUtil;

    class MetalUtil {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            metalConverter = new MetalConverter(logger);
            metalBufferUtil = new MetalBufferUtil(logger);
            metalTextureUtil = new MetalTextureUtil(logger);
        }

        //! Gets the MetalConverter. Used to convert framework formats to Metal formats.
        //! @return The MetalConverter pointer.
        static MetalConverter &getMetalConverter() { return *metalConverter; }

        //! Gets the MetalBufferUtil for working with buffers.
        //! @return The MetalBufferUtil ptr.
        static MetalBufferUtil &getBuffer() { return *metalBufferUtil; }

        //! Gets the MetalTextureUtil for working with textures.
        //! @return Tee MetalTextureUtil ptr.
        static MetalTextureUtil &getTexture() { return *metalTextureUtil; }

        //! Gets the MetalSamplerStateUtil for working with sampler state.
        //! @return The MetalSamplerStateUtil reference.
        static gpu_util::MetalSamplerStateUtil &getSamplerState() { return metalSamplerStateUtil; }
    };
}

#endif

#endif //METAL_UTIL_H
