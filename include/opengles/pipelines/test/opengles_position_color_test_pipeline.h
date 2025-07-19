//
// Created by Erkapic Luka on 8.7.2025.
//

#ifndef OPENGLES_POSITION_COLOR_TEST_PIPELINE_H
#define OPENGLES_POSITION_COLOR_TEST_PIPELINE_H

#include "core/pipelines/test/a_position_color_test_pipeline.h"
#include "opengles/opengles.h"
#include "opengles/renderer/opengles_renderer.h"
#include "opengles/buffers/opengles_vertex_buffer.h"

namespace mars
{
    class Framework;

    //! A OpenGLES implementation of the position color test pipeline.
    //! This is simple pipeline that just tests passing of the position and color attributes to the vertex shader
    ///! via a vertex buffer.
    class OpenGLESPositionColorTestPipeline : public APositionColorTestPipeline
    {
    public:
        //! Constructor for the OpenGLESTriangleTestPipeline.
        //! @param framework The framework to use for rendering.
        OpenGLESPositionColorTestPipeline(Framework& framework);

        //! @copydoc APositionColorTestPipeline::render
        void render(AVertexBuffer& vertexBuffer) override;

        //! @copydoc APositionColorTestPipeline::render
        void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) override;

        void destroy() override;
    private:
        Framework& framework;

        OpenGLESRenderer& renderer;

        GLuint programId;
        GLuint vaoId;
        GLuint vertexBufferId;

        void createProgram();

        //! Create a Vertex Array Object (VAO) for the given vertex buffer.
        //! It is created only whenever vertexBufferId is changed, that is when the vertex buffer is changed.
        //! Called before rendering.
        //! @param vertexBuffer The vertex buffer to create the VAO for.
        void createVAO(OpenGLESVertexBuffer& vertexBuffer);
    };
}

#endif //OPENGLES_POSITION_COLOR_TEST_PIPELINE_H
