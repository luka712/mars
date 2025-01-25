//
// Created by lukaa on 23.11.2024..
//

#include "Framework.h"
#include "sdl/renderer/SDLRenderer.h"
#include "opengles/renderer/OpenGLESRenderer.h"
#include "sdl/sprite/SDLSpriteBatch.h"
#include "opengles/sprite/OpenGLESSpriteBatch.h"

#ifdef __EMSCRIPTEN__
#include "core/log/BrowserLogger.h"
#else
#include "core/log/SpdLogger.h"
#endif
namespace mars {
    Framework::Framework(FrameworkOptions options)
    {
        currentState = State::CREATED;
        renderingBackend = options.renderingBackend;
        onRender.resize(0);

        windowManager = std::make_unique<WindowManager>(*this, WindowManagerOptions{
            options.windowBounds
        });

        if (renderingBackend == RenderingBackend::SDL) {
            this->renderer = std::make_unique<SDLRenderer>(*this);
            this->spriteBatch = std::make_unique<SDLSpriteBatch>(*this);
        }
        else {
            this->renderer = std::make_unique<OpenGLESRenderer>(*this);
            this->spriteBatch = std::make_unique<OpenGLESSpriteBatch>(*this);
        }

        this->timeManager = std::make_unique<TimeManager>();
        this->imageLoader = std::make_unique<ImageLoader>(*this);
        this->textureFactory = std::make_unique<TextureFactory>(*this);
        this->contentManager = std::make_unique<ContentManager>(*this);
        this->inputManager = std::make_unique<InputManager>(*this);
        this->spriteFontLoader = std::make_unique<SpriteFontLoader>(*this);
        this->spriteFontManager = std::make_unique<SpriteFontManager>(*this);
        this->fileLoader = std::make_unique<FileLoader>(*this);
        this->buffersFactory = std::make_unique<BuffersFactory>(*this);
#ifdef __EMSCRIPTEN__
        this->logger = std::make_unique<BrowserLogger>();
#else
        this->logger = std::make_unique<SpdLogger>();
#endif
    };

    Framework::~Framework() = default;

    void Framework::subscribeToUpdateEvent(const std::function<void(const Time)> &callback) {
        onUpdate.push_back(callback);
    }

    void Framework::subscribeToRenderEvent(const std::function<void()> &callback) {
        onRender.push_back(callback);
    }

    void Framework::initialize() {

        // Initialize window manager for appropriate rendering backend.
        if (renderingBackend == RenderingBackend::SDL) {
            windowManager->initializeForSDL();
        }
        else {
#if __EMSCRIPTEN__
            windowManager->initializeForOpenGLES(3, 0);
#else
            windowManager->initializeForOpenGLES();
#endif
        }

        windowManager->subscribeToUpdateEvent([&] {
            this->update();
        });
        windowManager->subscribeToRenderEvent([&] {
            this->render();
        });

        // RENDERER
        renderer->initialize();
        spriteBatch->initialize();
        // TODO: uncomment
        // spriteFontManager->initialize();

        logger->info("Framework initialized");

        // Should be called right before the first frame starts.
        timeManager->prepareStart();

        currentState = State::INITIALIZED;
    }

    void Framework::runEventLoop() const {
        windowManager->runEventLoop();
    }


    void Framework::update() const {

        if (currentState != State::INITIALIZED) {
            return;
        }

        // - FRAME START
        timeManager->frameStart();

        for (auto& updateCallback: onUpdate) {
            updateCallback(timeManager->getTime());
        }
    }

    void Framework::render() const {

        if (currentState != State::INITIALIZED) {
            return;
        }

        // - COMPUTE

        // - RENDER
        renderer->beginRenderPass();
        for (auto &renderCallback: onRender) {
            renderCallback();
        }
        renderer->endRenderPass();

        // - FRAME END
        timeManager->frameEnd();
    }

    void Framework::destroy() const {
        windowManager->destroy();
    }
}
