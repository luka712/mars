//
// Created by Erkapic Luka on 4.5.2025.
//

#ifndef ENTT_SPRITE_RENDERER_SYSTEM_H
#define ENTT_SPRITE_RENDERER_SYSTEM_H

#include <entt/entt.hpp>
#include "Framework.h"
#include "entt_ecs/transform/rect_transform.h"
#include "entt_ecs/sprite/sprite_renderer.h"

namespace mars_entt_ecs {
    class EnttEcs;

    class SpriteRendererSystem {
    public:
        //! Constructor
        //! @param ecs The ECS manager.
        explicit SpriteRendererSystem(EnttEcs &ecs);

        //! Destructor
        ~SpriteRendererSystem() = default;

        //! Render the sprite render.
        //! TLayer is the layer to render.
        template <typename TLayer>
        void render() {

            // Assign sprite batch. It is used in other methods.
            spriteBatch = &framework.getSpriteBatch();

            // For each layer, render separate batch.
            spriteBatch->begin();

            //! Get the view of the registry.
            const auto view = registry.view<SpriteRenderer, RectTransform, TLayer>();
            //! Iterate over the view and render the sprite renderer.
            view.each([&](auto entity, const SpriteRenderer& renderer, const RectTransform& rectTransform, const TLayer& layer) {
                render(rectTransform, renderer);
            });
            spriteBatch->end();
        }

    private:
        //! The ECS manager.
        EnttEcs &ecs;

        //! The framework.
        mars::Framework &framework;

        //! The registry.
        entt::registry &registry;

        //! The sprite batch. Assigned when `render<TLayer>()` is called.
        mars::SpriteBatch* spriteBatch;

        //! Render the sprite renderer.
        //! @param rect_transform The rect transform.
        //! @param sprite_renderer The sprite renderer.
        void render(const RectTransform &rect_transform, const SpriteRenderer &sprite_renderer) const;
    };
}

#endif //SPRITE_RENDERER_SYSTEM_H
