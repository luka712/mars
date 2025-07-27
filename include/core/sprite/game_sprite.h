//
// Created by Erkapic Luka on 22.12.2024.
//

#ifndef SPRITE_H
#define SPRITE_H

#include <memory>
#include "core/math/Rect.h"
#include "core/texture/texture2d.h"
#include "glm/vec2.hpp"

namespace mars {
    //! Class that represents a sprite.
    class GameSprite {
    public:
        //! Construct a new Sprite object.
        //! @param texture The texture.
        explicit GameSprite(const std::shared_ptr<Texture2D> &texture);

        //! The destructor.
        virtual ~GameSprite() = default;

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

        //! The origin of sprite
        //! @return The origin of sprite.
        [[nodiscard]] glm::vec2 getOrigin() const {
            return origin;
        }

        //! Sets the origin of the sprite.
        //! @param origin The origin of the sprite.
        void setOrigin(const glm::vec2 &origin);

    protected:
        std::shared_ptr<Texture2D> texture;
        Rect sourceRect{};

        glm::vec2 origin{};
        uint32_t width{};
        uint32_t height{};

    };
}


#endif //SPRITE_H
