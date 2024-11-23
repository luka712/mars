//
// Created by lukaa on 23.11.2024..
//

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <glm/glm.hpp>
#include "window/WindowManager.h"

namespace mars {
    struct FrameworkOptions {
        /**
         * @brief The bounds of the window.
         */
        WindowBounds windowBounds;
    };

    class Framework {
    private:
        WindowManager *windowManager;

    public:
        Framework(FrameworkOptions options);

        /**
        * Gets the @ref WindowManager instance.
        */
        inline WindowManager &getWindowManager() { return *windowManager; }

        /**
        * Initialize the framework.
        */
        void Initialize();

        /**
        * Destroy the framework.
        */
        void Destroy();
    };
}

#endif //FRAMEWORK_H
