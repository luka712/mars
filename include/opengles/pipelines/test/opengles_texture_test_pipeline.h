//
// Created by Erkapic Luka on 27.07.25.
//

#ifndef OPENGLES_TEXTURE_TEST_PIPELINE_H
#define OPENGLES_TEXTURE_TEST_PIPELINE_H

#include "core/pipelines/test/a_texture_test_pipeline.h"
#include "opengles/opengles.h"
#include "opengles/renderer/opengles_renderer.h"
#include "opengles/buffers/opengles_vertex_buffer.h"
#include "opengles/texture/opengles_texture2d.h"

namespace mars
{
    class Framework;

    //! A OpenGLES implementation of the texture test pipeline.
    class OpenGLESTextureTestPipeline : public ATextureTestPipeline
    {
    public:
        //! Constructor for the OpenGLESTriangleTestPipeline.
        //! @param framework The framework to use for rendering.
        OpenGLESTextureTestPipeline(Framework& framework);

        //! @copydoc ATextureTestPipeline::getTexture2D
        ATexture2D* getTexture2D() override;

        //! @copydoc ATextureTestPipeline::setTexture2D
        void setTexture2D(ATexture2D* texture) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) override;

        void destroy() override;
    private:
        Framework& framework;

        OpenGLESRenderer& renderer;
        OpenGLESTexture2D* texture;

        GLuint programId;
        GLuint vaoId;
        GLuint vertexBufferId;

        void createProgram();

        //! Create a Vertex Array Object (VAO) for the given vertex buffer.
        //! It is created only whenever vertexBufferId is changed, that is when the vertex buffer is changed.
        //! Called before rendering.
        //! @param vertexBuffer The vertex buffer to create the VAO for.
        void createVAO(const OpenGLESVertexBuffer& vertexBuffer);
    };
}

#endif //OPENGLES_TEXTURE_TEST_PIPELINE_H


