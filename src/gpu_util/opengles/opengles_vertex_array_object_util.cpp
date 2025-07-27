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

    GLuint OpenGLESVertexArrayObjectUtil::createPositionColorTextureCoordinatesVAO(const GLuint interleavedBuffer,
        const std::string &label) {

        const GLuint vao = create(label);

        // Bind the vertex buffer
        glBindBuffer(GL_ARRAY_BUFFER, interleavedBuffer);
        constexpr GLuint stride = sizeof(float) * 9;
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, static_cast<void *>(0)); // Position attribute
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(sizeof(float) * 3)); // Color attribute
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(sizeof(float) * (3 + 4))); // Tex coords attribute
        glEnableVertexAttribArray(0); // Enable position attribute
        glEnableVertexAttribArray(1); // Enable color attribute
        glEnableVertexAttribArray(2); // Enable texture coords attribute

        return vao;
    }
}
