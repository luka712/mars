//
// Created by lukaa on 26.12.2024..
//

#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include <vector>

#include "map"
#include "core/time/Time.h"
#include "core/sprite/Sprite.h"

namespace mars {

    //! The AnimatedSprite class.
    //! Plays simple animation from a single sprite sheet.
    //! Set animation frames with index and source rectangle.
    class AnimatedSprite : public Sprite {
    public:

        //! Construct a new AnimatedSprite object.
        //! @param texture The texture.
        explicit AnimatedSprite(const std::shared_ptr<Texture2D> &texture);

        //! @copydoc Sprite::getSourceRect()
        [[nodiscard]] Rect getSourceRect() const override;

        //! Update the animation.
        //! @param time The time.
        void update(Time time);

        //! Adds a frame to the animation.
        void addFrame(Rect frame);

        //! Sets the frame at given index.
        void setFrame(int32_t frameIndex, Rect frame);

        //! Sets the frames of the animation.
        void setFrames(const std::vector<Rect> &frames);

    private:
        // The frames of animation.
        // It's just collection of defined source rectangles from a single sprite sheet.
        std::vector<Rect> frames;

        // The current frame index.
        int32_t currentFrame;

        // The time between frames.
        float frameTime;

        // The speed of the animation.
        float animationSpeed;

        // When to change frames.
        float changeFrameTime;
    };

}


#endif //ANIMATEDSPRITE_H
