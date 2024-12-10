//
// Created by lukaa on 10.12.2024..
//

#ifndef SPRITERENDERERSYSTEM_H
#define SPRITERENDERERSYSTEM_H

#include <vector>
#include "ecs/sprite/SpriteRenderer.h"

namespace mars {

    class Framework;

    //! The system that renders the sprite components.
    class SpriteRendererSystem {
    public:
        //! Construct a new SpriteRendererSystem object.
        //! @param framework The framework.
        explicit SpriteRendererSystem(Framework& framework);

        //! Add a sprite component to the system.
        //! @param sprite The sprite component.
        void add(const std::shared_ptr<SpriteRenderer>& sprite);

        //! Remove a sprite component from the system.
        //! @param sprite The sprite component.
        void remove(SpriteRenderer *sprite);

        //! Render the sprite components.
        void render();
     private:
        Framework& framework;
        std::vector<std::shared_ptr<SpriteRenderer>> sprites;
    };
}

#endif //SPRITERENDERERSYSTEM_H
