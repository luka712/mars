//
// Created by lukaa on 22.12.2024..
//

#include "core/sprite/Sprite.h"

namespace mars
    {
    Sprite::Sprite(std::shared_ptr<Texture2D> texture)
        : texture(texture) {
      width = texture->getWidth();
        height = texture->getHeight();
    }

    Texture2D &Sprite::getTexture() const {
        return *texture;
    }

    uint32_t Sprite::getWidth() const {
        return width;
    }

    uint32_t Sprite::getHeight() const {
        return height;
    }
}