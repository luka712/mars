//
// Created by Erkapic Luka on 18.3.2025.
//

#include "Framework.h"
#include "opengles/pipelines/lines/OpenGLESLinesRenderPipeline.h"
#include "opengles/util/OpenGLESUtil.h"
#include "opengles/opengles.h"

namespace mars {
    OpenGLESLinesRenderPipeline::OpenGLESLinesRenderPipeline(
        Framework &framework,
        AUniformBuffer &projectionViewBuffer,
        AInstanceBuffer &modelBuffer)
        : framework(framework), program(0), vao(0), lastVerticesBuffer(0), color(Color::white()) {
        this->projectionViewBuffer = toOpenGLESUniformBuffer(&projectionViewBuffer);
        this->modelBuffer = toOpenGLESInstanceBuffer(&modelBuffer);

        createProgram();
        createResources();
        projectionViewMatrixLocation = OpenGLESUtil::getUniform()->getUniformLocation(program, "u_projectionView");
        colorLocation = OpenGLESUtil::getUniform()->getUniformLocation(program, "u_color");
    }

    void OpenGLESLinesRenderPipeline::setColor(const Color &color) {
        this->color = color;
        colorBuffer->update(&this->color, sizeof(Color));
    }

    void OpenGLESLinesRenderPipeline::initialize() {
        // TODO: REMOVE
    }

    void OpenGLESLinesRenderPipeline::render(AVertexBuffer &vertexBuffer) {
        render(vertexBuffer, 1, -1);
    }

    void OpenGLESLinesRenderPipeline::createProgram() {
        const FileReader &reader = framework.getFileReader();
        const std::string vertexShaderCode = reader.readFile("content/shaders/glsl/300es/lines/lines_vs.glsl");
        const std::string fragmentShaderCode = reader.readFile("content/shaders/glsl/300es/lines/lines_fs.glsl");

        const GLuint vertexShader = OpenGLESUtil::getShader()->createVertexShader(vertexShaderCode);
        const GLuint fragmentShader = OpenGLESUtil::getShader()->createFragmentShader(fragmentShaderCode);

        program = OpenGLESUtil::getProgram()->create(
            vertexShader,
            fragmentShader,
            "OpenGLESLinesRenderPipeline.program");

        glDeleteShader(fragmentShader);
        glDeleteShader(vertexShader);
    }

    void OpenGLESLinesRenderPipeline::createResources() {
        colorBuffer = toOpenGLESUniformBuffer(framework.getBuffersFactory().createUniformBuffer(
            &this->color,
            "OpenGLESLinesRenderPipeline.colorBuffer",
            sizeof(Color),
            BufferUsage::Uniform
        ));
    }

    void OpenGLESLinesRenderPipeline::createVAO(GLuint vertexBuffer) {
        // If exists, we need to delete if first.
        if (vao != 0) {
            glDeleteVertexArrays(1, &vao);
        }

        GLsizei stride = 7 * sizeof(float);

        vao = OpenGLESUtil::getVertexArrayObject()->create("OpenGLESLineRenderPipeline.vao");
        glBindVertexArray(vao);

        // - POSITION
        glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
        glEnableVertexAttribArray(0);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, nullptr);

        // - COLOR
        glEnableVertexAttribArray(1);
        glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(3 * sizeof(float)));

        stride = 4 * sizeof(float);

        // - MODEL MATRIX
        glBindBuffer(GL_ARRAY_BUFFER, modelBuffer->getBuffer());
        glEnableVertexAttribArray(2);
        glVertexAttribPointer(2, 4, GL_FLOAT, GL_FALSE, stride, nullptr);

        glEnableVertexAttribArray(3);
        glVertexAttribPointer(3, 4, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(stride));

        glEnableVertexAttribArray(4);
        glVertexAttribPointer(4, 4, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(2 * stride));

        glEnableVertexAttribArray(5);
        glVertexAttribPointer(5, 4, GL_FLOAT, GL_FALSE, stride, reinterpret_cast<void *>(3 * stride));

        glVertexAttribDivisor(2, 1);
        glVertexAttribDivisor(3, 1);
        glVertexAttribDivisor(4, 1);
        glVertexAttribDivisor(5, 1);

        glBindVertexArray(0);
        lastVerticesBuffer = vertexBuffer;
    }

    void OpenGLESLinesRenderPipeline::render(
        AVertexBuffer &vertexBuffer,
        const uint32_t instanceCount,
        uint32_t vertexCount
    ) {
        const OpenGLESVertexBuffer *glVertexBuffer = toOpenGLESVertexBuffer(&vertexBuffer);

        if (const GLuint glBuffer = glVertexBuffer->getBuffer(); glBuffer != lastVerticesBuffer) {
            createVAO(glBuffer);
        }

        glUseProgram(program);
        glBindVertexArray(vao);

        glUniformMatrix4fv(
            projectionViewMatrixLocation,
            1,
            GL_FALSE,
            static_cast<GLfloat *>(projectionViewBuffer->getBufferData())
        );
        glUniform4fv(colorLocation, 1, static_cast<GLfloat *>(colorBuffer->getBufferData()));

        if (vertexCount < 0) {
            vertexCount = vertexBuffer.getVertexCount();
        }
        glDrawArraysInstanced(GL_LINES, 0, static_cast<GLsizei>(vertexCount), static_cast<GLsizei>(instanceCount));
    }
}
