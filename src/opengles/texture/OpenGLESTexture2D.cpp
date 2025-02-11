//
// Created by luka on 11.02.25.
//

#include <sstream>
#include "opengles/texture/OpenGLESTexture2D.h"

#include <Framework.h>

#include "opengles/util/OpenGLESUtil.h"

namespace mars
{
    OpenGLESTexture2D::OpenGLESTexture2D(Framework& framework, const ImageData& imageData, const std::string& label)
        : framework(framework), logger(framework.getLogger())
    {
        this->label = label;
        texture = OpenGLESUtil::getTexture()->create(
            static_cast<GLint>(imageData.getWidth()),
            static_cast<GLint>(imageData.getHeight()),
            GL_RGBA,
            GL_RGBA,
            GL_UNSIGNED_BYTE,
            imageData.getData(),
            label
        );
    }

    void OpenGLESTexture2D::destroy()
    {
        glDeleteTextures(1, &texture);
    }

    std::string OpenGLESTexture2D::printInfo() {
        std::ostringstream oss;
        oss << "OpenGLESTexture2D INFO.\n";
        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: Texture2D\n";
        oss << "\t\tLabel: " << label << "\n";
        // oss << "\t\tByte Size: " << byteSize << "\n";

        logger.info(oss.str());

        return oss.str();
    }
}
