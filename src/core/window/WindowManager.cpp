//
// Created by lukaa on 22.11.2024..
//

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

#include "Framework.h"
#include "core/window/WindowManager.h"
#include <iostream>
#include <core/log/Logger.h>

using namespace mars;

WindowManager::WindowManager(Framework& framework, const WindowManagerOptions options)
    : framework(framework), windowBounds(options.windowBounds) {
}

void WindowManager::subscribeToRenderEvent(const std::function<void()>& callback) {
    renderEvents.push_back(callback);
}

void WindowManager::subscribeToUpdateEvent(const std::function<void()> &callback) {
    updateEvents.push_back(callback);
}

void WindowManager::initialize() {

    Logger& logger = framework.getLogger();

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        logger.error( std::string("Failed to initialize SDL: ") + SDL_GetError());
        return;
    }

    logger.info(std::string("Window initialized. Client size: ") + std::to_string(windowBounds.width) + ", " + std::to_string(windowBounds.height));

    window = SDL_CreateWindow("Mars Framework",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowBounds.width, windowBounds.height,
        0);
}

// Store a reference to the instance for the loop.
// Done to support EMSCRIPTEN.
static WindowManager* windowManagerInstance = nullptr;

static void mainLoop() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {

        if (event.type == SDL_KEYDOWN) {
            if (event.key.keysym.sym == SDLK_ESCAPE) {
                windowManagerInstance->running = false;
            }
        }

        if (event.type == SDL_QUIT) {
            windowManagerInstance->running = false;
        }
    }

    // Update
    for (auto& callback : windowManagerInstance->updateEvents) {
        callback();
    }

    // Render
    for (auto& callback : windowManagerInstance->renderEvents) {
        callback();
    }
}


void WindowManager::runEventLoop() {

    windowManagerInstance = this;
    running = true;

#ifdef __EMSCRIPTEN__
    emscripten_set_main_loop(mainLoop, 0, 1);
#else
    while (running) {
        mainLoop();
    }
#endif
}

void WindowManager::destroy() {
    SDL_DestroyWindow(window);
}
