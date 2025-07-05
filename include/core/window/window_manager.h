//
// Created by Erkapic Luka on 22.11.2024.
//

#ifndef WINDOWMANAGER_H

#define WINDOWMANAGER_H

#include <functional>
#include <SDL2/SDL.h>
#include <vector>
#include "core/window/WindowManagerOptions.h"
#include <SDL2/SDL_syswm.h>

#if __APPLE__
#include <metal-cpp/QuartzCore/CAMetalLayer.hpp>
using namespace MTL;
#endif

namespace mars {
    class Framework;

    //! The window manager.
    class WindowManager {
    public:
        bool running = true;
        std::vector<std::function<void()> > updateEvents;
        std::vector<std::function<void()> > renderEvents;

        //! Construct a new WindowManager object.
        //! @param framework The @see Framework.
        //! @param options The options for the window manager.
        explicit WindowManager(Framework &framework, WindowManagerOptions options);

        //! Get the window.
        //! @return The window.
        [[nodiscard]] SDL_Window *getWindow() const { return window; }

        //! Get the window bounds.
        //! @return The window bounds.
        [[nodiscard]] WindowBounds getWindowBounds() const { return windowBounds; }

#if _WIN32
        //! Get the win32 handle of the window.
        //! @return The HWND handle of the window.
        HWND getWin32Handle();
#endif 

#if __APPLE__

        //! Gets the cocoa window handle.
        //! The cocoa window handle.
        NSWindow* getCocoaWindowHandle();

        //! Gets the metal layer.
        //! The metal layer.
        [[nodiscard]] CA::MetalLayer *getMetalLayer() const { return metalLayer; }

#endif

        //! Subscribe to the update event.
        //! @param callback The callback to subscribe.
        void subscribeToUpdateEvent(const std::function<void()> &callback);

        //! Subscribe to the render event.
        //! @param callback The callback to subscribe.
        void subscribeToRenderEvent(const std::function<void()> &callback);

        //! Initialize the window.
        void initializeForSDL();

        //! Initialize the window for OpenGLES API.
        //! @param major The major version of OpenGLES.
        //! @param minor The minor version of OpenGLES.
        void initializeForOpenGLES(int major = 3, int minor = 0);

            //! Initialize the window for OpenGLES API throught the ANGLE project.
            //! @param major The major version of OpenGLES.
            //! @param minor The minor version of OpenGLES.
        void initializeForAngleOpenGLES(int major = 3, int minor = 0);

#if __APPLE__
        //! Initialize the window for working with Metal API.
        void initializeForMetal();
#endif

        //! Run the event loop.
        void runEventLoop();

        //! Destroy the window.
        void destroy();

    private:
        Framework &framework;
        SDL_Window *window;
        //! It's possible for renderer to be nullptr depending on implementation of backend.
        SDL_Renderer *renderer;
        WindowBounds windowBounds;

#if __APPLE__
        CA::MetalLayer *metalLayer{};
#endif

        //! Calls the SDL_Init() internally and setup sdl.
        void InitializeSDL() const;
    };
}


#endif //WINDOWMANAGER_H
