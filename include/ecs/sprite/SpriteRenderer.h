//
// Created by lukaa on 10.12.2024..
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "core/math/Color.h"
#include "ecs/transform/RectTransform.h"

namespace mars {

    //! The SpriteRenderer class.
    //! Represents a sprite renderer component.
    class SpriteRenderer : public AComponent {
    public:
        //! Construct a new SpriteRenderer object.
        //! @param entity The entity that the component is attached to.
        explicit SpriteRenderer(std::shared_ptr<Entity> entity);

        //! Get the rect transform.
        //! @return The rect transform. If not set, returns nullptr.
        const RectTransform* getRectTransform() const;

        void initialize() override;

        std::string toString() override;

        //! The color of the sprite.
        Color color;
    private:
          std::shared_ptr<RectTransform> rectTransform;
    };

}


#endif //SPRITERENDERER_H
