//
// Created by lukaa on 26.12.2024..
//

#include <sstream>
#include "ecs/sprite/AnimatedSpriteRenderer.h"


namespace mars {
    AnimatedSpriteRenderer::AnimatedSpriteRenderer(Entity *entity)
        : SpriteRenderer(entity) {
        currentAnimation = nullptr;
    }

    Sprite *AnimatedSpriteRenderer::getSprite() const {
        return currentAnimation;
    }

    void AnimatedSpriteRenderer::playAnimation(const std::string& animationName) {
        currentAnimation = animations[animationName];
    }


    void AnimatedSpriteRenderer::addAnimation(const std::string &animationName, const std::vector<Rect> &frames) {
        auto *animatedSprite = new AnimatedSprite(sprite->getTextureShared());
        animations.emplace(animationName, animatedSprite);
        animatedSprite->setFrames(frames);
        currentAnimation = animatedSprite;
    }

    void AnimatedSpriteRenderer::update(const Time &time) {
        if (currentAnimation == nullptr) {
            return;
        }

        currentAnimation->update(time);
    }

    std::string AnimatedSpriteRenderer::toString() {
        std::stringstream result;

        Sprite *sprite = getSprite();

        result << "AnimatedSpriteRenderer\n"
                //  << "\t - sprite(" << sprite->getTexture()->getLabel() << ")\n"
                << "\t - color(" << this->color.r << ", "
                << this->color.g << ", "
                << this->color.b << ", "
                << this->color.a << ")\n";

        return result.str();
    }
}
