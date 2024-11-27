//
// Created by lukaa on 23.11.2024..
//

#ifndef WINDOWMANAGEROPTIONS_H
#define WINDOWMANAGEROPTIONS_H

#include "core/window/WindowBounds.h"


namespace mars {

    /**
     * @brief The WindowManagerOptions struct represents the options for the window manager.
     */
    struct WindowManagerOptions {

        /**
         * @brief Construct a new WindowManagerOptions object.
         */
        WindowManagerOptions(): WindowManagerOptions(WindowBounds(800, 600)) {}

        /**
        * @brief Construct a new WindowManagerOptions object.
        *
        * @param windowBounds The bounds of the window.
        */
        explicit WindowManagerOptions(WindowBounds windowBounds): windowBounds(windowBounds) {}

        /**
         * @brief The bounds of the window.
         */
        WindowBounds windowBounds;

    };
}
#endif //WINDOWMANAGEROPTIONS_H
