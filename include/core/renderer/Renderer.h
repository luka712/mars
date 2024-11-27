//
// Created by lukaa on 23.11.2024..
//

#ifndef RENDERER_H
#define RENDERER_H

#include "core/math/Color.h"

namespace mars {
    class Framework;

    //! The Renderer class represents the renderer.
     class Renderer {
        public:
            //! The clear color of the renderer.
            Color clearColor = Color::lightPink();

            //! Destroy the Renderer object.
            virtual ~Renderer() = default;

            //! Construct a new Renderer object.
            explicit Renderer(Framework &framework);

            //! Initialize the renderer.
            virtual void initialize() = 0;

            //! Should be called at the beginning of the frame.
            //! Clears the buffer and prepares the renderer for rendering.
            virtual void beginRenderPass() = 0;

            //! Should be called at the end of the frame.
            //! Ends the rendering and submits the frame to the screen.
            virtual void endRenderPass() = 0;

            //! Destroy the renderer.
            virtual void destroy() = 0;

        protected:
            Framework &framework;
    };
}


#endif //RENDERER_H
