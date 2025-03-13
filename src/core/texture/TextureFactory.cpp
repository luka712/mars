//
// Created by Erkapic Luka on 22.12.2024.
//

#include <stdexcept>
#include "Framework.h"
#include "sdl/texture/SDLTexture2D.h"
#include "opengles/texture/OpenGLESTexture2D.h"

namespace mars {
    TextureFactory::TextureFactory(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<Texture2D> TextureFactory::createTextureFromImageFile(
        const std::string &filePath, const TextureUsage usage, const std::string &label) const {
        std::shared_ptr<ImageData> imageData = framework.getImageLoader().load(filePath);
        ImageData &data = *imageData;

        RenderingBackend backend = framework.getRenderingBackend();
        switch (backend) {
            case RenderingBackend::SDL:
                return std::make_shared<SDLTexture2D>(framework, data);
            case RenderingBackend::OpenGLES:
                return std::make_shared<OpenGLESTexture2D>(framework, data);
            default:
                const std::string msg = "TextureFactory::createTextureFromImageFile: Rendering backend not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }
    }

    std::shared_ptr<Texture2D> TextureFactory::createEmpty(
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
            default:
                const std::string msg = "TextureFactory::createTextureFromImageFile: Rendering backend not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }
    }
}
