//
// Created by lukaa on 8.12.2024..
//

#ifndef RECTTRANSFORM_H
#define RECTTRANSFORM_H

#include "ecs/components/AComponent.h"
#include "core/math/Rect.h"

namespace mars {
    //! The rect transform component.
    class RectTransform : public AComponent {
    public:
        //! Construct a new RectTransform object.
        //! @param entity The entity that the component is attached to.
        explicit RectTransform(std::shared_ptr<Entity> entity);

        //! Get the drawing rectangle.
        //! @return The drawing rectangle.
        [[nodiscard]] Rect getDrawRectangle() const;

        //! Set the drawing rectangle.
        //! @param drawRectangle The drawing rectangle.
        void setDrawRectangle(const Rect &drawRectangle);

        void update(const Time &time) override;

        bool operator==(const RectTransform & rect_transform) const = default;

    private:
        Rect drawRectangle;
        float rotation;
        bool isDirty = true;
    };
}


#endif //RECTTRANSFORM_H
