//
// Created by Luka on 23.11.2024.
//

#ifndef FRAMEWORK_H
#define FRAMEWORK_H

#include <memory>
#include <core/loaders/FileReader.h>
#include "core/life_management/State.h"
#include "core/window/WindowManager.h"
#include "core/renderer/Renderer.h"
#include "core/sprite/SpriteBatch.h"
#include "core/time/TimeManager.h"
#include "core/log/Logger.h"
#include "core/loaders/ImageLoader.h"
#include "core/texture/TextureFactory.h"
#include "core/content/ContentManager.h"
#include "core/input/InputManager.h"
#include "core/renderer/enums.h"
#include "core/loaders/SpriteFontLoader.h"
#include "core/fonts/SpriteFontManager.h"
#include "core/buffers/BuffersFactory.h"
#include "core/camera/CameraFactory.h"
#include "core/pipelines/PipelineFactory.h"
#include "core/mesh/MeshFactory.h"
#include "core/geometry/GeometryBuilder.h"
#include "core/sprite/SpriteBatch.h"

namespace mars {

    struct FrameworkOptions {
        //! The window bounds.
        WindowBounds windowBounds;

        //! The rendering backend.
        RenderingBackend renderingBackend;

        //! The frame buffer size.
        glm::vec2 frameBufferSize;
    };

    /**
     * @brief The Framework class represents the framework
     * and entry point of the application.
     */
    class Framework {

    public:
        //! Construct a new Framework object.
        //! @param options The options for the framework.
        explicit Framework(FrameworkOptions options);

        ~Framework();

        //! Gets the used rendering backend.
        //! @return The used rendering backend.
        [[nodiscard]] RenderingBackend getRenderingBackend() const { return renderingBackend; }

        //! Gets the @ref WindowManager instance.
        //! @return The @ref WindowManager instance.
        [[nodiscard]] WindowManager &getWindowManager() const { return *windowManager; }

        //! Gets the @ref Renderer instance.
        //! @return The @ref Renderer instance.
        [[nodiscard]] Renderer& getRenderer() const { return *renderer; }

        //! Gets the @ref SpriteBatch instance.
        //! @return The @ref SpriteBatch instance.
        [[nodiscard]] SpriteBatch &getSpriteBatch() const { return *spriteBatch; }

        //! Gets the @ref TimeManager instance.
        //! @return The @ref TimeManager instance.
        [[nodiscard]] TimeManager& getTimeManager() const { return *timeManager; }

        //! Gets the @ref Logger instance.
        //! @return The @ref Logger instance.
        [[nodiscard]] Logger& getLogger() const { return *logger; }

        //! Gets the @ref ImageLoader instance.
        //! @return The @ref ImageLoader instance.
        [[nodiscard]] ImageLoader& getImageLoader() const { return *imageLoader; }

        //! Gets the @ref TextureFactory instance.
        //! @return The @ref TextureFactory instance.
        [[nodiscard]] TextureFactory& getTextureFactory() const { return *textureFactory; }

        //! Gets the @ref ContentManager instance.
        //! @return The @ref ContentManager instance.
        [[nodiscard]] ContentManager& getContentManager() const { return *contentManager; }

        //! Gets the @ref InputManager instance.
        //! @return The @ref InputManager instance.
        [[nodiscard]] InputManager& getInputManager() const { return *inputManager; }

        //! Gets the @ref SpriteFontLoader instance.
        //! @return The @ref SpriteFontLoader instance.
        [[nodiscard]] SpriteFontLoader& getSpriteFontLoader() const { return *spriteFontLoader; }

        //! Gets the @ref SpriteFontManager instance.
        //! @return The @ref SpriteFontManager instance.
        [[nodiscard]] SpriteFontManager& getSpriteFontManager() const { return *spriteFontManager; }

        //! Gets the @ref FileReader instance.
        //! @return The @ref FileReader instance.
        [[nodiscard]] FileReader& getFileReader() const { return *fileReader; }

        //! Gets the @ref BuffersFactory instance.
        //! @return The @ref BuffersFactory instance.
        [[nodiscard]] BuffersFactory& getBuffersFactory() const { return *buffersFactory; }

        //! Gets the @ref CameraFactory instance.
        //! @return The @ref CameraFactory instance.
        [[nodiscard]] CameraFactory& getCameraFactory() const { return *cameraFactory; }

        //! Gets the @ref PipelineFactory instance.
        //! @return The @ref PipelineFactory instance.
        [[nodiscard]] PipelineFactory& getPipelineFactory() const { return *pipelineFactory; }

        //! Gets the @ref MeshFactory instance.
        //! @return The @ref MeshFactory instance.
        [[nodiscard]] MeshFactory& getMeshFactory() const { return *meshFactory; }

        //! Gets the @ref GeometryBuilder instance.
        //! @return The @ref GeometryBuilder instance.
        [[nodiscard]] GeometryBuilder& getGeometryBuilder() const { return *geometryBuilder; }

        //! Subscribe to the update event.
        //! @param callback The callback to subscribe.
        void subscribeToUpdateEvent(const std::function<void(const Time time)>& callback);

        //! Subscribe to the render event.
        //! @param callback The callback to subscribe.
        void subscribeToRenderEvent(const std::function<void()>& callback);

        //! Initialize the framework.
        void initialize();

        //! Run the event loop.
        void runEventLoop() const;

        //! Update the framework.
        void update() const;

        //! Render the frame.
        void render() const;

        //! Destroy the framework.
        void destroy() const;

    private:
        // FIELDS
        State currentState;
        RenderingBackend renderingBackend;
        std::unique_ptr<WindowManager> windowManager;
        std::unique_ptr<Renderer> renderer;
        std::unique_ptr<SpriteBatch> spriteBatch;
        std::unique_ptr<TimeManager> timeManager;
        std::unique_ptr<Logger> logger;
        std::unique_ptr<ImageLoader> imageLoader;
        std::unique_ptr<TextureFactory> textureFactory;
        std::unique_ptr<ContentManager> contentManager;
        std::unique_ptr<InputManager> inputManager;
        std::unique_ptr<SpriteFontLoader> spriteFontLoader;
        std::unique_ptr<SpriteFontManager> spriteFontManager;
        std::unique_ptr<FileReader> fileReader;
        std::unique_ptr<BuffersFactory> buffersFactory;
        std::unique_ptr<CameraFactory> cameraFactory;
        std::unique_ptr<PipelineFactory> pipelineFactory;
        std::unique_ptr<MeshFactory> meshFactory;
        std::unique_ptr<GeometryBuilder> geometryBuilder;

        // EVENTS
        std::vector<std::function<void(const Time time)>> onUpdate;
        std::vector<std::function<void()>> onRender;
    };
}

#endif //FRAMEWORK_H
