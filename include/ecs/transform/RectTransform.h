//
// Created by Erkapic Luka on 8.12.2024.
//

#ifndef RECT_TRANSFORM_H
#define RECT_TRANSFORM_H

#include "ecs/components/AComponent.h"
#include "core/math/Rect.h"
#include "glm/vec2.hpp"

namespace mars {
    //! The rect transform component.
    //! Used to store the position, rotation and scale of the entity in 2D world space.
    class RectTransform : public AComponent {
    public:
        //! Construct a new RectTransform object.
        //! @param entity The entity that the component is attached to.
        explicit RectTransform(Entity* entity);

        //! Get the position.
        //! @return The position.
        [[nodiscard]] glm::vec2 getPosition() const { return {drawRectangle.x, drawRectangle.y}; }

        //! Set the position.
        //! @param position The position.
        void setPosition(glm::vec2 position);

        //! Gets the size of the rectangle.
        //! @return The size of the rectangle.
        [[nodiscard]] glm::vec2 getSize() const { return {drawRectangle.width, drawRectangle.height}; }

        //! Get the drawing rectangle.
        //! @return The drawing rectangle.
        [[nodiscard]] Rect getDrawRectangle() const;

        //! Set the drawing rectangle.
        //! @param drawRectangle The drawing rectangle.
        void setDrawRectangle(Rect drawRectangle);

        //! @copydoc
        void update(const Time &time) override;

        //! @copydoc
        std::string toString() override;

    private:
        Rect drawRectangle{};
        float rotation{};
        bool isDirty = true;
    };
}


#endif //RECT_TRANSFORM_H
