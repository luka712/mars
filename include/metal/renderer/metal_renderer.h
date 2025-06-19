//
// Created by Luka Erkapic on 26.04.25.
//

#ifndef METAL_RENDERER_H
#define METAL_RENDERER_H

#if __APPLE__
#include <SDL.h>
#include "metal/metal.h"
#include "core/renderer/Renderer.h"

namespace mars {
    class Framework;

    class MetalRenderer final : public Renderer {
    public:
        //! Construct a new MetalRenderer object.
        //! @param framework The framework.
        //! @param frameBufferSize The frame buffer size.
        explicit MetalRenderer(Framework &framework, glm::vec2 frameBufferSize);

        //! Gets the Metal device.
        //! @return The MTL::Device pointer.
        [[nodiscard]] MTL::Device *getDevice() const { return device; }

        //! Gets the Metal queue.
        //! @return The MTL::Queue pointer.
        [[nodiscard]] MTL::CommandQueue *getQueue() const { return queue; }

        //! Gets the RenderCommandEncoder.
        //! @return The pointer to the RenderCommandEncoder.
        [[nodiscard]] MTL::RenderCommandEncoder *getRenderCommandEncoder() const { return renderCommandEncoder; }

        //! @copydoc Renderer::initialize()
        void initialize() override;

        //! @copydoc Renderer::beginRenderPass()
        void beginRenderPass() override;

        //! @copydoc Renderer::endRenderPass()
        void endRenderPass() override;

        //! @copydoc Renderer::destroy()
        void destroy() override;

    private:
        SDL_Window *window;
        //! The metal layer.
        CA::MetalLayer *metalLayer;
        //! The window surface to draw to.
        CA::MetalDrawable *currentDrawable;
        MTL::Device *device;
        MTL::CommandQueue *queue;

        // RENDERING
        MTL::CommandBuffer *renderCommandBuffer;
        MTL::RenderCommandEncoder *renderCommandEncoder;

        //! Create a new render pass.
        void setupNewRenderPass();
    };

    //! Convert the renderer to the Metal renderer.
    //! @param renderer The renderer.
    //! @return The MetalRenderer.
    static MetalRenderer &toMetalRenderer(Renderer &renderer);
}

#endif

#endif //METAL_RENDERER_H
