//
// Created by Luka Erkapic on 07.06.25.
//

#if __APPLE__

#include <sstream>
#include "Framework.h"
#include "metal/texture/metal_texture2d.h"
#include "gpu_util/metal/metal_utility.h"

namespace mars {

    MetalTexture2D::MetalTexture2D(Framework& framework, const ImageData& imageData, const std::string& label)
          : framework(framework),
            logger(framework.getLogger()),
            renderer(dynamic_cast<MetalRenderer &>(framework.getRenderer()))
    {
        this->label = label;
        this->width = imageData.getWidth();
        this->height = imageData.getHeight();

        // TEXTURE
        texture = gpu_util::MetalUtility::getTexture().create(
            renderer.getDevice(),
            NS::UInteger(width),
            NS::UInteger(height),
            MTL::TextureUsageShaderRead,
            PixelFormat::PixelFormatRGBA8Uint,
            imageData.getData(),
            label
        );

        // SAMPLER
        sampler = gpu_util::MetalUtility::getSamplerState().create(renderer.getDevice());
    }

    void MetalTexture2D::destroy()
    {
        sampler->release();
        texture->release();
    }

    std::string MetalTexture2D::printInfo() {
        std::ostringstream oss;
        oss << "OpenGLESTexture2D INFO.\n";
        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: Texture2D\n";
        oss << "\t\tLabel: " << label << "\n";
        // oss << "\t\tByte Size: " << byteSize << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    MetalTexture2D *asMetalTexture(Texture2D *texture) {
        return dynamic_cast<MetalTexture2D*>(texture);
    }
}

#endif
