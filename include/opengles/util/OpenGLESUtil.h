//
// Created by luka on 18.1.2025.
//
#ifndef OPEN_GLES_UTIL_H
#define OPEN_GLES_UTIL_H

#include "opengles/util/OpenGLESTextureUtil.h"
#include "opengles/util/OpenGLESBufferUtil.h"
#include "opengles/util/OpenGLESConverter.h"
#include "gpu_util/logger.h"
#include "gpu_util/opengles/opengles_shader_util.h"
#include "gpu_util/opengles/opengles_program_util.h"
#include "opengles/util/OpenGLESVertexArrayObjectUtil.h"
#include "opengles/util/OpenGLESUniformUtil.h"

namespace mars {

    static OpenGLESConverter *open_gles_converter = nullptr;
    static OpenGLESBufferUtil *open_gles_buffer = nullptr;
    static OpenGLESTextureUtil *open_gles_texture = nullptr;
    static gpu_util::OpenGLESShaderUtil *open_gles_shader = nullptr;
    static gpu_util::OpenGLESProgramUtil *open_gles_program = nullptr;
    static OpenGLESVertexArrayObjectUtil *open_gles_vao = nullptr;
    static OpenGLESUniformUtil *open_gles_uniform = nullptr;

    //! The OpenGLESUtil class for working with OpenGLES.
    class OpenGLESUtil {
    public:
        //! Initialize the OpenGLESUtil.
        //! @param logger The logger.
        static void initialize(Logger& logger) {

            gpu_util::Logger* spdLogger = new gpu_util::SpdLogger();

            open_gles_converter = new OpenGLESConverter(logger);
            open_gles_buffer = new OpenGLESBufferUtil(logger);
            open_gles_texture = new OpenGLESTextureUtil(logger);
            open_gles_shader = new gpu_util::OpenGLESShaderUtil(*spdLogger);
            open_gles_program = new gpu_util::OpenGLESProgramUtil(*spdLogger);
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
        static gpu_util::OpenGLESShaderUtil* getShader() { return open_gles_shader; }

        //! Gets the OpenGLESProgramUtil
        //! @return The OpenGLESProgramUtil.
        static gpu_util::OpenGLESProgramUtil* getProgram() { return open_gles_program; }

        //! Gets the OpenGLESVertexArrayObjectUtil.
        //! @return The OpenGLESVertexArrayObjectUtil.
        static OpenGLESVertexArrayObjectUtil* getVertexArrayObject() { return open_gles_vao; }

        //! Gets the OpenGLESUniformUtil.
        //! @return The OpenGLESUniformUtil.
        static OpenGLESUniformUtil* getUniform() { return open_gles_uniform; }
    };
}


#endif //OPEN_GLES_UTIL_H
