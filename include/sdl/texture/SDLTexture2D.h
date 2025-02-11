//
// Created by lukaa on 21.12.2024..
//

#ifndef SDLTEXTURE2D_H
#define SDLTEXTURE2D_H

#include <SDL.h>
#include "core/texture/Texture2D.h"
#include "core/data/ImageData.h"

namespace mars {
    class Framework;
    class SDLRenderer;

    //! The SDL implementation of the Texture2D.
    class SDLTexture2D : public Texture2D {
    public:

        //! Construct a new SDLTexture2D object.
        //! @param framework The framework.
        //! @param imageData The image data.
        SDLTexture2D(Framework& framework, ImageData& imageData);

        //! Destroy the texture.
        ~SDLTexture2D();

        //! Get the texture.
        //! @return The texture.
        SDL_Texture* getTexture() const { return texture; }

        //! @inheritDoc
        void destroy() override;

        //! @inheritDoc
        std::string printInfo() override;
    private:
        Framework& framework;
        SDLRenderer& renderer;
        SDL_Texture* texture{};
    };
}


#endif //SDLTEXTURE2D_H
