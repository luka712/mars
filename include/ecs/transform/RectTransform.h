//
// Created by lukaa on 8.12.2024..
//

#ifndef RECTTRANSFORM_H
#define RECTTRANSFORM_H

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

        //! Get the drawing rectangle.
        //! @return The drawing rectangle.
        [[nodiscard]] Rect getDrawRectangle() const;

        //! Set the drawing rectangle.
        //! @param drawRectangle The drawing rectangle.
        void setDrawRectangle(Rect drawRectangle);

        void update(const Time &time) override;

        std::string toString() override;

    private:
        Rect drawRectangle{};
        float rotation{};
        bool isDirty = true;
    };
}


#endif //RECTTRANSFORM_H
