//
// Created by luka on 18.1.2025.
//
#ifndef OPEN_GLES_UTIL_H
#define OPEN_GLES_UTIL_H

#include "opengles/util/OpenGLESTextureUtil.h"
#include "opengles/util/OpenGLESBufferUtil.h"
#include "opengles/util/OpenGLESConverter.h"
#include "opengles/util/OpenGLESShaderUtil.h"
#include "opengles/util/OpenGLESProgramUtil.h"
#include "opengles/util/OpenGLESVertexArrayObjectUtil.h"
#include "opengles/util/OpenGLESUniformUtil.h"

namespace mars {

    static OpenGLESConverter *open_gles_converter = nullptr;
    static OpenGLESBufferUtil *open_gles_buffer = nullptr;
    static OpenGLESTextureUtil *open_gles_texture = nullptr;
    static OpenGLESShaderUtil *open_gles_shader = nullptr;
    static OpenGLESProgramUtil *open_gles_program = nullptr;
    static OpenGLESVertexArrayObjectUtil *open_gles_vao = nullptr;
    static OpenGLESUniformUtil *open_gles_uniform = nullptr;

    //! The OpenGLESUtil class for working with OpenGLES.
    class OpenGLESUtil {
    public:
        //! Initialize the OpenGLESUtil.
        //! @param logger The logger.
        static void initialize(Logger& logger) {
            open_gles_converter = new OpenGLESConverter(logger);
            open_gles_buffer = new OpenGLESBufferUtil(logger);
            open_gles_texture = new OpenGLESTextureUtil(logger);
            open_gles_shader = new OpenGLESShaderUtil(logger);
            open_gles_program = new OpenGLESProgramUtil(logger);
            open_gles_vao = new OpenGLESVertexArrayObjectUtil();
            open_gles_uniform = new OpenGLESUniformUtil(logger);
        }

        //! Gets the OpenGLESConverter.
        //! @return The OpenGLESConverter.
        static OpenGLESConverter *getConverter() { return open_gles_converter; }

        //! Gets the OpenGLESBufferUtil.
        //! @return The OpenGLESBufferUtil.
        static OpenGLESBufferUtil* getBuffer() { return open_gles_buffer; }

        //! Gets the OpenGLESTextureUtil.
        //! @return The OpenGLESTextureUtil.
        static OpenGLESTextureUtil* getTexture() { return open_gles_texture; }

        //! Gets the OpenGLESShaderUtil
        //! @return The OpenGLESShaderUtil.
        static OpenGLESShaderUtil* getShader() { return open_gles_shader; }

        //! Gets the OpenGLESProgramUtil
        //! @return The OpenGLESProgramUtil.
        static OpenGLESProgramUtil* getProgram() { return open_gles_program; }

        //! Gets the OpenGLESVertexArrayObjectUtil.
        //! @return The OpenGLESVertexArrayObjectUtil.
        static OpenGLESVertexArrayObjectUtil* getVertexArrayObject() { return open_gles_vao; }

        //! Gets the OpenGLESUniformUtil.
        //! @return The OpenGLESUniformUtil.
        static OpenGLESUniformUtil* getUniform() { return open_gles_uniform; }
    };
}


#endif //OPEN_GLES_UTIL_H
