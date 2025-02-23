//
// Created by luka on 14.02.25.
//

#include "../../../include/opengles/util/OpenGLESProgramUtil.h"

#include <stdexcept>
#include <vector>

namespace mars {

    OpenGLESProgramUtil::OpenGLESProgramUtil(Logger &logger)
        :logger(logger){

    }

    GLuint OpenGLESProgramUtil::create(const GLuint vertexShader, const GLuint fragmentShader, const std::string& label) const {

        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

#ifndef __EMSCRIPTEN__
        if (!label.empty()) {
            glObjectLabel(GL_PROGRAM, program, static_cast<GLsizei>(label.size()), label.c_str());
        }
#endif

        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success );
        if (success == GL_FALSE) {
            GLint maxLength = 0;
            glGetProgramiv(program, GL_INFO_LOG_LENGTH, &maxLength);
            std::vector<GLchar> infoLog(maxLength);
            glGetProgramInfoLog(program, maxLength, &maxLength, &infoLog[0]);

            std::string msg = "Failed to link program: " + std::string(infoLog.begin(), infoLog.end());
            logger.error(msg);
            glDeleteProgram(program);
            throw std::runtime_error(msg);
        }

        return program;
    }
}
