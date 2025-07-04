//
// Created by Erkapic Luka on 11.02.25.
//

#include <sstream>
#include "Framework.h"
#include "opengles/texture/OpenGLESTexture2D.h"
#include "gpu_util/opengles/opengles_util.h"

using namespace gpu_util;

namespace mars
{
    OpenGLESTexture2D::OpenGLESTexture2D(Framework& framework, const ImageData& imageData, const std::string& label)
        : framework(framework), logger(framework.getLogger())
    {
        this->label = label;
        this->width = imageData.getWidth();
        this->height = imageData.getHeight();
        texture = OpenGLESUtil::getTexture()->create(
            static_cast<GLint>(width),
            static_cast<GLint>(height),
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

    OpenGLESTexture2D *asOpenGLESTexture(Texture2D *texture) {
        return dynamic_cast<OpenGLESTexture2D*>(texture);
    }

}
