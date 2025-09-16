//
// Created by Erkapic Luka on 22.12.2024.
//

#include "core/sprite/game_sprite.h"

namespace mars {
    GameSprite::GameSprite(const std::shared_ptr<ATexture2D> &texture)
        : texture(texture) {
        width = texture->getWidth();
        height = texture->getHeight();
        sourceRect = Rect(0, 0, static_cast<int>(width), static_cast<int>(height));
        origin = {0,0}; // By default, top left corner is the origin.
    }

    ATexture2D&GameSprite::getTexture() const {
        return *texture;
    }

    std::shared_ptr<ATexture2D> GameSprite::getTextureShared() const {
        return texture;
    }

    uint32_t GameSprite::getWidth() const {
        return width;
    }

    uint32_t GameSprite::getHeight() const {
        return height;
    }

    Rect GameSprite::getSourceRect() const {
        return sourceRect;
    }

    void GameSprite::setSourceRect(const Rect sourceRect) {
        this->sourceRect = sourceRect;
    }

    void GameSprite::setOrigin(const glm::vec2 &origin) {
        this->origin = origin;
    }
}
