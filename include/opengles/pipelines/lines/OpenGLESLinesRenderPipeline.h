//
// Created by Erkapic Luka on 18.3.2025.
//

#ifndef OPEN_GLES_LINES_RENDER_PIPELINE_H
#define OPEN_GLES_LINES_RENDER_PIPELINE_H

#include "core/pipelines/lines/ALinesRenderPipeline.h"
#include "opengles/buffers/OpenGLESUniformBuffer.h"
#include "opengles/buffers/opengles_vertex_buffer.h"
#include "opengles/buffers/OpenGLESInstanceBuffer.h"

namespace mars {

    class Framework;

    //! The Open GLES implementation of the lines render pipeline.
    class OpenGLESLinesRenderPipeline final : public ALinesRenderPipeline {
    public:

        //! Construct a new OpenGLESLinesRenderPipeline object.
        //! @param framework The framework.
        //! @param projectionViewBuffer The projection view buffer.
        //! @param modelBuffer The model buffer.
        OpenGLESLinesRenderPipeline(
            Framework &framework,
            AUniformBuffer &projectionViewBuffer,
            AInstanceBuffer &modelBuffer);

        [[nodiscard]] Color getColor() const override { return  color; }

        void setColor(const Color &color) override;

        void initialize() override;

        void render(AVertexBuffer &vertexBuffer) override;

        void render(AVertexBuffer &vertexBuffer, uint32_t instanceCount, uint32_t vertexCount) override;
    private:
        Framework& framework;
        GLuint program;
        GLuint vao;
        GLuint lastVerticesBuffer;
        GLint projectionViewMatrixLocation{};
        GLint colorLocation{};
        OpenGLESInstanceBuffer* modelBuffer;
        OpenGLESUniformBuffer* projectionViewBuffer;
        std::shared_ptr<OpenGLESUniformBuffer> colorBuffer;
        Color color;

        void createProgram();
        void createResources();
        void createVAO(GLuint vertexBuffer);
    };
}

#endif //OPEN_GLES_LINES_RENDER_PIPELINE_H
