//
// Created by lukaa on 27.11.2024
//

#include "Framework.h"
#include "sdl/sprite/SDLSpriteBatch.h"
#include "sdl/renderer/SDLRenderer.h"

namespace mars {
    SDLSpriteBatch::SDLSpriteBatch(Framework &framework)
        : SpriteBatch(framework), currentItemIndex(0), currentTexture(nullptr) {
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

        drawRects[currentItemIndex] = { (float)drawRect.x,(float)drawRect.y, (float)drawRect.width, (float)drawRect.height};
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
            currentTexture = dynamic_cast<SDLTexture2D *>(texture);
        }
        drawRects[currentItemIndex] = { (float)drawRect.x, (float)drawRect.y, (float)drawRect.width, (float)drawRect.height};
        srcRects[currentItemIndex] = {
            0, 0,
            (float) texture->getWidth(),
            (float) texture->getHeight()
        };
        colors[currentItemIndex] = {
            static_cast<uint8_t>(color.r * 255),
            static_cast<uint8_t>(color.g * 255),
            static_cast<uint8_t>(color.b * 255),
            static_cast<uint8_t>(color.a * 255)
        };
        currentItemIndex++;
    }

    void SDLSpriteBatch::draw(Texture2D *texture, const Rect drawRect, const Rect sourceRect, const Color color) {
        if (currentTexture != texture || currentItemIndex >= SDL_SPRITEBATCH_MAX_DRAW_ITEMS) {
            end();
            currentTexture = dynamic_cast<SDLTexture2D *>(texture);
        }
        drawRects[currentItemIndex] = { (float)drawRect.x, (float)drawRect.y, (float)drawRect.width, (float)drawRect.height};
        srcRects[currentItemIndex] = { (float)sourceRect.x, (float)sourceRect.y, (float)sourceRect.width, (float)sourceRect.height};
        colors[currentItemIndex] = {
            static_cast<uint8_t>(color.r * 255),
            static_cast<uint8_t>(color.g * 255),
            static_cast<uint8_t>(color.b * 255),
            static_cast<uint8_t>(color.a * 255)
        };
        currentItemIndex++;
    }

    void SDLSpriteBatch::drawString(SpriteFont *spriteFont, std::string text, glm::vec2 position, Color *color, float scale) {
        Color setColor = Color::white();
        if (color != nullptr) {
            setColor = *color;
        }

        if (currentTexture != spriteFont->getTexture() || currentItemIndex >= SDL_SPRITEBATCH_MAX_DRAW_ITEMS) {
            end();
            currentTexture = dynamic_cast<SDLTexture2D *>(spriteFont->getTexture());
        }

        float nextCharX = 0.0f;
        for (char character : text) {

            const SpriteFontCharacter* spriteFontCharacter = (*spriteFont)[character];
            float x = position.x + spriteFontCharacter->getOffset().x * scale + nextCharX * scale;
            float y = position.y + spriteFontCharacter->getOffset().y * scale;
            glm::vec2 size = spriteFontCharacter->getSize() * scale;
            const Quad quad = spriteFontCharacter->getTextureCoords();

            drawRects[currentItemIndex] = {
                x,
                y,
                size.x,
                size.y
            };
            // Texture coordinates are normalized. We need to convert them to pixel coordinates.
            const auto texWidth = static_cast<float>(spriteFont->getTexture()->getWidth());
            const auto texHeight = static_cast<float>(spriteFont->getTexture()->getHeight());

            x = quad.a.x * texWidth;
            y = quad.a.y * texHeight;
            size.x = quad.d.x * texWidth;
            size.y = quad.d.y * texHeight;

            srcRects[currentItemIndex] = {
                x,
                y,
                size.x - x,
                size.y - y
            };
            colors[currentItemIndex] = {
                static_cast<uint8_t>(setColor.r * 255),
                static_cast<uint8_t>(setColor.g * 255),
                static_cast<uint8_t>(setColor.b * 255),
                static_cast<uint8_t>(setColor.a * 255)
            };
            nextCharX += spriteFontCharacter->getAdvance();
            currentItemIndex++;
        }
    }

    void SDLSpriteBatch::end() {
        for (int i = 0; i < currentItemIndex; i++) {
            SDL_SetRenderDrawColor(renderer, colors[i].r, colors[i].g, colors[i].b, colors[i].a);
            if (currentTexture != nullptr) {
                SDL_RenderTexture(renderer, currentTexture->getTexture(), &srcRects[i], &drawRects[i]);
            } else {
                SDL_RenderFillRect(renderer, &drawRects[i]);
            }
        }

        currentItemIndex = 0;
    }
}
