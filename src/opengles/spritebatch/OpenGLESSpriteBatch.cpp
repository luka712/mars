//
// Created by lukaa on 2.1.2025..
//

#include "Framework.h"
#include "opengles/sprite/OpenGLESSpriteBatch.h"

namespace mars {
    OpenGLESSpriteBatch::OpenGLESSpriteBatch(Framework &framework)
        : framework(framework) {
    }

    void OpenGLESSpriteBatch::initialize() {
    }

    void OpenGLESSpriteBatch::begin() {
    }

    void OpenGLESSpriteBatch::draw(Rect drawRect, Color color) {}

    void OpenGLESSpriteBatch::draw(Texture2D* texture, Rect drawRect, Color color) {}

    void OpenGLESSpriteBatch::draw(Texture2D* texture, Rect drawRect, Rect srcRect, Color color) {}

    void OpenGLESSpriteBatch::drawString(SpriteFont *spriteFont, std::string text, glm::vec2 position, Color *color, float scale) {}

    void OpenGLESSpriteBatch::end() {
    }


}