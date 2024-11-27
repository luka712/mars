//
// Created by lukaa on 27.11.2024..
//

#ifndef SDLSPRITEBATCH_H
#define SDLSPRITEBATCH_H

#include <SDL.h>
#include "core/sprite/SpriteBatch.h"
#include <array>

#define SDL_SPRITEBATCH_MAX_DRAW_ITEMS 1000

namespace mars {
    class Framework;

    //! The SDL implementation of the SpriteBatch.
    class SDLSpriteBatch final : public SpriteBatch {
        Framework &framework;
        SDL_Renderer* renderer{};
        int32_t currentItemIndex;
        std::array<SDL_Rect, SDL_SPRITEBATCH_MAX_DRAW_ITEMS> drawRects{};
        std::array<SDL_Color, SDL_SPRITEBATCH_MAX_DRAW_ITEMS> colors{};

    public:
        //! Construct a new SDLSpriteBatch object.
        SDLSpriteBatch(Framework &framework);

        //! @copydoc SpriteBatch::initialize()
        void initialize() override;

        //! @copydoc SpriteBatch::begin()
        void begin() override;

        //! @copydoc SpriteBatch::draw()
        void draw(Rect drawRect, Color color) override;

        //! @copydoc SpriteBatch::end()
        void end() override;
    };
}

#endif //SDLSPRITEBATCH_H
