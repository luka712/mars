//
// Created by Luka Erkapic on 07.06.25.
//
#pragma once

#ifndef METAL_TEXTURE_UTIL_H
#define METAL_TEXTURE_UTIL_H

#if __APPLE__

#include <string>
#include "metal/metal.h"
#include "util/logger.h"

namespace gpu_util {

    //! The utility class for working with Metal textures.
    class MetalTextureUtility {
    public:
        //! Construct a new MetalBufferUtil object.
        //! @param logger The logger.
        explicit MetalTextureUtility(Logger &logger) : logger(logger) {
        }

        //! Create a new texture.
        //! @param device The device.
        //! @param width The width of the texture.
        //! @param height The height of the texture.
        //! @param textureUsage The usage of the texture.
        //! @param pixelFormat The pixel format of the texture.
        //! @param data The data to initialize the texture with.
        //! @param label The label of the texture. By default, empty string.
        //! @return The texture.
        MTL::Texture* create(
            MTL::Device* device,
            NS::UInteger width,
            NS::UInteger height,
            MTL::TextureUsage textureUsage,
            MTL::PixelFormat pixelFormat,
            const void* data,
            const std::string& label = "");

    private:
        Logger& logger;
    };
}

#endif //METAL_TEXTURE_UTIL_H

#endif
