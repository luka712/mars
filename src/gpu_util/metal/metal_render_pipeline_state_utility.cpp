//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include <stdexcept>
#include "gpu_util/metal/metal_render_pipeline_state_utility.h"

namespace gpu_util {

    MTL::RenderPipelineState *MetalRenderPipelineStateUtility::create(
                                                                      MTL::Device* device,
                                                                      MTL::Function* vertexFunction,
                                                                      MTL::Function* fragmentFunction,
                                                                      MTL::VertexDescriptor *vertexDescriptor,
                                                                      const std::string& label) {

        MTL::RenderPipelineDescriptor* descriptor = MTL::RenderPipelineDescriptor::alloc()->init();
        descriptor->setVertexFunction(vertexFunction);
        descriptor->setFragmentFunction(fragmentFunction);
        descriptor->colorAttachments()->object(0)->setPixelFormat(MTL::PixelFormatBGRA8Unorm);
        descriptor->colorAttachments()->object(0)->setBlendingEnabled(true);
        descriptor->colorAttachments()->object(0)->setRgbBlendOperation(MTL::BlendOperationAdd);
        descriptor->colorAttachments()->object(0)->setAlphaBlendOperation(MTL::BlendOperationAdd);
        descriptor->colorAttachments()->object(0)->setSourceRGBBlendFactor(MTL::BlendFactorSourceAlpha);
        descriptor->colorAttachments()->object(0)->setDestinationRGBBlendFactor(MTL::BlendFactorOneMinusSourceAlpha);
        descriptor->colorAttachments()->object(0)->setSourceAlphaBlendFactor(MTL::BlendFactorSourceAlpha);
        descriptor->colorAttachments()->object(0)->setDestinationAlphaBlendFactor(MTL::BlendFactorOneMinusSourceAlpha);

        if (vertexDescriptor != nullptr) {
            descriptor->setVertexDescriptor(vertexDescriptor);
        }

        // Set the label.
        if(label != "") {
            const NS::String *nsLabel = NS::String::string(label.c_str(), NS::StringEncoding::UTF8StringEncoding);
            descriptor->setLabel(nsLabel);
        }
        
        // Create pipeline state
        NS::Error* error = nullptr;
        MTL::RenderPipelineState* pipelineState = device->newRenderPipelineState(descriptor, &error);

        // Handle error
        if (error) {
            const char* c_str = error->debugDescription()->cString(NS::StringEncoding::UTF8StringEncoding);
            const std::string msg = "MetalRenderPipelineStateUtility::create: Failed to create render pipeline. Error: " + std::string(c_str);
            logger.error(msg);
            error->release();
            throw std::runtime_error(msg);
        }
        
        descriptor->release();
        
        return pipelineState;
    }

}

#endif
