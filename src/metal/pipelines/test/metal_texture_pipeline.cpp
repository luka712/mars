//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include "Framework.h"
#include "metal/pipelines/test/metal_texture_test_pipeline.h"
#include "gpu_util/metal/metal_util.h"
#include "metal/buffers/metal_vertex_buffer.h"
#include "metal/buffers/metal_index_buffer.h"

namespace mars {

    MetalTextureTestPipeline::MetalTextureTestPipeline(Framework &framework)
        :framework(framework), renderer(*dynamic_cast<MetalRenderer*>(&framework.getRenderer())), pipeline(nullptr)
    {
        device = renderer.getDevice();
        createPipeline();
    }

    void MetalTextureTestPipeline::setTexture2D(ATexture2D* texture) {
        if (texture != nullptr){
            this->texture = asMetalTexture(texture);
        }
    }

    void MetalTextureTestPipeline::createPipeline() {
        MTL::Library* library = gpu_util::MetalUtil::getLibrary().create(device, "content/shaders/metallib/2_0/test/texture.metallib");
        MTL::Function* vertexFunction = gpu_util::MetalUtil::getFunction().create(library, "main_vs");
        MTL::Function* fragmentFunction = gpu_util::MetalUtil::getFunction().create(library, "main_fs");

        MTL::VertexDescriptor *vertexDescriptor = gpu_util::MetalUtil::getVertexDescriptor()
            .createPositionColorTextureCoordinatesVertexDescriptor();

        pipeline = gpu_util::MetalUtil::getRenderPipelineState().create(
            device,
            vertexFunction,
            fragmentFunction,
            vertexDescriptor,
        "Position Color Pipeline");

        vertexDescriptor->release();
        fragmentFunction->release();
        vertexFunction->release();
        library->release();
    }

    void MetalTextureTestPipeline::render(AVertexBuffer& vertexBuffer) {

        const MetalVertexBuffer* metalVertexBuffer = toMetalVertexBuffer(&vertexBuffer);

        RenderCommandEncoder* commandEncoder = renderer.getRenderCommandEncoder();
        
        commandEncoder->setVertexBuffer(metalVertexBuffer->getBuffer(),0,0);
        commandEncoder->setRenderPipelineState(pipeline);
        commandEncoder->setFragmentTexture(texture->getTexture(), 0);
        commandEncoder->setFragmentSamplerState(texture->getSamplerState(),0);
        commandEncoder->drawPrimitives(MTL::PrimitiveTypeTriangle, 0, vertexBuffer.getVertexCount(), 1);
    }

void MetalTextureTestPipeline::render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) {

    const MetalVertexBuffer* metalVertexBuffer = toMetalVertexBuffer(&vertexBuffer);
    const MetalIndexBuffer* metalIndexBuffer = toMetalIndexBuffer(&indexBuffer);

    RenderCommandEncoder* commandEncoder = renderer.getRenderCommandEncoder();

    commandEncoder->setVertexBuffer(metalVertexBuffer->getBuffer(),0,0);
    commandEncoder->setRenderPipelineState(pipeline);
    commandEncoder->setFragmentTexture(texture->getTexture(), 0);
    commandEncoder->setFragmentSamplerState(texture->getSamplerState(),0);
    MTL::IndexType indexType = indexBuffer.getType() == IndexBufferType::Uint16
             ? MTL::IndexTypeUInt16 : MTL::IndexTypeUInt32;
    commandEncoder->drawIndexedPrimitives(
                                          MTL::PrimitiveTypeTriangle,
                                          indexBuffer.getIndicesCount(),
                                          indexType,
                                          metalIndexBuffer->getBuffer(),
                                          0,
                                          1);
}

    void MetalTextureTestPipeline::destroy() {

        pipeline->release();
    }


}

#endif
