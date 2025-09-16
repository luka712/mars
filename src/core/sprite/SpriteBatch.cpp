//
// Created by Erkapic Luka on 26.2.2025.
//

#include "Framework.h"
#include "core/sprite/SpriteBatch.h"

namespace mars {
    SpriteBatch::SpriteBatch(Framework &framework) : framework(framework) {
    }

    void SpriteBatch::checkIfNewDrawableShouldBeCreated(ATexture2D*texture) {
        // If there was a texture change we need to end the current sprite batch drawable and start a new one.
        if (texture != currentTexture) {
            // End will draw. This draws with previously set sprite batch drawable.
            end();

            // Create a new sprite batch drawable if needed.
            SpriteBatchDrawable *drawable = nullptr;

            // If drawable is not in dictionary, create a new one.
            if (!drawables.contains(texture)) {
                drawable = new SpriteBatchDrawable(framework, *texture, *camera, MAX_BATCH_SIZE);
                drawable->initialize();
                drawables[texture] = drawable;
            } else {
                drawable = drawables[texture];
            }

            // Assign current.
            currentDrawable = drawable;
        }
    }

    void SpriteBatch::initialize() {
        const glm::u32vec2 frameBufferSize = framework.getRenderer().getFrameBufferSize();
        camera = framework.getCameraFactory().createOrthographicCamera(
            0, static_cast<float>(frameBufferSize.x),
            0, static_cast<float>(frameBufferSize.y),
            0, 1);
        defaultWhiteTexture = framework.getTextureFactory().createEmpty(1, 1, Color::white());
    }

    void SpriteBatch::begin() {
        for (auto &[fst, snd]: drawables) {
            snd->reset();
        }

        // Clear the current texture.
        currentTexture = nullptr;
    }

    void SpriteBatch::draw(ATexture2D*texture, const Rect drawRect, const Rect sourceRect, const Color color) {
        checkIfNewDrawableShouldBeCreated(texture);

        // Safe to assign current texture.
        currentTexture = texture;

        const auto textureWidth = static_cast<float>(texture->getWidth());
        const auto textureHeight = static_cast<float>(texture->getHeight());

        const float u0 = static_cast<float>(sourceRect.x) / textureWidth;
        const float v0 = static_cast<float>(sourceRect.y) / textureHeight;
        const float u1 = static_cast<float>(sourceRect.x + sourceRect.width) / textureWidth;
        const float v1 = static_cast<float>(sourceRect.y + sourceRect.height) / textureHeight;

        currentDrawable->writeSprite(
            glm::vec3(drawRect.x, drawRect.y, 0),
            glm::vec2(drawRect.width, drawRect.height),
            color,
            u0, v0, u1, v1
        );
    }

    void SpriteBatch::draw(ATexture2D*texture, const Rect drawRect, const Color color) {
        checkIfNewDrawableShouldBeCreated(texture);

        // Safe to assign current texture.
        currentTexture = texture;

        currentDrawable->writeSprite(
            glm::vec3(drawRect.x, drawRect.y, 0),
            glm::vec2(drawRect.width, drawRect.height),
            color
        );
    }

    void SpriteBatch::draw(const Rect drawRect, const Color color) {
        checkIfNewDrawableShouldBeCreated(defaultWhiteTexture.get());

        // Safe to assign current texture.
        currentTexture = defaultWhiteTexture.get();

        currentDrawable->writeSprite(
            glm::vec3(drawRect.x, drawRect.y, 0),
            glm::vec2(drawRect.width, drawRect.height),
            color
        );
    }

    void SpriteBatch::drawString(SpriteFont *spriteFont, std::string text, glm::vec2 position, Color *color,
                                 float scale) {
        checkIfNewDrawableShouldBeCreated(spriteFont->getTexture());

        checkIfNewDrawableShouldBeCreated(spriteFont->getTexture());

        // Safe to assign current texture.
        currentTexture = spriteFont->getTexture();

        float nextCharX = 0;
        for (char &character: text) {
            /* TODO: implement
            SpriteFontCharacter spriteFontCharacter = spriteFont[character]!;

            float x = position.X + spriteFontCharacter.Offset.X * scale.X + nextCharX * scale.X;
            float y = position.Y + spriteFontCharacter.Offset.Y * scale.Y;

            // Offset for origin.
            x -= origin.X * scale.X;
            y -= origin.Y * scale.Y;

            currentSpriteBatchDrawable.WriteSprite(
                new Vector3D<float>(x, y, 0),
                spriteFontCharacter.Size * scale,
                spriteFontCharacter.TextureCoords.A,
                spriteFontCharacter.TextureCoords.B,
                spriteFontCharacter.TextureCoords.C,
                spriteFontCharacter.TextureCoords.D,
                color
           );

            nextCharX += spriteFontCharacter.Advance;
            */
        }
    }

    void SpriteBatch::end() {
        if (currentDrawable != nullptr) {
            currentDrawable->draw();
        }
    }

    void SpriteBatch::frameEnd() {
        for (auto &drawable: drawables) {
            drawable.second->frameEnd();
        }
    }
}
