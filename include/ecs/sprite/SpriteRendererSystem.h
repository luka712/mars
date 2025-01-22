//
// Created by lukaa on 10.12.2024..
//

#ifndef SPRITERENDERERSYSTEM_H
#define SPRITERENDERERSYSTEM_H

#include <vector>
#include <map>
#include "ecs/layer/Layer.h"
#include "ecs/sprite/SpriteRenderer.h"
#include "ecs/camera/Camera2D.h"

namespace mars {
    class Framework;

    //! The system that renders the sprite components.
    class SpriteRendererSystem {
    public:
        //! Construct a new SpriteRendererSystem object.
        //! @param framework The framework.
        explicit SpriteRendererSystem(Framework &framework);

        //! Add a sprite component to the system.
        //! @param spriteRenderer The sprite component.
        void add(SpriteRenderer *spriteRenderer);

        //! Called when frame starts. Prepares the system for rendering, by sorting according to layer order.
        void frameStart();

        //! Update the sprite components.
        //! @param time The game time.
        //! @param currentLayerOrder The current layer order being updated.
        void update(const Time &time, uint32_t currentLayerOrder);

        //! Remove a sprite component from the system.
        //! @param sprite The sprite component.
        void remove(const SpriteRenderer *sprite);

        //! Render the sprite components.
        //! @param currentLayerOrder The current layer order being rendered.
        //! @param camera The camera.
        void render(uint32_t currentLayerOrder, Camera2D& camera);

    private:
        Framework &framework;

        std::vector<SpriteRenderer *> sprites;
        //! Layer order is key, while sprites to render are values.
        std::map<uint32_t, std::vector<SpriteRenderer *> > layerOrderSpritesMap;
        //! Layer order is key, while sprites to render count is value.
        std::map<uint32_t, uint32_t> layerOrderSpriteCountMap;

        //! Move the sprite to the layer map.
        //! @param spriteRenderer The sprite renderer.
        void moveToLayerMap(SpriteRenderer *spriteRenderer);
    };
}

#endif //SPRITERENDERERSYSTEM_H
