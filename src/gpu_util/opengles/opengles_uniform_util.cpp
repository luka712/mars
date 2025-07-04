//
// Created by Erkapic Luka on 14.02.25.
//

#include "gpu_util/opengles/opengles_uniform_util.h"
#include <stdexcept>

namespace gpu_util {

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
