//
// Created by lukaa on 2.1.2025..
//

#ifndef OPENGLESRENDERER_H
#define OPENGLESRENDERER_H

#include <SDL.h>
#include "core/renderer/Renderer.h"

namespace mars {
    class Framework;

    class OpenGLESRenderer final : public Renderer {
    public:
        //! Construct a new OpenGLESRenderer object.
        //! @param framework The framework.
        explicit OpenGLESRenderer(Framework &framework);

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
}


#endif //OPENGLESRENDERER_H
