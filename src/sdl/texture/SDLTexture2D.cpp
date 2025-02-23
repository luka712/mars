//
// Created by Erkapic Luka on 21.12.2024.
//

#include <stdexcept>
#include <Framework.h>
#include "sdl/texture/SDLTexture2D.h"
#include <sdl/renderer/SDLRenderer.h>
#include "core/data/SDLImageData.h"

namespace mars {
    SDLTexture2D::SDLTexture2D(Framework &framework, ImageData &imageData)
        : framework(framework), renderer(dynamic_cast<SDLRenderer &>(framework.getRenderer())) {

        // Check if the cast was successful and set properties.
        if (const auto *imageDataPtr = dynamic_cast<SDLImageData *>(&imageData); imageDataPtr != nullptr) {

            width = imageDataPtr->getWidth();
            height = imageDataPtr->getHeight();

            SDL_Surface *surface = imageDataPtr->getSurface();
            SDL_Renderer *sdlRenderer = this->renderer.getRenderer();
            texture = SDL_CreateTextureFromSurface(sdlRenderer, surface);
        } else {
            const std::string msg = "Failed to cast ImageData to SDLImageData.";
            framework.getLogger().error(msg.c_str());
            std::runtime_error error(msg);
        }
    }

    SDLTexture2D::~SDLTexture2D() {
        SDLTexture2D::destroy();
    }

    void SDLTexture2D::destroy() {
        SDL_DestroyTexture(texture);
    }

    std::string SDLTexture2D::printInfo() {
        return "";
    }

}
