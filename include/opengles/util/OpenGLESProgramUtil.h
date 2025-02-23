//
// Created by Erkapic Luka on 14.02.25.
//

#ifndef OPEN_GLES_PROGRAM_UTIL_H
#define OPEN_GLES_PROGRAM_UTIL_H

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
        [[nodiscard]] GLuint create(GLuint vertexShader, GLuint fragmentShader, const std::string& label = "") const;

        private:
        Logger& logger;
    };
}



#endif //OPEN_GLES_PROGRAM_UTIL_H
