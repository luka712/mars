//
// Created by Erkapic Luka on 29.3.2025.
//

#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

#include <string>
#include <map>
#include "core/texture/Texture2D.h"
#include "core/sprite/Sprite.h"

namespace mars {

    class Framework;

    //! The SpriteManager class.
    //! Class responsible for managing the sprites.
    //! That is it holds all the game sprites created from textures.
    class SpriteManager final {
    public:

        //! Construct a new SpriteManager object.
        //! @param framework The framework.
        SpriteManager(Framework& framework);

        //! Get a sprite from the manager.
        //! @param name The name of the sprite.
        //! @return The sprite.
        std::shared_ptr<Sprite> getSprite(const std::string &name);

        //! Add a sprite to the manager.
        //! @param texture The texture of the sprite.
        //! @param spriteName The name of the sprite. This is the key to the sprite.
        void addSprite(const std::shared_ptr<Texture2D> &texture, const std::string &spriteName);

    private:
        Framework& framework;
        std::map<std::string, std::shared_ptr<Sprite> > sprites;
    };
}

#endif //SPRITE_MANAGER_H
