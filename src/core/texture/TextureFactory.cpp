//
// Created by lukaa on 22.12.2024..
//

#include "Framework.h"
#include "sdl/texture/SDLTexture2D.h"

namespace mars {

    TextureFactory::TextureFactory(Framework &framework)
        : framework(framework) {
    }

    std::shared_ptr<Texture2D> TextureFactory::createTextureFromImageFile(std::string filePath, const TextureUsage usage, std::string label) {
        std::shared_ptr<ImageData> imageData = framework.getImageLoader().load(filePath);
        ImageData& data = *imageData;
        return std::make_shared<SDLTexture2D>(framework, data);
    }

}
