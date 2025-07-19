//
// Created by lukaa on 10.12.2024..
//

#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include "core/math/color.h"
#include "core/sprite/game_sprite.h"
#include "ecs/layering/Layer.h"
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
        //! @return The sprite. It can be nullptr.
        [[nodiscard]] virtual GameSprite* getSprite() const;

        //! Sets the sprite.
        //! @param sprite The sprite.
        void setSprite(std::shared_ptr<GameSprite> sprite);

        //! @copydoc
        void initialize() override;

        //! @copydoc
        void destroy() override;

        //! @copydoc
        std::string toString() override;

        //! The color of the sprite.
        Color color;

        //! Is fixed. If fixed is <code>true</code> this sprite is not moving with the camera and is fixed to position on screen.
        /// Typical use case would be for rendering UI elements.
        bool isFixed = false;
    protected:
          SpriteRendererSystem* system{};
          RectTransform* rectTransform{};
          std::shared_ptr<GameSprite> sprite;
    };

}


#endif //SPRITERENDERER_H
