//
// Created by Erkapic Luka on 4.5.2025.
//

#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "core/sprite/game_sprite.h"
#include "core/math/Color.h"

namespace mars_entt_ecs {
    struct SpriteRenderer {

        //! Gets or sets the sprite.
        std::shared_ptr<mars::GameSprite> sprite;

        //! The color of the sprite.
        mars::Color color;

        //! Is fixed. If fixed is <code>true</code> this sprite is not moving with the camera and is fixed to position on screen.
        /// Typical use case would be for rendering UI elements.
        bool isFixed;
    };
}

#endif //SPRITE_RENDERER_H
