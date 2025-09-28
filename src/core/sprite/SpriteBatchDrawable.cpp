//
// Created by Erkapic Luka on 29.11.2024.
//

#include "Framework.h"
#include "core/sprite/SpriteBatchDrawable.h"

namespace mars {
    SpriteBatchDrawable::SpriteBatchDrawable(
        Framework &framework,
        ATexture2D* texture,
        OrthographicCamera& camera,
        const size_t maxBatchSize)
        : framework(framework), camera(camera), texture(texture), maxBatchSize(maxBatchSize) {
    }

    void SpriteBatchDrawable::initialize() {
        renderPipeline = framework.getPipelineFactory().createSpriteRenderPipeline(&camera);
        renderPipeline->setSpriteTexture(texture);

        drawingMesh = std::make_unique<SpriteBatchMesh>(framework, maxBatchSize);
        drawingMesh->initialize();
    }

    void SpriteBatchDrawable::reset() {
        // Nothing is drawn yet.
        fromInstance = 0;
        toInstance = 0;
    }

    void SpriteBatchDrawable::writeSprite(const glm::vec3 position, const glm::vec2 size) {
        if (toInstance >= maxBatchSize) {
            // We need to resize the batch.
            needsResize = true;
            return;
        }

        drawingMesh->writeSprite(toInstance, position, size);
        toInstance++;
    }

    void SpriteBatchDrawable::writeSprite(
        const glm::vec3 position, const glm::vec2 size, const Color color,
        const float u0, const float v0, const float u1, const float v1) {
        // We must wait for frame end to resize.
        if (toInstance >= maxBatchSize)
        {
            needsResize = true;
            return;
        }

        drawingMesh->writeSprite(toInstance, position, size, color, u0, v0, u1, v1);

        // Write at correct position.
        toInstance++;
    }


    void SpriteBatchDrawable::draw() {
        // Nothing to draw.
        if (toInstance <= 0 || fromInstance > toInstance) {
            return;
        }

        // Clamp instance to max batch size.
        if (toInstance >= maxBatchSize) {
            toInstance = maxBatchSize - 1;
        }

        // Draw mesh.
        const size_t indicesOffset = static_cast<int>(fromInstance) * 6;
        const size_t indicesCount = toInstance * 6 - indicesOffset;
        drawingMesh->applyChanges();
        renderPipeline->render(
            &drawingMesh->getVertexBuffer(),
            &drawingMesh->getIndexBuffer(),
         	indicesCount,
         	indicesOffset );
        fromInstance = toInstance;
    }

    void SpriteBatchDrawable::frameEnd() {

        if (needsResize) {
            maxBatchSize *= 2;
            drawingMesh->resize(maxBatchSize);
        }

        needsResize = false;
    }
}
