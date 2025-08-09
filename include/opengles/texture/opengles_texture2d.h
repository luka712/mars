//
// Created by luka erkapic on 11.02.25.
//

#ifndef OPEN_GLES_TEXTURE2D_H
#define OPEN_GLES_TEXTURE2D_H

#include <string>
#include "opengles/opengles.h"
#include "core/log/Logger.h"
#include "core/texture/a_texture2d.h"
#include "core/data/ImageData.h"

namespace mars
{
    class Framework;

    //! The OpenGLES implementation of the Texture2D.
    class OpenGLESTexture2D : public ATexture2D {
    public:
        //! Construct a new OpenGLESTexture2D object.
        //! @param framework The framework.
        //! @param imageData The image data.
        //! @param label The label.
        OpenGLESTexture2D(Framework& framework,
            const ImageData& imageData,
            const std::string& label = "");

        //! Get the texture.
        [[nodiscard]] uint32_t getTexture() const { return texture; }

        //! @inheritDoc
        void destroy() override;

        //! @inheritDoc
        std::string printInfo() override;
    private:
        Framework& framework;
        Logger& logger;
        //! The OpenGL texture.
        GLuint texture = 0;
    };

    //! Converts the @ref ATexture2D to the @ref OpenGLESTexture2D
    //! @param texture The @ref ATexture2D
    //! @returns The OpenGLESTexture2D.
    OpenGLESTexture2D* asOpenGLESTexture(ATexture2D* texture);
}

#endif //OPEN_GLES_TEXTURE2D_H
