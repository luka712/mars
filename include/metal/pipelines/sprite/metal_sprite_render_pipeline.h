#if __APPLE__

#ifndef METAL_SPRITE_RENDER_PIPELINE_H
#define METAL_SPRITE_RENDER_PIPELINE_H

#include <metal/metal.h>
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "metal/texture/metal_texture2d.h"
#include "metal/renderer/metal_renderer.h"
#include "core/camera/core/OrthographicCamera.h"

namespace mars {

class Framework;

    //! The Metal implementation of the APositionColorTestPipeline
    class MetalSpriteRenderPipeline : public ASpriteRenderPipeline {
        
    public:
        //! Constructor for the DX11TextureTestPipeline.
        //! @param framework The framework to use for rendering.
        //! @param camera The camera of this pipeline.
        //! @param culling The culling. By default, it is Culling::Back.
        MetalSpriteRenderPipeline(Framework& framework,
            OrthographicCamera *camera,
            Culling culling = Culling::Back);
        
        //! @copydoc ASpriteRenderPipeline::getSpriteTexture
        ATexture2D* getSpriteTexture() override { return texture; }
        
        //! @copydoc ASpriteRenderPipeline::setSpriteTexture
        void setSpriteTexture(ATexture2D* texture) override;
        
        //! @copydoc ASpriteRenderPipeline::render
        virtual void render(
            AVertexBuffer* vertexBuffer,
            AIndexBuffer* indexBuffer,
            uint32_t indicesCount,
            uint32_t indicesOffset) override;
        
        //! @copydoc ASpriteRenderPipeline::destroy
        void destroy() override;
        
    private:
        Framework &framework;
        MetalRenderer &renderer;
        MTL::Device *device;
        MTL::RenderPipelineState *pipeline;
        MetalTexture2D* texture;
        MTL::Buffer *projectionViewBuffer;
        
        //! Creates the MTL::RenderPipelineState.
        void createPipeline();
    };

}

#endif //METAL_SPRITE_RENDER_PIPELINE_H

#endif
