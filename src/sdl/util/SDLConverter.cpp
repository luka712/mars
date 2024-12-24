//
// Created by lukaa on 22.12.2024..
//


#include "Framework.h"
#include "sdl/util/SDLConverter.h"


namespace mars {
    SDLConverter::SDLConverter(Framework &framework)
        : framework(framework) {
    }

    SDL_TextureAccess SDLConverter::convert(const TextureUsage format) const {
        switch (format) {
            case TextureUsage::TextureBinding:
                return SDL_TEXTUREACCESS_STATIC;
            default:
                std::string msg = "Format not supported.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
        }
    }
}
