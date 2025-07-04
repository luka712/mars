//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESCONVERTERUTIL_H
#define OPENGLESCONVERTERUTIL_H

#include "opengles/opengles.h"
#include "core/buffers/BufferEnums.h"

namespace mars {
    //! Converts the Mars enums to OpenGLES enums.
    class OpenGLESConverter {
    public:
        //! Converts the buffer usage to OpenGLES buffer usage.
        static GLenum convertToGLHint(BufferUsage usage);
    };
}

#endif //OPENGLESCONVERTERUTIL_H
