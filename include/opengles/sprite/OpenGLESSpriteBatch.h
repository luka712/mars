//
// Created by lukaa on 2.1.2025..
//

#ifndef OPENGLESSPRITEBATCH_H
#define OPENGLESSPRITEBATCH_H


#include "core/sprite/SpriteBatch.h"

#define SDL_SPRITEBATCH_MAX_DRAW_ITEMS 1000

namespace mars {

class Framework;

//! THe Open GLES implementation of the SpriteBatch.
class OpenGLESSpriteBatch final : public SpriteBatch {

public:
    //! Construct a new SDLSpriteBatch object.
    explicit OpenGLESSpriteBatch(Framework &framework);

    //! @copydoc SpriteBatch::initialize()
    void initialize() override;

    //! @copydoc SpriteBatch::begin()
    void begin() override;

    //! @copydoc SpriteBatch::draw()
    void draw(Rect drawRect, Color color) override;

    //! @copydoc SpriteBatch::draw()
    void draw(Texture2D* texture, Rect drawRect, Color color) override;

    //! @copydoc SpriteBatch::draw()
    void draw(Texture2D* texture, Rect drawRect, Rect srcRect, Color color) override;

    //! @copydoc SpriteBatch::drawString()
    void drawString(SpriteFont *spriteFont, std::string text, glm::vec2 position, Color *color, float scale) override;

    //! @copydoc SpriteBatch::end()
    void end() override;

    private:
      Framework &framework;
};

}

#endif //OPENGLESSPRITEBATCH_H
