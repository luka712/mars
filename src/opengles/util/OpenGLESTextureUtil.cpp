//
// Created by Erkapic Luka on 11.02.25.
//

#include <stdexcept>
#include "opengles/util/OpenGLESTextureUtil.h"

namespace mars {
    OpenGLESTextureUtil::OpenGLESTextureUtil(Logger &logger) : logger(logger) {
    }

    GLuint OpenGLESTextureUtil::create(const int32_t width, const int32_t height, const GLint format, const GLint internalFormat, const GLint type, const void* data, const std::string& label)
    {
        validateTextureType(type);
        validateInternalFormat(internalFormat);

        GLuint texture;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, type, data);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

        // If there is sampling.
        //if (compareFunction != GLEnum.Never)
        {
          //  gl.TexParameterI(GLEnum.Texture2D, GLEnum.TextureCompareMode, (int)GLEnum.CompareRefToTexture);
           // gl.TexParameterI(GLEnum.Texture2D, GLEnum.TextureCompareFunc, (int) compareFunction);
        }

        // Generate mipmaps.
        //if (useMipMaps)
        {
          //  gl.GenerateMipmap(GLEnum.Texture2D);
        }

        // Set anisotropy.
       // if (anisotropy > 1.0f)
        {
         //   gl.TexParameter(GLEnum.Texture2D, GLEnum.TextureMaxAnisotropy, anisotropy);
        }

        if (glGetError() != GL_NO_ERROR)
        {
            const std::string msg = "Potential error occurred during setup of OpenGL texture.";
            logger.error(msg);
            throw std::runtime_error(msg);
        }

#ifndef __EMSCRIPTEN__
        if (!label.empty())
        {
            glObjectLabel(GL_TEXTURE_2D, texture, static_cast<GLsizei>(label.size()), label.c_str());
        }
#endif

        return texture;
    }

    void OpenGLESTextureUtil::validateTextureType(uint32_t type)
    {
    }

    void OpenGLESTextureUtil::validateInternalFormat(uint32_t internalFormat)
    {
    }
}
