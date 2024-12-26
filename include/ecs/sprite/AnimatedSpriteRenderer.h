//
// Created by lukaa on 26.12.2024..
//

#ifndef ANIMATEDSPRITERENDERER_H
#define ANIMATEDSPRITERENDERER_H

#include <map>
#include "ecs/sprite/SpriteRenderer.h"
#include "core/sprite/AnimatedSprite.h"

namespace mars {
    //! The AnimatedSpriteRenderer class.
    //! Represents a renderer that can render animated sprites.
    class AnimatedSpriteRenderer final : public SpriteRenderer {

    public:
        //! Construct a new AnimatedSpriteRenderer object.
        //! @param entity The entity that the component is attached to.
        explicit AnimatedSpriteRenderer(Entity* entity);

        //! Get the current sprite.
        [[nodiscard]] Sprite* getSprite() const override;

        //! Play the animation.
        //! @param animationName The name of the animation.
        void playAnimation(const std::string& animationName);

        //! Adds new animation to the renderer.
        //! @param animationName The name of the animation.
        //! @param frames The frames of the animation.
        void addAnimation(const std::string& animationName, const std::vector<Rect> &frames);

        //! @copydoc SpriteRenderer::toString()
        std::string toString() override;

        //! @copydoc SpriteRenderer::update()
        void update(const Time &time) override;

    private:
        AnimatedSprite* currentAnimation;
        std::map<std::string, AnimatedSprite*> animations;
    };
}




#endif //ANIMATEDSPRITERENDERER_H
