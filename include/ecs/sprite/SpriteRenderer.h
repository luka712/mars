//
// Created by lukaa on 10.12.2024..
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "core/math/Color.h"
#include "core/sprite/Sprite.h"
#include "ecs/layer/Layer.h"
#include "ecs/transform/RectTransform.h"

namespace mars {

    class SpriteRendererSystem;

    //! The SpriteRenderer class.
    //! Represents a sprite renderer component.
    class SpriteRenderer : public AComponent {
    public:
        //! Construct a new SpriteRenderer object.
        //! @param entity The entity that the component is attached to.
        explicit SpriteRenderer(Entity* entity);

        //! Get the rect transform.
        //! @return The rect transform. If not set, returns nullptr.
        [[nodiscard]] const RectTransform* getRectTransform() const;

        //! Gets the sprite.
        //! @return The sprite.
        [[nodiscard]] virtual Sprite* getSprite() const;

        //! Sets the sprite.
        //! @param sprite The sprite.
        void setSprite(Sprite* sprite);

        void initialize() override;

        std::string toString() override;

        //! The color of the sprite.
        Color color;
    protected:
          SpriteRendererSystem* system{};
          RectTransform* rectTransform{};
          Sprite* sprite{};
    };

}


#endif //SPRITERENDERER_H
