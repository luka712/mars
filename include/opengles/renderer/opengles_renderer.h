//
// Created by Erkapic Luka on 2.1.2025.
//

#ifndef OPENGLES_RENDERER_H
#define OPENGLES_RENDERER_H

#include <SDL3/SDL.h>
#include "core/renderer/Renderer.h"

namespace mars {
    class Framework;

    class OpenGLESRenderer final : public Renderer {
    public:
        //! Construct a new OpenGLESRenderer object.
        //! @param framework The framework.
        //! @param frameBufferSize The frame buffer size.
        explicit OpenGLESRenderer(Framework &framework, glm::vec2 frameBufferSize);

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
    };

    //! From framework, find the @ref OpenGLESRenderer.
    //! @param framework The framework.
    //! @returns The @ref OpenGLESRenderer pointer.
    OpenGLESRenderer* findOpenGLESRenderer(const Framework &framework);

}


#endif //OPENGLESRENDERER_H
