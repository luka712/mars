//
// Created by Luka Erkapic on 07.06.25.
//

#ifndef METAL_SAMPLER_UTIL_H
#define METAL_SAMPLER_UTIL_H

#include "gpu_util/metal.h"

namespace gpu_util {

    //! The utility class for working with Metal SamplerState.
    class MetalSamplerStateUtil {
    public:
        //! Create a new Metal SamplerState
        MTL::SamplerState* create(
            MTL::Device* device,
            const MTL::SamplerMinMagFilter minFilter = MTL::SamplerMinMagFilterLinear,
            const MTL::SamplerMinMagFilter magFilter = MTL::SamplerMinMagFilterLinear,
            const MTL::SamplerAddressMode sAddressMode = MTL::SamplerAddressModeRepeat,
            const MTL::SamplerAddressMode tAddressMode = MTL::SamplerAddressModeRepeat);
    };

}

#endif //METAL_SAMPLER_UTIL_H
