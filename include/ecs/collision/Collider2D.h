//
// Created by luka erkapic on 1.2.2025.
//

#ifndef COLLIDER2D_H
#define COLLIDER2D_H

#include <vector>
#include <functional>
#include <core/math/Color.h>

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

        //! Get the tag.
        //! @return The tag.
        [[nodiscard]] std::string getTag() const {  return tag; }

        //! Get the debug color.
        //! @return The debug color.
        [[nodiscard]] Color getDebugColor() const {   return debugColor;}

        //! Set the debug color.
        //! @param debugColor The debug color.
        void setDebugColor(const Color &debugColor) { this->debugColor = debugColor; }

        //! Set the tag.
        //! @param tag The tag.
        void setTag(const std::string &tag) { this->tag = tag; }

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
        Rect collisionRectangle{};
        std::vector<std::function<void(const Collider2D*, const Collider2D*)>> onCollisionCallbacks;
        std::string tag{};
        bool debug;
        Color debugColor;
    };
}

#endif //COLLIDER2D_H
