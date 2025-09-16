//
// Created by Erkapic Luka on 27.11.2024.
//

#ifndef SPRITE_BATCH_H
#define SPRITE_BATCH_H

#include <map>
#include "core/fonts/SpriteFont.h"
#include "core/texture/a_texture2d.h"
#include "core/math/Math.h"
#include "core/sprite/SpriteBatchDrawable.h"

#define MAX_BATCH_SIZE 1000

namespace mars {

    class Framework;

    //! The sprite batch.
    class SpriteBatch {
    public:
        virtual ~SpriteBatch() = default;

        //! Get the camera.
        //! @return The camera.
        [[nodiscard]] const OrthographicCamera& getCamera() const { return *camera; }

        //! The constructor.
        //! @param framework The framework.
        explicit SpriteBatch(Framework& framework);

        //! Initialize the sprite batch.
        virtual void initialize();

        //! Begin the sprite batch.
        virtual void begin();

        //! Draw a sprite.
        //! @param drawRect The region where to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(Rect drawRect, Color color);

        //! Draw a sprite.
        //! @param texture The texture to draw.
        //! @param drawRect The region where to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(ATexture2D* texture, Rect drawRect, Color color);

        //! Draw a sprite.
        //! @param texture The texture to draw.
        //! @param drawRect The region where to draw.
        //! @param sourceRect The region of the texture to draw.
        //! @param color The color of a rectangle that's drawn.
        virtual void draw(ATexture2D* texture, Rect drawRect, Rect sourceRect, Color color);

        //! Draws a text string.
        //! @param spriteFont The sprite font.
        //! @param text The text to draw.
        //! @param position The position where to draw.
        //! @param color The color of the text. By default, it's <code>nullptr</code>. If it's <code>nullptr</code>, the color is white.
        //! @param scale The scale of the text. By default, it's 1.0f.
        virtual void drawString(SpriteFont* spriteFont, std::string text, glm::vec2 position, Color *color, float scale);

        //! End the sprite batch.
        virtual void end();

        //! Call on frame end.
        virtual void frameEnd();

    protected:
        Framework& framework;
        std::map<ATexture2D*, SpriteBatchDrawable*> drawables;
        ATexture2D* currentTexture = nullptr;
        //! Texture to be used when one of overload without texture is called.
        std::shared_ptr<ATexture2D> defaultWhiteTexture;
        SpriteBatchDrawable* currentDrawable = nullptr;
        std::shared_ptr<OrthographicCamera> camera;

    private:
        void checkIfNewDrawableShouldBeCreated(ATexture2D* texture);
    };
}


#endif //SPRITE_BATCH_H
