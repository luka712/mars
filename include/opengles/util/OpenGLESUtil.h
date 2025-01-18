//
// Created by lukaa on 18.1.2025..
//

#ifndef OPENGLESUTIL_H
#define OPENGLESUTIL_H


#include "opengles/util/OpenGLESBufferUtil.h"
#include "opengles/util/OpenGLESConverter.h"

namespace mars {

    static OpenGLESConverter *open_gles_converter = nullptr;
    static OpenGLESBufferUtil *open_gles_buffer_util = nullptr;

    //! The OpenGLESUtil class for working with OpenGLES.
    class OpenGLESUtil {
    public:
        //! Initialize the OpenGLESUtil.
        //! @param logger The logger.
        static void initialize(Logger& logger) {
            open_gles_converter = new OpenGLESConverter(logger);
            open_gles_buffer_util = new OpenGLESBufferUtil(logger);
        }

        //! Gets the OpenGLESConverter.
        //! @return The OpenGLESConverter.
        static OpenGLESConverter *getConverter() { return open_gles_converter; }

        //! Gets the OpenGLESBufferUtil.
        //! @return The OpenGLESBufferUtil.
        static OpenGLESBufferUtil* getBuffer() { return open_gles_buffer_util; }

    private:
    };
}


#endif //OPENGLESUTIL_H
