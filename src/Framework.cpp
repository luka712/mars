//
// Created by lukaa on 23.11.2024..
//

#include "Framework.h"
#include "sdl/renderer/SDLRenderer.h"
#include "sdl/sprite/SDLSpriteBatch.h"

namespace mars {
    Framework::Framework(FrameworkOptions options) {
        currentState = State::CREATED;
        onRender.resize(0);

        windowManager = std::make_unique<WindowManager>(WindowManagerOptions{
            options.windowBounds
        });

        this->renderer = std::make_unique<SDLRenderer>(*this);
        this->spriteBatch = std::make_unique<SDLSpriteBatch>(*this);
        this->timeManager = std::make_unique<TimeManager>();
    };

    Framework::~Framework() = default;

    void Framework::subscribeToRenderEvent(const std::function<void()> &callback) {
        onRender.push_back(callback);
    }

    void Framework::initialize() {
        // WINDOW MANAGER
        windowManager->initialize();
        windowManager->subscribeToUpdateEvent([&] {
            this->update();
        });
        windowManager->subscribeToRenderEvent([&] {
            this->render();
        });

        // RENDERER
        renderer->initialize();
        spriteBatch->initialize();

        // Should be called right before the first frame starts.
        timeManager->prepareStart();

        currentState = State::INITIALIZED;

        windowManager->runEventLoop();
    }

    void Framework::update() const {

        if (currentState != State::INITIALIZED) {
            return;
        }

        // - FRAME START
        timeManager->frameStart();
    }

    void Framework::render() const {

        if (currentState != State::INITIALIZED) {
            return;
        }

        // - COMPUTE

        // - RENDER
        renderer->beginRenderPass();
        for (auto &renderCallback: onRender) {
            renderCallback();
        }
        renderer->endRenderPass();

        // - FRAME END
        timeManager->frameEnd();
    }

    void Framework::destroy() const {
        windowManager->destroy();
    }
}
