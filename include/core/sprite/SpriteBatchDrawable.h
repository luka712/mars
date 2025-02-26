//
// Created by lukaa on 29.11.2024..
//

#ifndef SPRITEBATCHDRAWABLE_H
#define SPRITEBATCHDRAWABLE_H

#include <memory>
#include "core/mesh/SpriteBatchMesh.h"
#include "core/texture/Texture2D.h"
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "core/camera/core/OrthographicCamera.h"

namespace mars {

class Framework;

class SpriteBatchDrawable {
public:
    //! Construct a new SpriteBatchDrawable object.
    //! @param framework The framework.
    //! @param texture The texture.
    //! @param camera The camera.
    //! @param maxBatchSize The maximum batch size.
    SpriteBatchDrawable(Framework& framework,
        Texture2D& texture,
        OrthographicCamera& camera,
        size_t maxBatchSize);

    //! Initialize the sprite batch.
    void initialize();

    //! Resize the batch.
    void reset();

    //! Begin the sprite batch.
    //! @param position The position of the sprite.
    //! @param size The size of the sprite.
    void writeSprite(glm::vec3 position, glm::vec2 size);

    //! Write a sprite.
    //! @param position The position of the sprite.
    //! @param size The size of the sprite.
    //! @param color The color of the sprite.
    //! @param u0 The u0.
    //! @param v0 The v0.
    //! @param u1 The u1.
    //! @param v1 The v1.
    void writeSprite(
        glm::vec3 position,
        glm::vec2 size,
        Color color,
        float u0 = 0,
        float v0 = 0,
        float u1 = 1,
        float v1 = 1);

    //! Draws the batch.
    void draw();

    //! Call on frame end.
    void frameEnd();

private:
    Framework& framework;
    std::shared_ptr<ASpriteRenderPipeline> renderPipeline;
    OrthographicCamera& camera;
    Texture2D& texture;
    std::unique_ptr<SpriteBatchMesh> drawingMesh;
    size_t maxBatchSize;
    bool needsResize{};
    size_t fromInstance{};
    size_t toInstance{};
};
}

#endif //SPRITEBATCHDRAWABLE_H
