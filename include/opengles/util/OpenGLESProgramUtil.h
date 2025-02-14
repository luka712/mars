//
// Created by luka on 14.02.25.
//

#ifndef OPENGLESPROGRAMUTIL_H
#define OPENGLESPROGRAMUTIL_H

#include "opengles/opengles.h"
#include "core/log/Logger.h"

namespace mars {
    class OpenGLESProgramUtil {

public:
        //! The constructor.
        //! @param logger The logger.
        explicit OpenGLESProgramUtil(Logger& logger);

        //! Create OpenGLES program.
        //! @param vertexShader The vertex shader.
        //! @param fragmentShader The fragment shader.
        //! @param label The label. By default, it is empty. If empty, it is not set.
        //! @return The program id.
        GLuint create(GLuint vertexShader, GLuint fragmentShader, const std::string& label = "") const;

        private:
        Logger& logger;
    };
}



#endif //OPENGLESPROGRAMUTIL_H
