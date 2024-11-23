//
// Created by lukaa on 22.11.2024..
//

#include "window/WindowManager.h"
#include <iostream>

using namespace mars;

WindowManager::WindowManager(const WindowManagerOptions options)
    : windowBounds(options.windowBounds) {
}

void WindowManager::subscribeToRenderEvent(const std::function<void()>& callback) {
    renderEvents.push_back(callback);
}

void WindowManager::initialize() {

    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "Failed to initialize SDL" << std::endl;
        return;
    }

    window = SDL_CreateWindow("Mars Framework",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        windowBounds.width, windowBounds.height,
        0);
}

void WindowManager::runEventLoop() {
    SDL_Event event;
    while (true) {
        if (SDL_PollEvent(&event)) {

            if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    break;
                }
            }

            if (event.type == SDL_QUIT) {
                break;
            }
        }

        // Render
        for (auto& callback : renderEvents) {
            callback();
        }
    }
}

void WindowManager::destroy() {
    SDL_DestroyWindow(window);
}
