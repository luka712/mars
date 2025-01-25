//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESCONVERTERUTIL_H
#define OPENGLESCONVERTERUTIL_H

#include "opengles/opengles.h"
#include "core/log/Logger.h"
#include "core/buffers/BufferEnums.h"

namespace mars {
    //! Converts the Mars enums to OpenGLES enums.
    class OpenGLESConverter {
    public:
        //! Construct a new OpenGLESConverterUtil object.
        //! @param logger The logger.
        explicit OpenGLESConverter(Logger& logger);

        //! Converts the buffer usage to OpenGLES buffer usage.
        GLenum convertToGLHint(BufferUsage usage);

    private:
        Logger &logger;
    };
}

#endif //OPENGLESCONVERTERUTIL_H
