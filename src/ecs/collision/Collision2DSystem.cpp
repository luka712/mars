//
// Created by lukaa on 1.2.2025..
//

#include "../../../include/Framework.h"
#include "../../../include/ecs/collision/Collision2DSystem.h"

namespace mars {
    Collision2DSystem::Collision2DSystem(Framework &framework)
        : framework(framework) {
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

            const Collider2D& checkCollider = *colliders[i];

            for (uint32_t j = i + 1; j < colliders.size(); j++) {

                const Collider2D& otherCollider = *colliders[j];

                // Check for collision.
                if (checkCollider.getCollisionRectangle().intersects(otherCollider.getCollisionRectangle())) {

                    // Callback.
                    for (auto& callback: checkCollider.getOnCollisionCallbacks()) {
                        callback(&checkCollider, &otherCollider);
                    }
                }
            }
        }
    }

    void Collision2DSystem::render(Camera2D &camera) const {
        if (colliders.empty()) {
            return;
        }

        Rect cameraRect = camera.getRectTransform()->getDrawRectangle();

        SpriteBatch &spriteBatch = framework.getSpriteBatch();

        spriteBatch.begin();
        for (const auto &collider: colliders) {
            if (collider->getDebug()) {
                // Draw the collision rectangle.
                Rect drawRect = collider->getCollisionRectangle();
                drawRect.x -= cameraRect.x;
                drawRect.y -= cameraRect.y;
                // Line rendering.
                spriteBatch.draw(drawRect, Color::red());
            }
        }
        spriteBatch.end();
    }
}
