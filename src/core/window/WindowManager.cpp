//
// Created by Erkapic Luka on 22.11.2024.
//

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif


#include "opengles/opengles.h"
#include "Framework.h"
#include "core/window/WindowManager.h"
#include <iostream>
#include <core/log/Logger.h>

using namespace mars;

WindowManager::WindowManager(Framework &framework, const WindowManagerOptions options)
    : framework(framework), windowBounds(options.windowBounds) {
}

void WindowManager::subscribeToRenderEvent(const std::function<void()> &callback) {
    renderEvents.push_back(callback);
}

void WindowManager::subscribeToUpdateEvent(const std::function<void()> &callback) {
    updateEvents.push_back(callback);
}

void WindowManager::initializeForSDL() {
    Logger &logger = framework.getLogger();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        logger.error(std::string("Failed to initialize SDL: ") + SDL_GetError());
        return;
    }

    logger.info(
        std::string("Window initialized for SDL. Client size: ") + std::to_string(windowBounds.width) + ", " +
        std::to_string(windowBounds.height));

    window = SDL_CreateWindow("Mars Framework",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              windowBounds.width, windowBounds.height,
                              0);
}

void WindowManager::initializeForOpenGLES(const int major, const int minor) {
    Logger &logger = framework.getLogger();

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
        std::string msg = std::string("WindowManager::initializeForOpenGLES: Failed to initialize SDL. Error: ") + SDL_GetError();
        logger.error(msg);
        throw std::runtime_error(msg);
    }

    // Set OpenGL ES version
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);

    logger.info(
        "WindowManager::initializeForOpenGLES: Window initialized for OpenGLES(" + std::to_string(major) + ", " +
        std::to_string(minor) + ").");
    logger.info(
        "WindowManager::initializeForOpenGLES: Client size: " + std::to_string(windowBounds.width) + ", " +
        std::to_string(windowBounds.height) + ".");

    window = SDL_CreateWindow("Mars Framework",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              windowBounds.width, windowBounds.height,
                              SDL_WINDOW_OPENGL);

    if (window == NULL) {
        std::string msg = std::string("WindowManager::initializeForOpenGLES: Failed to create window. Error: ") + SDL_GetError();
        logger.error(msg);
        throw std::runtime_error(msg);
    }

    SDL_GLContext context = SDL_GL_CreateContext(window);
    if (context == nullptr) {
        const std::string msg = std::string("WindowManager::initializeForOpenGLES: Failed to create OpenGL ES context. Error: ") + SDL_GetError();
        logger.error(msg);
        throw std::runtime_error(msg);
    }
}

// Store a reference to the instance for the loop.
// Done to support EMSCRIPTEN.
static WindowManager *windowManagerInstance = nullptr;
static Framework *frameworkInstance = nullptr;

static void mainLoop() {
    SDL_Event event;

    if (SDL_PollEvent(&event)) {
        frameworkInstance->getInputManager().processEvent(event);

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
    for (auto &callback: windowManagerInstance->updateEvents) {
        callback();
    }

    // Render
    for (auto &callback: windowManagerInstance->renderEvents) {
        callback();
    }
}


void WindowManager::runEventLoop() {
    windowManagerInstance = this;
    frameworkInstance = &framework;

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
