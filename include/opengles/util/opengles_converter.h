//
// Created by Erkapic Luka on 18.1.2025.
//

#ifndef OPEN_GLES_CONVERTER_UTIL_H
#define OPEN_GLES_CONVERTER_UTIL_H

#include "opengles/opengles.h"
#include "core/buffers/buffer_enums.h"

namespace mars {
    //! Converts the Mars enums to OpenGLES enums.
    class OpenGLESConverter {
    public:
        //! Converts the buffer usage to OpenGLES buffer usage.
        static GLenum convertToGLHint(BufferUsage usage);
    };
}

#endif //OPEN_GLES_CONVERTER_UTIL_H
