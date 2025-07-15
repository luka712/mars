//
// Created by Erkapic Luka on 2.1.2025.
//

#include <SDL3/SDL.h>
#include "Framework.h"
#include "opengles/renderer/opengles_renderer.h"
#include "gpu_util/opengles/opengles_util.h"

using namespace gpu_util;

namespace mars {
    static Logger *staticLogger = nullptr;

    void APIENTRY OpenGLESDebugCallback(GLenum source, GLenum type, GLuint id,
                                        GLenum severity, GLsizei length,
                                        const GLchar *message, const void *userParam) {
        if (type != GL_DEBUG_TYPE_ERROR && type != GL_DEBUG_TYPE_PERFORMANCE) {
            return;
        }

        std::string typeStr = type == GL_DEBUG_TYPE_ERROR ? "Error" : "Performance";

        std::string severityStr = "Unknown";
        switch (severity) {
            case GL_DEBUG_SEVERITY_HIGH:
                severityStr = "High";
                break;
            case GL_DEBUG_SEVERITY_MEDIUM:
                severityStr = "Medium";
                break;
            case GL_DEBUG_SEVERITY_LOW:
                severityStr = "Low";
                break;
            case GL_DEBUG_SEVERITY_NOTIFICATION:
                severityStr = "Notification";
                break;
        }

        const std::string msg = "OpenGLESDebugCallback: " + typeStr + " " + severityStr + ": " + std::string(message);
        staticLogger->warn(msg);
    }

    OpenGLESRenderer::OpenGLESRenderer(Framework &framework, const glm::vec2 frameBufferSize)
        : Renderer(framework), window(nullptr) {
        this->frameBufferSize = frameBufferSize;
    }

    void OpenGLESRenderer::initialize() {
        window = framework.getWindowManager().getWindow();
        Logger &logger = framework.getLogger();
        staticLogger = &logger;

        OpenGLESUtil::initialize(true);

#ifndef __EMSCRIPTEN__
        // gladLoadGLLoader(SDL_GL_GetProcAddress);
        gladLoadGLES2Loader((GLADloadproc) SDL_GL_GetProcAddress);
#endif
        std::string msg = "Open GLES initialized.\n";
        msg += "Vendor  : " + std::string((char *) glGetString(GL_VENDOR)) + "\n";
        msg += "Renderer: " + std::string((char *) glGetString(GL_RENDERER)) + "\n";
        msg += "Version : " + std::string((char *) glGetString(GL_VERSION)) + "\n";

        logger.info(msg);

        // TODO: move to function check extensions
        GLint numExtensions;
        glGetIntegerv(GL_NUM_EXTENSIONS, &numExtensions);

        logger.info("Supported extensions: ");
        for (GLint i = 0; i < numExtensions; ++i) {
            auto extension = reinterpret_cast<const char *>(glGetStringi(GL_EXTENSIONS, i));
            logger.info(extension);
        }

        // Debug. Note WebGL does not have glDebugMessageCallbackKHR.
#ifndef __EMSCRIPTEN__
        glEnable(GL_DEBUG_OUTPUT);
        glDebugMessageCallbackKHR(OpenGLESDebugCallback, nullptr);
#endif

        // Blending
        glEnable(GL_BLEND);
        glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    }

    void OpenGLESRenderer::beginRenderPass() {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, 1280, 720);
        glClearColor(clearColor.r, clearColor.g, clearColor.b, clearColor.a);
    }

    void OpenGLESRenderer::endRenderPass() {
        SDL_GL_SwapWindow(window);
    }

    void OpenGLESRenderer::destroy() {
    }

    OpenGLESRenderer *findOpenGLESRenderer(const Framework &framework) {
        return dynamic_cast<OpenGLESRenderer *>(&framework.getRenderer());
    }
}
