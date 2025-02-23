//
// Created by Erkapic Luka on 14.02.25.
//

#ifndef OPEN_GLES_UNIFORM_UTIL_H
#define OPEN_GLES_UNIFORM_UTIL_H

#include "opengles/opengles.h"
#include "core/log/Logger.h"

namespace mars {
    class OpenGLESUniformUtil {
        public:
        //! The constructor.
        //! @param logger The logger.
        explicit OpenGLESUniformUtil(Logger& logger);

        //! Gets the location of uniform.
        //! @param program The program.
        //! @param name The name of the uniform.
        //! @returns The uniform.
        GLint getUniformLocation(GLuint program, const char* name) const;

        //! Gets the location of uniform.
        //! @param program The program.
        //! @param name The name of the uniform.
        //! @returns The uniform.
        [[nodiscard]] GLint getUniformLocation(GLuint program,const std::string& name) const;

    private:
        Logger& logger;
    };
}



#endif //OPEN_GLES_UNIFORM_UTIL_H
