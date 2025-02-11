//
// Created by lukaa on 22.12.2024..
//

#include "Framework.h"
#include "sdl/texture/SDLTexture2D.h"
#include "opengles/texture/OpenGLESTexture2D.h"

namespace mars
{
    TextureFactory::TextureFactory(Framework& framework)
        : framework(framework)
    {
    }

    std::shared_ptr<Texture2D> TextureFactory::createTextureFromImageFile(
        const std::string& filePath, const TextureUsage usage, const std::string& label) const
    {
        std::shared_ptr<ImageData> imageData = framework.getImageLoader().load(filePath);
        ImageData& data = *imageData;

        RenderingBackend backend = framework.getRenderingBackend();
        switch (backend)
        {
        case RenderingBackend::SDL:
            return std::make_shared<SDLTexture2D>(framework, data);
        case RenderingBackend::OpenGLES:
            return std::make_shared<OpenGLESTexture2D>(framework, data);
        default:
            std::string msg = "TextureFactory::createTextureFromImageFile: Rendering backend not supported.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }
}
