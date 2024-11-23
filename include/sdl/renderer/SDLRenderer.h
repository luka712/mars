//
// Created by lukaa on 23.11.2024.
//

#ifndef SDLRENDERER_H
#define SDLRENDERER_H

#include <SDL.h>
#include "renderer/Renderer.h"

namespace mars {

    //! The SDL implementation of the Renderer.
    class SDLRenderer : public Renderer {
        public:
            //! Construct a new Renderer object.
            explicit SDLRenderer(Framework& framework);

            //! @copydoc Renderer::initialize()
            void initialize() override;

            //! @copydoc Renderer::beginRenderPass()
            void beginRenderPass() override;

            //! @copydoc Renderer::endRenderPass()
            void endRenderPass() override;

            //! @copydoc Renderer::destroy()
            void destroy() override;

        private:
              SDL_Renderer *renderer;
    };
}



#endif //SDLRENDERER_H
