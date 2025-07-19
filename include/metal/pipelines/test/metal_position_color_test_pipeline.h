//
// Created by Luka Erkapic on 12.07.25.
//

#ifdef __APPLE__

#ifndef METAL_POSITION_COLOR_TEST_PIPELINE_H
#define METAL_POSITION_COLOR_TEST_PIPELINE_H

#include "core/pipelines/test/a_position_color_test_pipeline.h"
#include "metal/renderer/metal_renderer.h"
#include "metal/metal.h"

namespace mars {

    class Framework;

    //! The Metal implementation of the APositionColorTestPipeline
    class MetalPositionColorTestPipeline : public APositionColorTestPipeline {

    public:
        //! The constructor.
        //! @param framework The framework.
        explicit MetalPositionColorTestPipeline(Framework &framework);

        //! @copydoc APositionColorTestPipeline::render
        void render(AVertexBuffer& vertexBuffer) override;

        //! @copydoc APositionColorTestPipeline::render
        void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) override;

        //! @copydoc APositionColorTestPipeline::destroy
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

#endif //METAL_POSITION_COLOR_TEST_PIPELINE_H

#endif
