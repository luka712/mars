//
// Created by lukaa on 23.11.2024..
//

#include "Framework.h"
#include "sdl/renderer/SDLRenderer.h"
#include "sdl/sprite/SDLSpriteBatch.h"

namespace mars {

    Framework::Framework(FrameworkOptions options){

        onRender.resize(0);

        windowManager = std::make_unique<WindowManager>(WindowManagerOptions{
            options.windowBounds
        });

        this->renderer = std::make_unique<SDLRenderer>(*this);
        this->spriteBatch = std::make_unique<SDLSpriteBatch>(*this);
    };

    Framework::~Framework() = default;

    void Framework::subscribeToRenderEvent(const std::function<void()>& callback) {
        onRender.push_back(callback);
    }

    void Framework::initialize() const {

        // WINDOW MANAGER
        windowManager->initialize();
        windowManager->subscribeToRenderEvent([&] {
            this->render();
        });

        // RENDERER
        renderer->initialize();
        spriteBatch->initialize();

        windowManager->runEventLoop();
    }

    void Framework::render() const {

        renderer->beginRenderPass();

        for (auto& renderCallback : onRender) {
            renderCallback();
        }

        renderer->endRenderPass();
    }

    void Framework::destroy() const {

        windowManager->destroy();
    }
}
