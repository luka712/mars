//
// Created by luka on 14.02.25.
//

#include "opengles/util/OpenGLESVertexArrayObjectUtil.h"


namespace mars {

    GLuint OpenGLESVertexArrayObjectUtil::create(const std::string &label) {

        GLuint vao = 0;
        glGenVertexArrays(1, &vao);
        glBindVertexArray(vao);

        // Label
        if (!label.empty()) {
            glObjectLabel(GL_VERTEX_ARRAY, vao, static_cast<GLsizei>(label.size()), label.c_str());
        }

        return vao;
    }


}
