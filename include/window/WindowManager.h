//
// Created by lukaa on 22.11.2024..
//

#ifndef WINDOWMANAGER_H
#define WINDOWMANAGER_H

#include <SDL.h>
#include <window/WindowManagerOptions.h>

namespace mars {
    class WindowManager {
    private:
        SDL_Window *window{};
        WindowBounds windowBounds;

    public:
        WindowManager(WindowManagerOptions options);

        /**
         * Get the window bounds.
         *
         * @return The window bounds.
         */
        [[nodiscard]] inline WindowBounds GetWindowBounds() const { return windowBounds; }

        /**
         * Initialize the window.
         */
        void Initialize();

        /**
         * Run the event loop.
         */
        void RunEventLoop();

        /**
         * Destroy the window.
         */
        void Destroy();
    };
}


#endif //WINDOWMANAGER_H
