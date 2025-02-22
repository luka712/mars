//
// Created by luka on 10.02.25.
//

#include "opengles/pipelines/sprite/OpenGLESSpriteRenderPipeline.h"
#include <Framework.h>
#include <opengles/buffers/OpenGLESIndexBuffer.h>
#include <opengles/buffers/OpenGLESVertexBuffer.h>
#include <opengles/util/OpenGLESUtil.h>

namespace mars {
    OpenGLESSpriteRenderPipeline::OpenGLESSpriteRenderPipeline(
        Framework &framework, OrthographicCamera *camera, const Culling culling)
        : framework(framework), renderer(findOpenGLESRenderer(framework)), camera(camera), culling(culling) {
        glVao = 0;
        createProgram();
        glProjectionViewMatrixLocation = OpenGLESUtil::getUniform()->getUniformLocation(glProgram, "u_projectionView");
    }

    void OpenGLESSpriteRenderPipeline::setSpriteTexture(Texture2D *spriteTexture) {
        this->texture = asOpenGLESTexture(spriteTexture);
    }

    void OpenGLESSpriteRenderPipeline::createProgram() {
        const FileReader &reader = framework.getFileReader();
        const std::string vertexShaderCode = reader.readFile("shaders/glsl/300es/sprite/sprite_vs.glsl");
        const std::string fragmentShaderCode = reader.readFile("shaders/glsl/300es/sprite/sprite_fs.glsl");

        const GLuint vertexShader = OpenGLESUtil::getShader()->createVertexShader(
            vertexShaderCode,
            "OpenGLESSpriteRenderPipeline.vertexShader");
        const GLuint fragmentShader = OpenGLESUtil::getShader()->createFragmentShader(
            fragmentShaderCode,
            "OpenGLESSpriteRenderPipeline.fragmentShader");

        // create a program.
        glProgram = OpenGLESUtil::getProgram()->create(vertexShader, fragmentShader,
                                                       "OpenGLESSpriteRenderPipeline.glProgram");

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void OpenGLESSpriteRenderPipeline::createVao(GLuint vertexBuffer) {
        if (glVao != 0) {
            glDeleteVertexArrays(1, &glVao);
        }

        glVao = OpenGLESUtil::getVertexArrayObject()->create("OpenGLESSpriteRenderPipeline.glVao");
        glBindVertexArray(glVao);
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);

        constexpr GLsizei stride = 3 * sizeof(float) + 4 * sizeof(float) + 2 * sizeof(float);

        // (xyz) position
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, false, stride, nullptr);

        // (rgba) color
        glEnableVertexAttribArray(1);
        GLint offset = 3 * sizeof(float);
        glVertexAttribPointer(1, 4, GL_FLOAT, false, stride, &offset);

        // (uv) texture
        glEnableVertexAttribArray(2);
        offset = 7 * sizeof(float);
        glVertexAttribPointer(2, 2, GL_FLOAT, false, stride, &offset);
    }


    void OpenGLESSpriteRenderPipeline::render(
        AVertexBuffer *vertexBuffer,
        AIndexBuffer *indexBuffer,
        const uint32_t indicesCount,
        uint32_t indicesOffset) {
        OpenGLESVertexBuffer *glVertexBuffer = toOpenGLESVertexBuffer(vertexBuffer);
        OpenGLESIndexBuffer *glIndexBuffer = toOpenGLESIndexBuffer(indexBuffer);

        if (GLuint glBuffer = glVertexBuffer->getBuffer(); glBuffer != glLastVertexBuffer) {
            createVao(glBuffer);
            glLastVertexBuffer = glBuffer;
        }

        glUseProgram(glProgram);
        // Bind the vao. It contains all the information about the vertex buffer layout ( vertices + instances)
        glBindVertexArray(glVao);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, glIndexBuffer->getBuffer());
        glUniformMatrix4fv(glProjectionViewMatrixLocation, 1, false, &camera->getProjectionViewMatrix()[0][0]);
        glActiveTexture(GL_TEXTURE0);
        glBindTexture(GL_TEXTURE_2D, texture->getTexture());

        // We can only really use two types uint16 and uint32. Boolean check to see which one to use.
        const GLenum type = indexBuffer->getType() == IndexBufferType::Uint16 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT;

        // api.PolygonMode(GLEnum.FrontAndBack, GLEnum.Line);

        // Either draw all indices or a specific amount. If indicesCount is -1, draw all as defined by the index buffer.
        const uint32_t toIndices = indicesCount > 0 ? indicesCount : indexBuffer->getIndicesCount();
        const uint32_t fromIndices = indicesOffset * indexBuffer->getElementByteSize();

        glDrawElements(GL_LINES, static_cast<GLsizei>(toIndices), type, &fromIndices);
    }

    void OpenGLESSpriteRenderPipeline::destroy() {
        glDeleteProgram(glProgram);
        if (glVao != 0) {
            glDeleteVertexArrays(1, &glVao);
        }
    }
}
