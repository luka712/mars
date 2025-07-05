//
// Created by Erkapic Luka on 14.02.25.
//

#include <stdexcept>
#include "gpu_util/opengles/opengles_shader_util.h"
#include "gpu_util/util/file_reader.h"

namespace gpu_util {
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

    GLuint OpenGLESShaderUtil::createFromFile(const std::string& filePath, const GLenum type, const std::string& label) const {
      
		std::string source = FileReader::readFile(filePath);

		return create(
			source,
			type,
			label
		);
    }

    GLuint OpenGLESShaderUtil::createVertexShaderFromFile(const std::string& filePath, const std::string& label) const {
        return createFromFile(filePath, GL_VERTEX_SHADER, label);
    }

    GLuint OpenGLESShaderUtil::createFragmentShaderFromFile(const std::string& filePath, const std::string& label) const {
        return createFromFile(filePath, GL_FRAGMENT_SHADER, label);
    }

}
