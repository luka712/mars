//
// Created by Erkapic Luka on 23.11.2024.
//

#include <stdexcept>
#include "Framework.h"
#include "sdl/renderer/SDLRenderer.h"

namespace mars {

    SDLRenderer::SDLRenderer(Framework& framework) : Renderer(framework) {
    }

    void SDLRenderer::initialize() {
        WindowManager& windowManager = framework.getWindowManager();
        SDL_Window* window = windowManager.getWindow();

        renderer = SDL_CreateRenderer(window, -1, 0);
        if(!renderer) {
            std::string msg = "Failed to create renderer: " + std::string(SDL_GetError());
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }
    }

    void SDLRenderer::beginRenderPass() {
        SDL_SetRenderDrawColor( renderer,
            static_cast<uint8_t>(clearColor.r * 255),
            static_cast<uint8_t>(clearColor.g * 255),
            static_cast<uint8_t>(clearColor.b * 255),
            static_cast<uint8_t>(clearColor.a * 255)
        );
        SDL_RenderClear( renderer );
    }

    void SDLRenderer::endRenderPass() {
        SDL_RenderPresent( renderer );
    }

    void SDLRenderer::destroy() {
        SDL_DestroyRenderer(renderer);
    }

}
