//
// Created by Erkapic Luka on 14.02.25.
//

#include "gpu_util/opengles/opengles_vertex_array_object_util.h"

namespace gpu_util {

    GLuint OpenGLESVertexArrayObjectUtil::create(const std::string &label) {

        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Label
#ifndef __EMSCRIPTEN__
        if (!label.empty()) {
            glObjectLabel(GL_VERTEX_ARRAY, vao, static_cast<GLsizei>(label.size()), label.c_str());
        }
#endif

        return vao;
    }


}
