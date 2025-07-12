//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include "Framework.h"
#include "metal/pipelines/test/metal_position_color_test_pipeline.h"
#include "gpu_util/metal/metal_utility.h"
#include "metal/buffers/metal_vertex_buffer.h"

namespace mars {

    MetalPositionColorTestPipeline::MetalPositionColorTestPipeline(Framework &framework)
        :framework(framework), renderer(*dynamic_cast<MetalRenderer*>(&framework.getRenderer())), pipeline(nullptr)
    {
        device = renderer.getDevice();
        createPipeline();
    }

    void MetalPositionColorTestPipeline::createPipeline() {
        MTL::Library* library = gpu_util::MetalUtility::getLibrary().create(device, "content/shaders/metallib/2_0/test/position_color.metallib");
        MTL::Function* vertexFunction = gpu_util::MetalUtility::getFunction().create(library, "main_vs");
        MTL::Function* fragmentFunction = gpu_util::MetalUtility::getFunction().create(library, "main_fs");

        MTL::VertexDescriptor *vertexDescriptor = MTL::VertexDescriptor::alloc()->init();
        
        // Attribute 0: position (float3)
        vertexDescriptor->attributes()->object(0)->setFormat(MTL::VertexFormatFloat3);
        vertexDescriptor->attributes()->object(0)->setOffset(0);
        vertexDescriptor->attributes()->object(0)->setBufferIndex(0);

        // Attribute 1: color (float4)
        vertexDescriptor->attributes()->object(1)->setFormat(MTL::VertexFormatFloat4);
        vertexDescriptor->attributes()->object(1)->setOffset(sizeof(float) * 3);
        vertexDescriptor->attributes()->object(1)->setBufferIndex(0); // Interleaved buffer

        // Layout for buffer index 0
        vertexDescriptor->layouts()->object(0)->setStride(sizeof(float) * (4 + 3));
        vertexDescriptor->layouts()->object(0)->setStepRate(1);
        vertexDescriptor->layouts()->object(0)->setStepFunction(MTL::VertexStepFunctionPerVertex);

        pipeline = gpu_util::MetalUtility::getRenderPipelineState().create(
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

    void MetalPositionColorTestPipeline::render(AVertexBuffer& vertexBuffer) {

        const MetalVertexBuffer* metalVertexBuffer = toMetalVertexBuffer(&vertexBuffer);

        RenderCommandEncoder* commandEncoder = renderer.getRenderCommandEncoder();

        commandEncoder->setVertexBuffer(metalVertexBuffer->getBuffer(),0,0);
        commandEncoder->setRenderPipelineState(pipeline);
        commandEncoder->drawPrimitives(MTL::PrimitiveTypeTriangle, 0, vertexBuffer.getVertexCount(), 1);
    }

    void MetalPositionColorTestPipeline::destroy() {

        pipeline->release();
    }


}

#endif
