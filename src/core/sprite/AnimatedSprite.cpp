//
// Created by lukaa on 26.12.2024..
//

#include "core/sprite/AnimatedSprite.h"

namespace mars {
    AnimatedSprite::AnimatedSprite(const std::shared_ptr<Texture2D> &texture)
    : GameSprite(texture), currentFrame(0), frameTime(0), animationSpeed(1), changeFrameTime(100) {
        // Nothing to do.
    }

    Rect AnimatedSprite::getSourceRect() const {

        // Nothing to do.
        if (frames.empty()) {
            return Rect(0, 0,
                static_cast<int32_t>(texture->getWidth()),
                static_cast<int32_t>(texture->getHeight()));
        }

        return frames[currentFrame];
    }

    void AnimatedSprite::update(const Time time) {
        // Nothing to do.
        if (frames.empty()) {
            return;
        }

        frameTime += time.getDeltaTimeMS() * animationSpeed;
        if (frameTime >= changeFrameTime) {
            frameTime = 0;
            currentFrame++;
            if (currentFrame >= frames.size()) {
                currentFrame = 0;
            }
        }
    }

    //! Adds a frame to the animation.
    void AnimatedSprite::addFrame(const Rect frame) {
        frames.push_back(frame);
    }

    //! Sets the frame at given index.
    void AnimatedSprite::setFrame(const int32_t frameIndex, const Rect frame) {
        // Resize the vector if needed.
        if (frameIndex >= frames.size()) {
            frames.resize(frameIndex + 1);
        }

        frames[frameIndex] = frame;
    }

    void AnimatedSprite::setFrames(const std::vector<Rect> &frames) {
        this->frames = frames;
    }
}
