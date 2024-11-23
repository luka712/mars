//
// Created by lukaa on 23.11.2024..
//

#include "Framework.h"
#include "sdl/renderer/SDLRenderer.h"

namespace mars {

    Framework::Framework(FrameworkOptions options){

        windowManager = std::make_unique<WindowManager>(WindowManagerOptions{
            options.windowBounds
        });

        this->renderer = std::make_unique<SDLRenderer>(*this);
    };

    Framework::~Framework() = default;

    void Framework::initialize() const {

        // WINDOW MANAGER
        windowManager->initialize();
        windowManager->subscribeToRenderEvent([&] {
            this->render();
        });

        // RENDERER
        renderer->initialize();

        windowManager->runEventLoop();
    }

    void Framework::render() const {
        renderer->beginRenderPass();

        renderer->endRenderPass();
    }

    void Framework::destroy() const {

        windowManager->destroy();
    }
}
