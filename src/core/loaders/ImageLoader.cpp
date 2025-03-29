//
// Created by lukaa on 21.12.2024..
//

#include <SDL_image.h>
#include <filesystem>
#include "core/loaders/ImageLoader.h"

#include <Framework.h>

#include "core/data/SDLImageData.h"

namespace mars {
    ImageLoader::ImageLoader(Framework &framework)
        : framework(framework){
    }

    std::shared_ptr<ImageData> ImageLoader::load(const std::string &path, const bool cache) {

        // Check if image is already in cache.
        if (cache) {
            if (permanentCache.contains(path)) {
                return  permanentCache[path];
            }
        }
        else {
            if (tempCache.contains(path)) {
                return tempCache[path];
            }
        }

        // Check if file exists.
        if (!std::filesystem::exists(path)) {
            const std::string msg = "File under path \"" + path + "\" does not exist.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        SDL_Surface* surface = IMG_Load(path.c_str());
        if (!surface) {
            const std::string msg = "Failed to load image from path: \"" + path + "\". Error: " + IMG_GetError();
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        // We must ensure that the image is in RGBA format.
        if (surface->format->BytesPerPixel != 4) {
            const std::string msg = "Image under path \"" + path + "\" is not in RGBA format.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }

        std::shared_ptr<ImageData> imageData = std::make_shared<SDLImageData>(surface);

        if (cache) {
            permanentCache[path] = imageData;
        }
        else {
            tempCache[path] = imageData;
        }

        return imageData;
    }

    void ImageLoader::disposeOfTemporaryCache() {
        tempCache.clear();
    }


}
