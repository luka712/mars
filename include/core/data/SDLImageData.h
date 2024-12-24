//
// Created by lukaa on 21.12.2024..
//

#ifndef SDLIMAGEDATA_H
#define SDLIMAGEDATA_H

#include <SDL_image.h>
#include "core/data/ImageData.h"

namespace mars {
    //! The implementation of the ImageData which wraps the SDL_Surface.
    class SDLImageData : public ImageData {
    public:
        //! Construct a new SDLImageData object.
        //! @param surface The SDL_Surface.
        explicit SDLImageData(SDL_Surface *surface);

        //! Get the SDL_Surface.
        //! @return The SDL_Surface.
        [[nodiscard]] SDL_Surface* getSurface() const { return surface; }

        [[nodiscard]] uint32_t getWidth() const override;

        [[nodiscard]] uint32_t getHeight() const override;

        [[nodiscard]] const uint8_t *getData() const override;

        [[nodiscard]] uint32_t getChannels() const override;

        void destroy() override;

    private:
        SDL_Surface *surface;
    };
}


#endif //SDLIMAGEDATA_H
