//
// Created by lukaa on 23.11.2024.
//

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <memory>
#include "window/WindowManager.h"
#include "renderer/Renderer.h"

namespace mars {

    struct FrameworkOptions {
        /**
         * @brief The bounds of the window.
         */
        WindowBounds windowBounds;
    };

    /**
     * @brief The Framework class represents the framework
     * and entry point of the application.
     */
    class Framework {
    private:
        std::unique_ptr<WindowManager> windowManager;
        std::unique_ptr<Renderer> renderer;

    public:
        /**
        * Construct a new Framework object.
        *
        * @param options The options for the framework.
        */
        Framework(FrameworkOptions options);

        ~Framework();

        //! Gets the @ref WindowManager instance.
        //! @return The @ref WindowManager instance.
        inline WindowManager &getWindowManager() const { return *windowManager; }

        //! Gets the @ref Renderer instance.
        //! @return The @ref Renderer instance.
        inline Renderer &getRenderer() const { return *renderer; }

        //! Initialize the framework.
        void initialize() const;

        //! Render the frame.
        void render() const;

        //! Destroy the framework.
        void destroy() const;
    };
}

#endif //FRAMEWORK_H
