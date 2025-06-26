//
// Created by Luka Erkapic on 07.06.25.
//

#if __APPLE__

#include "gpu_util/metal/metal_texture_utility.h"

namespace gpu_util {

    MTL::Texture* MetalTextureUtility::create(
        MTL::Device* device,
        NS::UInteger width,
        NS::UInteger height,
        MTL::TextureUsage textureUsage,
        MTL::PixelFormat pixelFormat,
        const void* data,
        const std::string& label) {

        MTL::TextureDescriptor *textureDescriptor = MTL::TextureDescriptor::alloc()->init();
        textureDescriptor->setTextureType(MTL::TextureType2D);
        textureDescriptor->setPixelFormat(pixelFormat);
        textureDescriptor->setWidth(width);
        textureDescriptor->setHeight(height);
        textureDescriptor->setStorageMode(MTL::StorageModeManaged);
        textureDescriptor->setUsage(textureUsage);

        MTL::Texture *texture = device->newTexture(textureDescriptor);
        const NS::String *nsLabel = NS::String::string(label.c_str(), NS::StringEncoding::UTF8StringEncoding);
        texture->setLabel(nsLabel);

        // Copy to the texture.
        MTL::Region region;
        region.origin = {0, 0, 0};
        region.size = {width, height, 1};

        // bytes per row
        NS::Integer bytesPerRow = 4 * width;

        texture->replaceRegion(region, 0, data, bytesPerRow);

        return texture;
    }
}

#endif
