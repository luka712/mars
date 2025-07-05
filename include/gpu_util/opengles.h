//
// Created by Erkapic Luka on 2.7.2025.
//

#ifndef OPENGLES_HEADER
#define OPENGLES_HEADER

#if __EMSCRIPTEN__
#include <GL/gl.h>
#include <GLES3/gl3.h>
#else
#include <KHR/khrplatform.h>
#include <glad/glad.h>
#endif

#endif //OPENGLES_HEADER
