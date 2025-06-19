//
// Created by Luka Erkapic on 18.06.25.
//

#ifdef __APPLE__

#ifndef METAL_TRIANGLE_TEST_PIPELINE_H
#define METAL_TRIANGLE_TEST_PIPELINE_H

#include "metal/metal.h"
#include "metal/renderer/metal_renderer.h"
#include "core/pipelines/test/a_triangle_test_pipeline.h"

namespace mars {
    class Framework;

    class MetalTriangleTestPipeline : public ATriangleTestPipeline {
    public:
        //! The constructor.
        //! @param framework The Framework reference.
        explicit MetalTriangleTestPipeline(Framework &framework);

        void render() override;

        void destroy() override;

    private:
        Framework &framework;
        MetalRenderer &renderer;

        MTL::Device *device;
        MTL::RenderPipelineState *pipeline;

        //! Creates the MTL::RenderPipelineState.
        void createPipeline();
    };
}

#endif //METAL_TRIANGLE_TEST_PIPELINE_H

#endif
