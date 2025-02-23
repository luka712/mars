//
// Created by luka on 11.02.25.
//

#ifndef OPENGLESTEXTUREUTIL_H
#define OPENGLESTEXTUREUTIL_H

#include <cstdint>
#include <core/log/Logger.h>
#include "opengles/opengles.h"
#include <string>

namespace mars {

    //! The OpenGLESTextureUtil class for working with OpenGLES textures.
    class OpenGLESTextureUtil {
    public:
        //! Construct a new OpenGLESConverterUtil object.
        //! @param logger The logger.
        explicit OpenGLESTextureUtil(Logger& logger);

        //! Create a new texture.
        //! @param width The width of the texture.
        //! @param height The height of the texture.
        //! @param format The format of the texture.
        //! @param internalFormat The internal format of the texture.
        //! @param type The type of the texture.
        //! @param data The data to initialize the texture with.
        //! @param label The label of the texture. By default, empty string.
        //! @return The texture ID.
        GLuint create(
            GLint width,
            GLint height,
            GLint format,
            GLint internalFormat,
            GLint type,
            const void* data,
            const std::string& label = "");

    private:
        Logger &logger;

        //! Validate the texture type.
        //! @param type The type of the texture.
        void validateTextureType(uint32_t type);

        //! Validate the texture format.
        //! @param internalFormat The format of the texture.
        void validateInternalFormat(uint32_t internalFormat);
    };
}



#endif //OPENGLESTEXTUREUTIL_H
