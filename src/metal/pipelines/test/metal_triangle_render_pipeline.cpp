//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include "Framework.h"
#include "metal/pipelines/test/metal_triangle_test_pipeline.h"
#include "gpu_util/metal/metal_utility.h"

namespace mars {

    MetalTriangleTestPipeline::MetalTriangleTestPipeline(Framework &framework)
        :framework(framework), renderer(*dynamic_cast<MetalRenderer*>(&framework.getRenderer()))
    {
        device = renderer.getDevice();
        createPipeline();
    }

    void MetalTriangleTestPipeline::createPipeline() {
        MTL::Library* library = gpu_util::MetalUtility::getLibrary().create(device, "content/shaders/metallib/2_0/test/triangle.metallib");
        MTL::Function* vertexFunction = gpu_util::MetalUtility::getFunction().create(library, "main_vs");
        MTL::Function* fragmentFunction = gpu_util::MetalUtility::getFunction().create(library, "main_fs");

        pipeline = gpu_util::MetalUtility::getRenderPipelineState().create(device, vertexFunction, fragmentFunction, "TrianglePipeline");

        fragmentFunction->release();
        vertexFunction->release();
        library->release();
    }

    void MetalTriangleTestPipeline::render() {
        RenderCommandEncoder* commandEncoder = renderer.getRenderCommandEncoder();
        
        commandEncoder->setRenderPipelineState(pipeline);
        commandEncoder->drawPrimitives(MTL::PrimitiveTypeTriangle, 0, 3, 1);
    }

    void MetalTriangleTestPipeline::destroy() {
    
        pipeline->release();
    }


}

#endif
