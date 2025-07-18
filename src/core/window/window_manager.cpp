//
// Created by Erkapic Luka on 22.11.2024.
//

#if __EMSCRIPTEN__
#include <emscripten.h>
#endif

#if __APPLE__
#include <metal/metal.h>
#include <SDL3/SDL_metal.h>
#endif

#include "Framework.h"
#include "core/window/window_manager.h"
#include "opengles/opengles.h"
#include <iostream>
#include <core/log/Logger.h>
#include <SDL3/SDL_system.h>
#include <SDL3/SDL_egl.h>
#include <SDL3/SDL_properties.h>
// #include <EGL/eglext.h>


using namespace mars;

WindowManager::WindowManager(Framework& framework, const WindowManagerOptions options)
	: framework(framework), window(nullptr), renderer(nullptr), windowBounds(options.windowBounds) {

#if __APPLE__
	metalLayer = nullptr;
#endif
}

#if _WIN32

HWND mars::WindowManager::getWin32Handle()
{
	SDL_PropertiesID props = SDL_GetWindowProperties(window);
	HWND hwnd = (HWND)SDL_GetPointerProperty(props, SDL_PROP_WINDOW_WIN32_HWND_POINTER, nullptr);
	return hwnd;
}

#endif

#if __APPLE__

/*
void* mars::WindowManager::getCocoaWindowHandle() {
    SDL_PropertiesID props = SDL_GetWindowProperties(window);
    return SDL_GetPointerProperty(props, SDL_PROPERTY_WINDOW_COCOA_WINDOW_POINTER, nullptr);
}
*/

#endif

void WindowManager::subscribeToRenderEvent(const std::function<void()>& callback) {
	renderEvents.push_back(callback);
}

void WindowManager::subscribeToUpdateEvent(const std::function<void()>& callback) {
	updateEvents.push_back(callback);
}

void WindowManager::initializeForSDL() {
	Logger& logger = framework.getLogger();

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS) != 0) {
		logger.error(std::string("Failed to initialize SDL: ") + SDL_GetError());
		return;
	}

	logger.info(
		std::string("Window initialized for SDL. Client size: ") + std::to_string(windowBounds.width) + ", " +
		std::to_string(windowBounds.height));

	window = SDL_CreateWindow("Mars Framework",
		windowBounds.width, windowBounds.height,
		0);
}

void WindowManager::InitializeSDL() const {
	Logger& logger = framework.getLogger();

	if (!SDL_InitSubSystem(SDL_INIT_VIDEO | SDL_INIT_EVENTS)) {
		const std::string msg = "WindowManager::InitializeSDL: Failed to initialize SDL. Error: " + std::string(SDL_GetError());
		logger.error(msg);
		throw std::runtime_error(msg);
	}
}

void WindowManager::initializeForOpenGLES(const int major, const int minor) {
	Logger& logger = framework.getLogger();

	InitializeSDL();

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
		windowBounds.width, windowBounds.height,
		SDL_WINDOW_OPENGL);

	if (window == nullptr) {
		std::string msg = std::string("WindowManager::initializeForOpenGLES: Failed to create window. Error: ") +
			SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}

	SDL_GLContext context = SDL_GL_CreateContext(window);
	if (context == nullptr) {
		const std::string msg = std::string(
			"WindowManager::initializeForOpenGLES: Failed to create OpenGL ES context. Error: ")
			+ SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}
}

void WindowManager::initializeForAngleOpenGLES(const int major, const int minor) {
	Logger& logger = framework.getLogger();

	InitializeSDL();
    
#if __APPLE__
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "metal"); // Force to use metal if apple device
#endif

    SDL_SetHint(SDL_HINT_OPENGL_ES_DRIVER, "1"); // Use "Angle".

	// Set SDL to use EGL
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	logger.info(
		"WindowManager::initializeForOpenGLES: Window initialized for OpenGLES(" + std::to_string(major) + ", " +
		std::to_string(minor) + ").");
	logger.info(
		"WindowManager::initializeForOpenGLES: Client size: " + std::to_string(windowBounds.width) + ", " +
		std::to_string(windowBounds.height) + ".");

	window = SDL_CreateWindow("Mars Framework",
		windowBounds.width, windowBounds.height,
        SDL_WINDOW_OPENGL);

	if (window == nullptr) {
		std::string msg = std::string("WindowManager::initializeForOpenGLES: Failed to create window. Error: ") +
			SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}

	SDL_GLContext context = SDL_GL_CreateContext(window);
	if (context == nullptr) {
		const std::string msg = std::string(
			"WindowManager::initializeForOpenGLES: Failed to create OpenGL ES context. Error: ")
			+ SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}

}

#if __APPLE__
void WindowManager::initializeForMetal() {
	Logger& logger = framework.getLogger();

	InitializeSDL();

	logger.info(
		"WindowManager::initializeForMetal: Client size: " + std::to_string(windowBounds.width) + ", " +
		std::to_string(windowBounds.height) + ".");

	SDL_CreateWindowAndRenderer(
        "Mars Framework",
        windowBounds.width, windowBounds.height,
		0,
		&window,
		&renderer);

	if (window == nullptr) {
		const std::string msg = std::string("WindowManager::initializeForMetal: Failed to create window. Error: ") +
			SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}

	if (renderer == nullptr) {
		const std::string msg = std::string("WindowManager::initializeForMetal: Failed to create renderer. Error: ") +
			SDL_GetError();
		logger.error(msg);
		throw std::runtime_error(msg);
	}

	metalLayer = static_cast<CA::MetalLayer*>(SDL_GetRenderMetalLayer(renderer));

	if (metalLayer == nullptr) {
		const std::string msg = "WindowManager::InitializeForMetal: Failed to get metal layer: " + std::string(SDL_GetError());
		logger.error(msg);
		throw std::runtime_error(msg.c_str());
	}

	// Log information about the device and if metal is linked.
	const NS::String* nsDeviceName = metalLayer->device()->name();
	const auto deviceName = std::string(nsDeviceName->cString(NS::StringEncoding::ASCIIStringEncoding));
	logger.info("SDLWindowManager::InitializeForMetal: Metal Enabled. Metal Device: " + deviceName + ".");
}
#endif


// Store a reference to the instance for the loop.
// Done to support EMSCRIPTEN.
static WindowManager* windowManagerInstance = nullptr;
static Framework* frameworkInstance = nullptr;

static void mainLoop() {
	SDL_Event event;

	if (SDL_PollEvent(&event)) {
		frameworkInstance->getInputManager().processEvent(event);

		if (event.type == SDL_EVENT_KEY_DOWN) {
			if (event.key.key == SDLK_ESCAPE) {
				windowManagerInstance->running = false;
			}
		}

		if (event.type == SDL_EVENT_QUIT) {
			windowManagerInstance->running = false;
		}
	}

	// Update
	for (auto& callback : windowManagerInstance->updateEvents) {
		callback();
	}

	// Render
	for (auto& callback : windowManagerInstance->renderEvents) {
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
