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

    //! @copydoc SpriteBatch::draw()
    void OpenGLESSpriteBatch::draw(Rect drawRect, Color color) {}

    //! @copydoc SpriteBatch::draw()
    void OpenGLESSpriteBatch::draw(Texture2D* texture, Rect drawRect, Color color) {}

    //! @copydoc SpriteBatch::draw()
    void OpenGLESSpriteBatch::draw(Texture2D* texture, Rect drawRect, Rect srcRect, Color color) {}


    void OpenGLESSpriteBatch::end() {
    }


}