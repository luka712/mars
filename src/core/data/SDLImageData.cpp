//
// Created by lukaa on 21.12.2024..
//

#include "core/data/SDLImageData.h"

namespace mars {

    SDLImageData::SDLImageData(SDL_Surface *surface)
        : ImageData(surface->w, surface->h, static_cast<unsigned char *>(surface->pixels), surface->format->BytesPerPixel) {
        this->surface = surface;
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
        return surface->format->BytesPerPixel;
    }

    void SDLImageData::destroy() {
        SDL_FreeSurface(surface);
    }
}
