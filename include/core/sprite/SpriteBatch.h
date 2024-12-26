//
// Created by lukaa on 27.11.2024..
//

#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

#include "core/texture/Texture2D.h"
#include "core/math/Math.h"

namespace mars {
    class SpriteBatch {
    public:
        virtual ~SpriteBatch() = default;

        //! Initialize the sprite batch.
        virtual void initialize() = 0;

        //! Begin the sprite batch.
        virtual void begin() = 0;

        //! Draw a sprite.
        //! @param drawRect The region where to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(Rect drawRect, Color color) = 0;

        //! Draw a sprite.
        //! @param texture The texture to draw.
        //! @param drawRect The region where to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(Texture2D* texture, Rect drawRect, Color color) = 0;

        //! Draw a sprite.
        //! @param texture The texture to draw.
        //! @param drawRect The region where to draw.
        //! @param sourceRect The region of the texture to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(Texture2D* texture, Rect drawRect, Rect sourceRect, Color color) = 0;

        //! End the sprite batch.
        virtual void end() = 0;
    };
}


#endif //SPRITEBATCH_H
