//
// Created by lukaa on 22.11.2024
//

#ifndef WINDOWMANAGER_H

#define WINDOWMANAGER_H

#include <functional>
#include <SDL.h>
#include <vector>
#include "core/window/WindowManagerOptions.h"

namespace mars {
    //! The window manager.
    class WindowManager {
    private:
        SDL_Window *window{};
        WindowBounds windowBounds;

        std::vector<std::function<void()>> updateEvents;
        std::vector<std::function<void()>> renderEvents;

    public:
        //! Construct a new WindowManager object.
        //! @param options The options for the window manager.
        explicit WindowManager(WindowManagerOptions options);

        //! Get the window.
        //! @return The window.
        [[nodiscard]]
        inline SDL_Window *getWindow() const { return window; }

        //! Get the window bounds.
        //! @return The window bounds.
        [[nodiscard]] inline WindowBounds getWindowBounds() const { return windowBounds; }

        //! Subscribe to the update event.
        //! @param callback The callback to subscribe.
        void subscribeToUpdateEvent(const std::function<void()> &callback);

        //! Subscribe to the render event.
        //! @param callback The callback to subscribe.
        void subscribeToRenderEvent(const std::function<void()> &callback);

        //! Initialize the window.
        void initialize();

        //! Run the event loop.
        void runEventLoop();

        //! Destroy the window.
        void destroy();
    };
}


#endif //WINDOWMANAGER_H
