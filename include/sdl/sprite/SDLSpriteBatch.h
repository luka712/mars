//
// Created by lukaa on 27.11.2024..
//

#ifndef SDLSPRITEBATCH_H
#define SDLSPRITEBATCH_H

#include <SDL3/SDL.h>
#include "core/sprite/SpriteBatch.h"
#include <array>

#include "sdl/texture/SDLTexture2D.h"

#define SDL_SPRITEBATCH_MAX_DRAW_ITEMS 1000

namespace mars {
    class Framework;

    //! The SDL implementation of the SpriteBatch.
    class SDLSpriteBatch final : public SpriteBatch {

    public:
        //! Construct a new SDLSpriteBatch object.
        explicit SDLSpriteBatch(Framework &framework);

        //! @copydoc SpriteBatch::initialize()
        void initialize() override;

        //! @copydoc SpriteBatch::begin()
        void begin() override;

        //! @copydoc SpriteBatch::draw()
        void draw(Rect drawRect, Color color) override;

        //! @copydoc SpriteBatch::draw()
        void draw(ATexture2D* texture, Rect drawRect, Color color) override;

        //! @copydoc SpriteBatch::draw()
        void draw(ATexture2D* texture, Rect drawRect, Rect srcRect, Color color) override;

        //! @copydoc SpriteBatch::drawString()
        void drawString(SpriteFont *spriteFont, std::string text, glm::vec2 position, Color *color, float scale) override;

        //! @copydoc SpriteBatch::end()
        void end() override;

    private:
        SDL_Renderer* renderer{};
        SDLTexture2D* currentTexture;
        int32_t currentItemIndex;
        std::array<SDL_FRect, SDL_SPRITEBATCH_MAX_DRAW_ITEMS> drawRects{};
        std::array<SDL_FRect, SDL_SPRITEBATCH_MAX_DRAW_ITEMS> srcRects{};
        std::array<SDL_Color, SDL_SPRITEBATCH_MAX_DRAW_ITEMS> colors{};
    };
}

#endif //SDLSPRITEBATCH_H
