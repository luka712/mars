//
// Created by Erkapic Luka on 4.7.2025.
//

#include "gpu_util/opengles/opengles_util.h"

namespace gpu_util {
	Logger* OpenGLESUtil::logger = nullptr;
	OpenGLESBufferUtil* OpenGLESUtil::open_gles_buffer = nullptr;
	OpenGLESTextureUtil* OpenGLESUtil::open_gles_texture = nullptr;
	OpenGLESShaderUtil* OpenGLESUtil::open_gles_shader = nullptr;
	OpenGLESProgramUtil* OpenGLESUtil::open_gles_program = nullptr;
	OpenGLESVertexArrayObjectUtil* OpenGLESUtil::open_gles_vao = nullptr;
	OpenGLESUniformUtil* OpenGLESUtil::open_gles_uniform = nullptr;

} // namespace gpu_util

