//
// Created by lukaa on 22.12.2024..
//

#include "core/sprite/Sprite.h"

namespace mars {
    Sprite::Sprite(const std::shared_ptr<Texture2D> &texture)
        : texture(texture) {
        width = texture->getWidth();
        height = texture->getHeight();
        sourceRect = Rect(0, 0, static_cast<int>(width), static_cast<int>(height));
    }

    Texture2D& Sprite::getTexture() const {
        return *texture;
    }

    std::shared_ptr<Texture2D> Sprite::getTextureShared() const {
        return texture;
    }

    uint32_t Sprite::getWidth() const {
        return width;
    }

    uint32_t Sprite::getHeight() const {
        return height;
    }

    Rect Sprite::getSourceRect() const {
        return sourceRect;
    }

    void Sprite::setSourceRect(Rect newSourceRect) {
        this->sourceRect = newSourceRect;
    }
}
