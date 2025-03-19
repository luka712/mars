//
// Created by Erkapic Luka on 1.2.2025.
//

#include "Framework.h"
#include "ecs/collision/Collision2DSystem.h"

#include "glm/gtc/type_ptr.hpp"

namespace mars {
    Collision2DSystem::Collision2DSystem(Framework &framework)
        : framework(framework) {
    }

    void Collision2DSystem::initialize() {
        // Single vertex is (xyz + rgba). Supports 20_000 vertices or 10_000 lines.
        vertexData = std::vector(20'000 * 7, 0.0f);

        vertexBuffer = framework.getBuffersFactory().createVertexBuffer(
            vertexData,
            20'000,
            BufferUsage::Vertex_CopyDst,
            "Collision2DSystem.vertexBuffer"
        );

        auto identity = glm::mat4(1.0f);
        modelBuffer = framework.getBuffersFactory().createInstanceBuffer(
            glm::value_ptr(identity),
            sizeof(glm::mat4),
            sizeof(glm::mat4),
            1,
            "Collision2DSystem.modelBuffer"
        );

        linesRenderPipeline = framework.getPipelineFactory().createLinesRenderPipeline(
            framework.getSpriteBatch().getCamera().getProjectionViewBuffer(),
            *modelBuffer
        );
    }

    void Collision2DSystem::add(Collider2D *collider) {
        colliders.emplace_back(collider);
    }

    void Collision2DSystem::remove(const Collider2D *collider) {
        for (uint32_t i = 0; i < colliders.size(); i++) {
            if (colliders[i] == collider) {
                colliders.erase(colliders.begin() + i);
                break;
            }
        }
    }

    void Collision2DSystem::update(const Time &time) {
        // First we need to update all colliders.
        for (const auto &collider: colliders) {
            collider->update(time);
        }

        // Then we can check for collisions.
        for (uint32_t i = 0; i < colliders.size(); i++) {
            const Collider2D &checkCollider = *colliders[i];

            for (uint32_t j = i + 1; j < colliders.size(); j++) {
                const Collider2D &otherCollider = *colliders[j];

                // Check for collision.
                if (checkCollider.getCollisionRectangle().intersects(otherCollider.getCollisionRectangle())) {
                    // Callback.
                    for (auto &callback: checkCollider.getOnCollisionCallbacks()) {
                        callback(&checkCollider, &otherCollider);
                    }
                }
            }
        }
    }

     void Collision2DSystem::addLine(const glm::vec2 &start, const glm::vec2 &end, const Color &color, size_t* index) {

        size_t i = *index;

        vertexData[i++] = start.x;
        vertexData[i++] = start.y;
        vertexData[i++] = 0.0f;
        vertexData[i++] = color.r;
        vertexData[i++] = color.g;
        vertexData[i++] = color.b;
        vertexData[i++] = color.a;

        vertexData[i++] = end.x;
        vertexData[i++] = end.y;
        vertexData[i++] = 0.0f;
        vertexData[i++] = color.r;
        vertexData[i++] = color.g;
        vertexData[i++] = color.b;
        vertexData[i++] = color.a;

        *index = i;
    }

    void Collision2DSystem::render(Camera2D &camera) {
        if (colliders.empty()) {
            return;
        }

        size_t index = 0;
        size_t vertexCount = 0;

        Rect cameraRect = camera.getRectTransform()->getDrawRectangle();

        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        // spriteBatch.begin();
        for (const auto &collider: colliders) {
            if (collider->getDebug()) {
                // Draw the collision rectangle.
                Rect drawRect = collider->getCollisionRectangle();
                drawRect.x -= cameraRect.x;
                drawRect.y -= cameraRect.y;
                // Line rendering.
                // spriteBatch.draw(drawRect, collider->getDebugColor());

                Color color = collider->getDebugColor();
                addLine({drawRect.x, drawRect.y}, {drawRect.x + drawRect.width, drawRect.y}, color, &index);
                addLine({drawRect.x + drawRect.width, drawRect.y}, {drawRect.x + drawRect.width, drawRect.y + drawRect.height}, color, &index);
                addLine({drawRect.x + drawRect.width, drawRect.y + drawRect.height}, {drawRect.x, drawRect.y + drawRect.height}, color, &index);
                addLine({drawRect.x, drawRect.y + drawRect.height}, {drawRect.x, drawRect.y}, color, &index);
                vertexCount += 8;
            }
        }
       //  spriteBatch.end();

        vertexBuffer->update(vertexData.data(), vertexCount * 7 * sizeof(float), 0);
        linesRenderPipeline->render(*vertexBuffer, 1, vertexCount);

    }
}
