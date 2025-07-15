//
// Created by Erkapic Luka on 21.12.2024.
//

#include "core/data/SDLImageData.h"

namespace mars {

    SDLImageData::SDLImageData(SDL_Surface *surface)
        : ImageData(surface->w, surface->h, static_cast<unsigned char *>(surface->pixels), 0) {
        this->surface = surface;
		this->channels = SDL_GetPixelFormatDetails(surface->format)->bytes_per_pixel;
    }

    uint32_t SDLImageData::getWidth() const {
        return surface->w;
    }

    uint32_t SDLImageData::getHeight() const {
        return surface->h;
    }

    const uint8_t *SDLImageData::getData() const {
        return static_cast<uint8_t *>(surface->pixels);
    }

    uint32_t SDLImageData::getChannels() const {
        return SDL_GetPixelFormatDetails(surface->format)->bytes_per_pixel;
    }

    void SDLImageData::destroy() {
        if (surface != nullptr) {
            SDL_DestroySurface(surface);
            surface = nullptr;
        }
    }
}
