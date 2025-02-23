//
// Created by Erkapic Luka on 14.02.25.
//

#include <stdexcept>
#include "opengles/util/OpenGLESShaderUtil.h"

namespace mars {
    OpenGLESShaderUtil::OpenGLESShaderUtil(Logger &logger)
        : logger(logger) {
    }

    GLuint OpenGLESShaderUtil::create(const std::string& source, const GLenum type, const std::string &label) const {
        GLuint shader = glCreateShader(type);
        const char* sourceCStr = source.c_str();
        glShaderSource(shader, 1, &sourceCStr, nullptr);
        glCompileShader(shader);

#ifndef __EMSCRIPTEN__
        if (!label.empty()) {
            glObjectLabel(GL_SHADER, shader, static_cast<GLsizei>(label.size()), label.c_str());
        }
#endif

        GLint status;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

        if (status <= 0) {
            char buffer[1024];
            glGetShaderInfoLog(shader, 1024, nullptr, buffer);

            std::string msg = "OpenGL shader compilation failed: " + std::string(buffer);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        return shader;
    }

    GLuint OpenGLESShaderUtil::createVertexShader(const std::string &source, const std::string &label) const {
        return create(source, GL_VERTEX_SHADER, label);
    }

    GLuint OpenGLESShaderUtil::createFragmentShader(const std::string &source, const std::string &label) const {
        return create(source, GL_FRAGMENT_SHADER, label);
    }


}
