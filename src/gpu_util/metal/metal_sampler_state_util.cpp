//
// Created by Luka Erkapic on 07.06.25.
//

#if __APPLE__

#include "gpu_util/metal/metal_sampler_state_util.h"

namespace gpu_util {

    MTL::SamplerState* MetalSamplerStateUtil::create(
           MTL::Device* device,
           const MTL::SamplerMinMagFilter minFilter,
           const MTL::SamplerMinMagFilter magFilter,
           const MTL::SamplerAddressMode sAddressMode,
           const MTL::SamplerAddressMode tAddressMode
           ) {

        MTL::SamplerDescriptor *descriptor = MTL::SamplerDescriptor::alloc()->init();
        descriptor->setMinFilter(minFilter);
        descriptor->setMagFilter(magFilter);
        descriptor->setSAddressMode(sAddressMode);
        descriptor->setTAddressMode(tAddressMode);

        MTL::SamplerState *sampler = device->newSamplerState(descriptor);
        descriptor->release();
        return sampler;
    }
}

#endif 