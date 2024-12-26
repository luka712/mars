//
// Created by lukaa on 29.11.2024..
//

#ifndef SPRITEBATCHDRAWABLE_H
#define SPRITEBATCHDRAWABLE_H

#include <memory>
#include "core/mesh/SpriteBatchMesh.h"
#include "core/texture/Texture2D.h"

namespace mars {

class Framework;

class SpriteBatchDrawable {
public:
    //! Construct a new SpriteBatchDrawable object.
    //! @param framework The framework.
    //! @param texture The texture.
    //! @param maxBatchSize The maximum batch size.
    SpriteBatchDrawable(Framework& framework, std::shared_ptr<Texture2D> texture, size_t maxBatchSize);

    //! Initialize the sprite batch.
    void initialize();

    //! Resize the batch.
    void reset();

    //! Begin the sprite batch.
    //! @param position The position of the sprite.
    //! @param size The size of the sprite.
    void writeSprite(glm::vec3 position, glm::vec2 size);

    //! Draws the batch.
    void draw();

    //! Call on frame end.
    void frameEnd();

private:
    Framework& framework;
    std::shared_ptr<Texture2D> texture;
    std::unique_ptr<SpriteBatchMesh> drawingMesh;
    size_t maxBatchSize;
    bool needsResize{};
    size_t fromInstance{};
    size_t toInstance{};
};
}

#endif //SPRITEBATCHDRAWABLE_H
