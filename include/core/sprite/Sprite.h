//
// Created by lukaa on 22.12.2024..
//

#ifndef SPRITE_H
#define SPRITE_H

#include <memory>
#include "core/math/Rect.h"
#include "core/texture/Texture2D.h"

namespace mars {
    class Sprite {
    public:
        //! Construct a new Sprite object.
        //! @param texture The texture.
        explicit Sprite(std::shared_ptr<Texture2D> texture);

        //! Gets the texture.
        //! @return The texture.
        [[nodiscard]] Texture2D &getTexture() const;

        //! Gets the width of the sprite.
        //! @return The width of the sprite.
        [[nodiscard]] uint32_t getWidth() const;

        //! Gets the height of the sprite.
        //! @return The height of the sprite.
        [[nodiscard]] uint32_t getHeight() const;

    private:
        std::shared_ptr<Texture2D> texture;
        uint32_t width;
        uint32_t height;

    };
}


#endif //SPRITE_H
