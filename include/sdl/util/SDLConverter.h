//
// Created by lukaa on 22.12.2024..
//

#ifndef SDLCONVERTER_H
#define SDLCONVERTER_H

#include <SDL.h>
#include "core/texture/TextureEnums.h"

namespace mars {
     enum class TextureUsage;

     class Framework;

     //! Converts mars data to SDL data.
     struct SDLConverter {

          //! Construct a new SDLConverter object.
          //! @param framework The framework.
          explicit SDLConverter(Framework& framework);

          //! Convert the texture format to SDL texture access.
          //! @param format The texture format.
          //! @return The SDL texture access.
          SDL_TextureAccess convert(TextureUsage format) const;

     private:
          Framework& framework;
     };
}

#endif //SDLCONVERTER_H
