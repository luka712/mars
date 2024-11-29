//
// Created by lukaa on 23.11.2024.
//

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <memory>
#include "core/life_management/State.h"
#include "core/window/WindowManager.h"
#include "core/renderer/Renderer.h"
#include "core/sprite/SpriteBatch.h"
#include "core/time/TimeManager.h"

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

    public:
        /**
        * Construct a new Framework object.
        *
        * @param options The options for the framework.
        */
        explicit Framework(FrameworkOptions options);

        ~Framework();

        //! Gets the @ref WindowManager instance.
        //! @return The @ref WindowManager instance.
        [[nodiscard]] WindowManager &getWindowManager() const { return *windowManager; }

        //! Gets the @ref Renderer instance.
        //! @return The @ref Renderer instance.
        [[nodiscard]] Renderer &getRenderer() const { return *renderer; }

        //! Gets the @ref SpriteBatch instance.
        //! @return The @ref SpriteBatch instance.
        [[nodiscard]] SpriteBatch &getSpriteBatch() const { return *spriteBatch; }

        //! Gets the @ref TimeManager instance.
        //! @return The @ref TimeManager instance.
        [[nodiscard]] TimeManager& getTimeManager() const { return *timeManager; }

        //! Subscribe to the render event.
        //! @param callback The callback to subscribe.
        void subscribeToRenderEvent(const std::function<void()>& callback);

        //! Initialize the framework.
        void initialize();

        //! Update the framework.
        void update() const;

        //! Render the frame.
        void render() const;

        //! Destroy the framework.
        void destroy() const;

    private:
        // FIELDS
        State currentState;
        std::unique_ptr<WindowManager> windowManager;
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<SpriteBatch> spriteBatch;
        std::unique_ptr<TimeManager> timeManager;

        // EVENTS
        std::vector<std::function<void()>> onRender;
    };
}

#endif //FRAMEWORK_H
