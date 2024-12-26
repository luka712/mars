//
// Created by lukaa on 22.12.2024..
//

#ifndef SPRITE_H
#define SPRITE_H

#include <memory>
#include "core/math/Rect.h"
#include "core/texture/Texture2D.h"

namespace mars {
    //! Class that represents a sprite.
    class Sprite {
    public:
        //! Construct a new Sprite object.
        //! @param texture The texture.
        explicit Sprite(const std::shared_ptr<Texture2D> &texture);

        //! The destructor.
        virtual ~Sprite() = default;

        //! Gets the texture.
        //! @return The texture.
        [[nodiscard]] Texture2D& getTexture() const;

        //! Gets the texture as a shared pointer.
        //! @return The shared pointer to the texture.
        [[nodiscard]] std::shared_ptr<Texture2D> getTextureShared() const;

        //! Gets the width of the sprite.
        //! @return The width of the sprite.
        [[nodiscard]] uint32_t getWidth() const;

        //! Gets the height of the sprite.
        //! @return The height of the sprite.
        [[nodiscard]] uint32_t getHeight() const;

        //! Gets the source rectangle.
        //! @return The source rectangle.
        [[nodiscard]] virtual Rect getSourceRect() const;

        //! Sets the source rectangle.
        //! @param sourceRect The source rectangle.
        void setSourceRect(Rect sourceRect);

    protected:
        std::shared_ptr<Texture2D> texture;
        Rect sourceRect{};

        uint32_t width{};
        uint32_t height{};

    };
}


#endif //SPRITE_H
