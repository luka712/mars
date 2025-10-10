//
// Created by Erkapic Luka on 22.12.2024.
//

#include <stdexcept>
#include "Framework.h"
#include "metal/texture/metal_texture2d.h"
#include "sdl/texture/SDLTexture2D.h"
#include "opengles/texture/opengles_texture2d.h"

#if __APPLE__
#include "metal/texture/metal_texture2d.h"
#endif

#if _WIN32
#include "dx11/texture/dx11_texture2d.h"
#endif 

namespace mars {
    TextureFactory::TextureFactory(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<ATexture2D> TextureFactory::createTextureFromImageFile(
        const std::string &filePath, const TextureUsage usage, const std::string &label) const {
        const std::shared_ptr<ImageData> imageData = framework.getImageLoader().load(filePath);
        ImageData &data = *imageData;

        RenderingBackend backend = framework.getRenderingBackend();
        switch (backend) {
            case RenderingBackend::SDL:
                return std::make_shared<SDLTexture2D>(framework, data);
            case RenderingBackend::OpenGLES:
                return std::make_shared<OpenGLESTexture2D>(framework, data);
#if __APPLE__
            case RenderingBackend::Metal:
                return std::make_shared<MetalTexture2D>(framework, data);
#endif
#if _WIN32
            case RenderingBackend::D3D11:
                return std::make_shared<DX11Texture2D>(&framework, &data);

#endif 
            default:
                const std::string msg = "TextureFactory::createTextureFromImageFile: Rendering backend not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }
    }

    std::shared_ptr<ATexture2D> TextureFactory::createEmpty(
        const uint32_t width,
        const uint32_t height,
        const Color defaultColor,
        const TextureUsage usage,
        const std::string &label) const {
        // Create data for image.
        auto *data = new uint8_t[width * height * 4];
        for (size_t i = 0; i < width * height * 4; i += 4) {
            data[i] = static_cast<uint8_t>(defaultColor.r * 255);
            data[i + 1] = static_cast<uint8_t>(defaultColor.g * 255);
            data[i + 2] = static_cast<uint8_t>(defaultColor.b * 255);
            data[i + 3] = static_cast<uint8_t>(defaultColor.a * 255);
        }
        // Create image data.
        auto imageData = ImageData(width, height, data, 4);

        switch (framework.getRenderingBackend()) {
            case RenderingBackend::SDL:
                return std::make_shared<SDLTexture2D>(framework, imageData);
            case RenderingBackend::OpenGLES:
                return std::make_shared<OpenGLESTexture2D>(framework, imageData, label);
#if __APPLE__
            case RenderingBackend::Metal:
                return std::make_shared<MetalTexture2D>(framework, imageData, label);
#endif 
#if _WIN32
                case RenderingBackend::D3D11:
					return std::make_shared<DX11Texture2D>(&framework, &imageData, label);
#endif
            default:
                const std::string msg = "TextureFactory::createTextureFromImageFile: Rendering backend not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }
    }
}
