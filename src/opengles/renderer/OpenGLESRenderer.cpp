//
// Created by Erkapic Luka on 2.1.2025.
//

#include <SDL.h>
#include <glad/glad.h>
#include "Framework.h"
#include "opengles/renderer/OpenGLESRenderer.h"

namespace mars {

    OpenGLESRenderer::OpenGLESRenderer(Framework &framework)
        : Renderer(framework), window(nullptr) {
    }

    void OpenGLESRenderer::initialize() {
        window = framework.getWindowManager().getWindow();
        Logger& logger = framework.getLogger();

        gladLoadGLLoader(SDL_GL_GetProcAddress);

        std::string msg = "Open GLES initialized.\n";
        msg += "Vendor  : " + std::string((char*)glGetString(GL_VENDOR)) + "\n";
        msg += "Renderer: " + std::string((char*)glGetString(GL_RENDERER)) + "\n";
        msg += "Version : " + std::string((char*)glGetString(GL_VERSION)) + "\n";

        logger.info(msg);
    }

    void OpenGLESRenderer::beginRenderPass() {
        glClear(GL_COLOR_BUFFER_BIT);
        glViewport(0, 0, 800, 600);
        glClearColor(1.0f,0.0f,1.0f,1.0f);
    }

    void OpenGLESRenderer::endRenderPass() {
        SDL_GL_SwapWindow(window);
    }

    void OpenGLESRenderer::destroy() {
    }

}
