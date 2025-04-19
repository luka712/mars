//
// Created by Erkapic Luka on 22.12.2024.
//

#include "core/sprite/Sprite.h"

namespace mars {
    Sprite::Sprite(const std::shared_ptr<Texture2D> &texture)
        : texture(texture) {
        width = texture->getWidth();
        height = texture->getHeight();
        sourceRect = Rect(0, 0, static_cast<int>(width), static_cast<int>(height));
        origin = {0,0}; // By default, top left corner is the origin.
    }

    Texture2D &Sprite::getTexture() const {
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

    void Sprite::setSourceRect(const Rect sourceRect) {
        this->sourceRect = sourceRect;
    }

    void Sprite::setOrigin(const glm::vec2 &origin) {
        this->origin = origin;
    }
}
