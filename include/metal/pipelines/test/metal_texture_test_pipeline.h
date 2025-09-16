//
// Created by Luka Erkapic on 15.08.25.
//

#ifdef __APPLE__

#ifndef METAL_TEXTURE_TEST_PIPELINE_H
#define METAL_TEXTURE_TEST_PIPELINE_H


#include "core/pipelines/test/a_texture_test_pipeline.h"
#include "metal/renderer/metal_renderer.h"
#include "metal/metal.h"
#include "metal/texture/metal_texture2d.h"

namespace mars {

    class Framework;

    //! The Metal implementation of the APositionColorTestPipeline
    class MetalTextureTestPipeline : public ATextureTestPipeline {

    public:
        //! Constructor for the DX11TextureTestPipeline.
        //! @param framework The framework to use for rendering.
        MetalTextureTestPipeline(Framework& framework);

        //! @copydoc ATextureTestPipeline::getTexture2D
        ATexture2D* getTexture2D() override { return texture; }

        //! @copydoc ATextureTestPipeline::setTexture2D
        void setTexture2D(ATexture2D* texture) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) override;

        //! @copydoc ATextureTestPipeline::destroy
        void destroy() override;

    private:
        Framework &framework;
        MetalRenderer &renderer;

        MTL::Device *device;
        MTL::RenderPipelineState *pipeline;

        MetalTexture2D* texture;

        //! Creates the MTL::RenderPipelineState.
        void createPipeline();

    };
}

#endif

#endif //METAL_TEXTURE_TEST_PIPELINE_H
