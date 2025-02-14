//
// Created by luka on 14.02.25.
//

#include "../../../include/opengles/util/OpenGLESUniformUtil.h"
#include <stdexcept>

namespace mars {

    OpenGLESUniformUtil::OpenGLESUniformUtil(Logger& logger)
        : logger(logger) {}

    GLint OpenGLESUniformUtil::getUniformLocation(const GLuint program, const char *name) const {
        const GLint uniform = glGetUniformLocation(program, name);
        if (uniform < 0) {
            const std::string msg = "Uniform \"" + std::string(name) + "\" not found";
            logger.error(msg);
            throw std::runtime_error(msg);
        }
        return uniform;
    }

    GLint OpenGLESUniformUtil::getUniformLocation(const GLuint program, const std::string& name) const {
        return getUniformLocation(program, name.c_str());
    }

}
