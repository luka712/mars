//
// Created by lukaa on 27.11.2024
//

#include "Framework.h"
#include "sdl/sprite/SDLSpriteBatch.h"
#include "sdl/renderer/SDLRenderer.h"

namespace mars {
    SDLSpriteBatch::SDLSpriteBatch(Framework &framework)
        : framework(framework), currentItemIndex(0), currentTexture(nullptr) {
    }

    void SDLSpriteBatch::initialize() {
        this->renderer = dynamic_cast<SDLRenderer &>(framework.getRenderer()).getRenderer();
    }

    void SDLSpriteBatch::begin() {
        currentItemIndex = 0;
    }

    void SDLSpriteBatch::draw(const Rect drawRect, const Color color) {
        if (currentTexture != nullptr || currentItemIndex >= SDL_SPRITEBATCH_MAX_DRAW_ITEMS) {
            end();
            currentTexture = nullptr;
        }

        drawRects[currentItemIndex] = {drawRect.x, drawRect.y, drawRect.width, drawRect.height};
        colors[currentItemIndex] = {
            static_cast<uint8_t>(color.r * 255),
            static_cast<uint8_t>(color.g * 255),
            static_cast<uint8_t>(color.b * 255),
            static_cast<uint8_t>(color.a * 255)
        };
        currentItemIndex++;
    }

    void SDLSpriteBatch::draw(Texture2D *texture, const Rect drawRect, const Color color) {
        if (currentTexture != texture || currentItemIndex >= SDL_SPRITEBATCH_MAX_DRAW_ITEMS) {
            end();
            currentTexture = static_cast<SDLTexture2D *>(texture);
        }
        drawRects[currentItemIndex] = {drawRect.x, drawRect.y, drawRect.width, drawRect.height};
        colors[currentItemIndex] = {
            static_cast<uint8_t>(color.r * 255),
            static_cast<uint8_t>(color.g * 255),
            static_cast<uint8_t>(color.b * 255),
            static_cast<uint8_t>(color.a * 255)
        };
        currentItemIndex++;
    }

    void SDLSpriteBatch::end() {
        for (int i = 0; i < currentItemIndex; i++) {
            SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            if (currentTexture != nullptr) {
                SDL_RenderCopy(renderer, currentTexture->getTexture(), nullptr, &drawRects[i]);
            } else {
                SDL_RenderFillRect(renderer, &drawRects[i]);
            }
        }

        currentItemIndex = 0;
    }
}
