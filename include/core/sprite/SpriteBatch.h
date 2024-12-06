//
// Created by lukaa on 27.11.2024..
//

#ifndef SPRITEBATCH_H
#define SPRITEBATCH_H

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

        //! End the sprite batch.
        virtual void end() = 0;
    };
}


#endif //SPRITEBATCH_H
