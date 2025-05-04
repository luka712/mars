//
// Created by Erkapic Luka on 4.5.2025.
//

#ifndef ENTT_SPRITE_RENDERER_SYSTEM_H
#define ENTT_SPRITE_RENDERER_SYSTEM_H

namespace mars_entt_ecs {
    class EnttEcs;

    class SpriteRendererSystem {
    public:
        //! Constructor
        //! @param ecs The ECS manager.
        explicit SpriteRendererSystem(EnttEcs &ecs);

        //! Destructor
        ~SpriteRendererSystem() = default;

        //! Render the sprite renderer system.
        void render();

    private:
        //! The ECS manager.
        EnttEcs &ecs;
    };
}

#endif //SPRITE_RENDERER_SYSTEM_H
