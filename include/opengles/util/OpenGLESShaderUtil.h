//
// Created by luka on 14.02.25.
//

#ifndef OPENGLESSHADERUTIL_H
#define OPENGLESSHADERUTIL_H
#include <core/log/Logger.h>
#include "opengles/opengles.h"

namespace mars {

    //! The OpenGLES shader utility class.
    class OpenGLESShaderUtil {

        public:
        //! The constructor.
        //! @param logger The logger.
        explicit OpenGLESShaderUtil(Logger& logger);

        //! Creates the shader.
        //! @param source The source.
        //! @param type The type of shader.
        //! @param label The label. By default, it is empty string. If empty string it is not set.
        [[nodiscard]] GLuint create(const std::string& source, GLenum type, const std::string& label = "") const;

        //! Creates vertex shader.
        //! @param source The source.
        //! @param label The label. By default, it is empty string. If empty string it is not set.
        [[nodiscard]] GLuint createVertexShader(const std::string& source, const std::string& label = "") const;

        //! Creates fragment shader.
        //! @param source The source.
        //! @param label The label. By default, it is empty string. If empty string it is not set.
        [[nodiscard]] GLuint createFragmentShader(const std::string& source, const std::string& label = "") const;

    private:
        Logger& logger;
    };
}



#endif //OPENGLESSHADERUTIL_H
