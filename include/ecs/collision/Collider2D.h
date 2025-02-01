//
// Created by luka erkapic on 1.2.2025.
//

#ifndef COLLIDER2D_H
#define COLLIDER2D_H

#include <vector>
#include <functional>
#include "ecs/transform/RectTransform.h"
#include "core/math/Rect.h"

namespace mars {
    //! The Collider2D class.
    //! Represents a 2D collider.
    class Collider2D : public AComponent {
    public:
        //! Construct a new Collider2D object.
        //! @param entity The entity that the component is attached to.
        explicit Collider2D(Entity *entity);

        //! Get the drawing rectangle.
        //! @return The drawing rectangle.
        [[nodiscard]] Rect getCollisionRectangle() const { return collisionRectangle; }

        //! Set the drawing rectangle.
        //! @param drawRectangle The drawing rectangle.
        void setCollisionRectangle(Rect drawRectangle) { this->collisionRectangle = drawRectangle; }

        //! Get the debug flag.
        //! @return The debug flag.
        [[nodiscard]] bool getDebug() const { return debug; }

        //! Set the debug flag.
        //! @param debug The debug flag.
        void setDebug(const bool debug) { this->debug = debug; }

        //! Subscribe to on collision event.
        //! @param callback The callback.
        void subscribeToOnCollision(const std::function<void(const Collider2D*, const Collider2D*)>& callback) {
            onCollisionCallbacks.push_back(callback);
        }

        //! Get the on collision callbacks.
        //! @return The on collision callbacks.
        [[nodiscard]] std::vector<std::function<void(const Collider2D *, const Collider2D *)>> getOnCollisionCallbacks() const {
            return onCollisionCallbacks;
        }

        //! @copydoc AComponent::initialize()
        void initialize() override;

        //! @copydoc AComponent::update()
        void update(const Time &time) override;

    private:
        RectTransform* rectTransform{};
        bool debug = false;
        Rect collisionRectangle{};
        std::vector<std::function<void(const Collider2D*, const Collider2D*)>> onCollisionCallbacks;
    };
}

#endif //COLLIDER2D_H
