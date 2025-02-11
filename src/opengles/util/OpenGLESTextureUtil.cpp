//
// Created by luka on 11.02.25.
//

#include "../../../include/opengles/util/OpenGLESTextureUtil.h"

#include <stdexcept>
#include <../../../cmake-build-debug/vendor/glad/include/glad/glad.h>

namespace mars {
    OpenGLESTextureUtil::OpenGLESTextureUtil(Logger &logger) : logger(logger) {
    }

    GLuint OpenGLESTextureUtil::create(int32_t width, int32_t height, GLint format, GLint internalFormat, GLint type, const void* data, const std::string& label)
    {
        validateTextureType(type);
        validateInternalFormat(internalFormat);

        GLuint texture;
        glGenTextures(1, &texture);

        glBindTexture(GL_TEXTURE_2D, texture);
        glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, width, height, 0, format, type, data);
        // TODO: pass parameters
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
            std::string msg = "Potential error occurred during setup of OpenGL texture.";
            logger.error(msg);
            throw new std::runtime_error(msg);
        }
        if (!label.empty())
        {
            glObjectLabel(GL_TEXTURE_2D, texture, static_cast<GLsizei>(label.size()), label.c_str());
        }

        return texture;
    }

    void OpenGLESTextureUtil::validateTextureType(uint32_t type)
    {
    }

    void OpenGLESTextureUtil::validateInternalFormat(uint32_t internalFormat)
    {
    }
}
