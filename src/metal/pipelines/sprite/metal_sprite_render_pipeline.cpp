//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include "Framework.h"
#include "metal/pipelines/sprite/metal_sprite_render_pipeline.h"
#include "gpu_util/metal/metal_util.h"
#include "metal/buffers/metal_vertex_buffer.h"
#include "metal/buffers/metal_index_buffer.h"

namespace mars {

    MetalSpriteRenderPipeline::MetalSpriteRenderPipeline(Framework &framework,
                                                         OrthographicCamera *camera,
                                                         Culling culling)
        :framework(framework),
         renderer(*dynamic_cast<MetalRenderer*>(&framework.getRenderer())),
         pipeline(nullptr)
    {
        device = renderer.getDevice();
        createPipeline();
    }

void MetalSpriteRenderPipeline::setSpriteTexture(ATexture2D* texture) {
        if (texture != nullptr){
            this->texture = asMetalTexture(texture);
        }
    }

    void MetalSpriteRenderPipeline::createPipeline() {
        MTL::Library* library = gpu_util::MetalUtil::getLibrary().create(device, "content/shaders/metallib/2_0/sprite/sprite.metallib");
        MTL::Function* vertexFunction = gpu_util::MetalUtil::getFunction().create(library, "main_vs");
        MTL::Function* fragmentFunction = gpu_util::MetalUtil::getFunction().create(library, "main_fs");

        MTL::VertexDescriptor *vertexDescriptor = gpu_util::MetalUtil::getVertexDescriptor()
            .createPositionColorTextureCoordinatesVertexDescriptor();

        pipeline = gpu_util::MetalUtil::getRenderPipelineState().create(
            device,
            vertexFunction,
            fragmentFunction,
            vertexDescriptor,
        "Sprite Pipeline");

        vertexDescriptor->release();
        fragmentFunction->release();
        vertexFunction->release();
        library->release();
    }

void MetalSpriteRenderPipeline::render(AVertexBuffer* vertexBuffer,
                                       AIndexBuffer* indexBuffer,
                                       uint32_t indicesCount,
                                       uint32_t indicesOffset) {

    const MetalVertexBuffer* metalVertexBuffer = toMetalVertexBuffer(vertexBuffer);
    const MetalIndexBuffer* metalIndexBuffer = toMetalIndexBuffer(indexBuffer);

    RenderCommandEncoder* commandEncoder = renderer.getRenderCommandEncoder();

    commandEncoder->setVertexBuffer(metalVertexBuffer->getBuffer(),0,0);
    commandEncoder->setRenderPipelineState(pipeline);
    commandEncoder->setFragmentTexture(texture->getTexture(), 0);
    commandEncoder->setFragmentSamplerState(texture->getSamplerState(),0);
    MTL::IndexType indexType = indexBuffer->getType() == IndexBufferType::Uint16
             ? MTL::IndexTypeUInt16 : MTL::IndexTypeUInt32;
    commandEncoder->drawIndexedPrimitives(
                                          MTL::PrimitiveTypeTriangle,
                                          indexBuffer->getIndicesCount(),
                                          indexType,
                                          metalIndexBuffer->getBuffer(),
                                          0,
                                          1);
}

    void MetalSpriteRenderPipeline::destroy() {

        pipeline->release();
    }


}

#endif
