//
// Created by Erkapic Luka on 2.7.2025.
//

#ifndef OPENGLES_TRIANGLE_TEST_PIPELINE_H
#define OPENGLES_TRIANGLE_TEST_PIPELINE_H

#include "core/pipelines/test/a_triangle_test_pipeline.h"
#include "opengles/opengles.h"
#include "opengles/renderer/opengles_renderer.h"

namespace mars
{
    class Framework;

    //! A OpenGLES implementation of the triangle test pipeline.
    class OpenGLESTriangleTestPipeline : public ATriangleTestPipeline
    {
    public:
        //! Constructor for the OpenGLESTriangleTestPipeline.
        //! @param framework The framework to use for rendering.
        OpenGLESTriangleTestPipeline(Framework& framework);

        void render() override;

        void destroy() override;
    private:
        Framework& framework;

        OpenGLESRenderer& renderer;

        GLuint programId;

        void createProgram();
    };
}

#endif //OPENGLES_TRIANGLE_TEST_PIPELINE_H
