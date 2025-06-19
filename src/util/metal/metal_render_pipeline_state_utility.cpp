//
// Created by Luka Erkapic on 18.06.25.
//

#if __APPLE__

#include <stdexcept>
#include "../../../include/util/metal/metal_render_pipeline_state_utility.h"

#include "../../../../../../../../Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/string"

namespace gpu_util {

MetalRenderPipelineStateUtility::MetalRenderPipelineStateUtility(mars::Logger* logger)
: logger(logger) {}

    MTL::RenderPipelineState *MetalRenderPipelineStateUtility::create(
                                                                      MTL::Device* device,
                                                                      MTL::Function* vertexFunction,
                                                                      MTL::Function* fragmentFunction,
                                                                      const std::string& label) {
        
        MTL::RenderPipelineDescriptor* descriptor = MTL::RenderPipelineDescriptor::alloc()->init();
        descriptor->setVertexFunction(vertexFunction);
        descriptor->setFragmentFunction(fragmentFunction);
        descriptor->colorAttachments()->object(0)->setPixelFormat(MTL::PixelFormatBGRA8Unorm);
        
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
            if(logger != nullptr){
                logger->error(msg);
            }
            error->release();
            throw std::runtime_error(msg);
        }
        
        descriptor->release();
        
        return pipelineState;
    }

}

#endif
