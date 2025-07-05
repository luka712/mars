//
// Created by Erkapic Luka on 18.1.2025.
//
#ifndef OPEN_GLES_UTIL_H
#define OPEN_GLES_UTIL_H

#include "gpu_util/opengles/opengles_texture_util.h"
#include "gpu_util/opengles/opengles_buffer_util.h"
#include "gpu_util/logger.h"
#include "gpu_util/opengles/opengles_shader_util.h"
#include "gpu_util/opengles/opengles_program_util.h"
#include "gpu_util/opengles/opengles_vertex_array_object_util.h"
#include "gpu_util/opengles/opengles_uniform_util.h"

namespace gpu_util {

    //! The OpenGLESUtil class for working with OpenGLES.
    class OpenGLESUtil {
    public:
        //! Initialize the OpenGLESUtil.
        //! @param logger The logger.
        static void initialize(Logger* logger) {
            open_gles_buffer = new OpenGLESBufferUtil(*logger);
            open_gles_texture = new OpenGLESTextureUtil(*logger);
            open_gles_shader = new OpenGLESShaderUtil(*logger);
            open_gles_program = new OpenGLESProgramUtil(*logger);
            open_gles_vao = new OpenGLESVertexArrayObjectUtil();
            open_gles_uniform = new OpenGLESUniformUtil(*logger);
        }

          //! Initialize the OpenGLESUtil.
        //! @param withDefaultLogger If <code>true</code>,  creates default logger.
        static void initialize(bool withDefaultLogger) {

            if (OpenGLESUtil::logger != nullptr) {
                delete OpenGLESUtil::logger;
            }

            if (withDefaultLogger) {
                OpenGLESUtil::logger = new SpdLogger();
            }
            else {
                OpenGLESUtil::logger = new MockLogger();
            }
            OpenGLESUtil::initialize(logger);
        }

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
    private:
        static Logger* logger;
        static OpenGLESBufferUtil* open_gles_buffer ;
        static OpenGLESTextureUtil* open_gles_texture;
        static OpenGLESShaderUtil* open_gles_shader;
        static OpenGLESProgramUtil* open_gles_program ;
        static OpenGLESVertexArrayObjectUtil* open_gles_vao;
        static OpenGLESUniformUtil* open_gles_uniform ;
    };
}


#endif //OPEN_GLES_UTIL_H
