//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_UTIL_H
#define METAL_UTIL_H

#if __APPLE__

#include "gpu_util/metal/metal_buffer_util.h"
#include "metal_texture_utility.h"
#include "gpu_util/metal/metal_sampler_state_util.h"
#include "gpu_util/metal/metal_render_pipeline_state_utility.h"
#include "gpu_util/metal/metal_library_utility.h"
#include "gpu_util/metal/metal_function_utility.h"
#include "gpu_util/metal/metal_vertex_descriptor_util.h"

namespace gpu_util {

    //! The helper class for working with Metal.
    class MetalUtil {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger *logger) {
            logger->info("metal util initialize");
            metalBufferUtil = new MetalBufferUtil(*logger);
            metalTextureUtil = new MetalTextureUtility(*logger);
            metalRenderPipelineStateUtil = new MetalRenderPipelineStateUtility(*logger);
            metalLibraryUtility = new MetalLibraryUtility(*logger);
            metalFunctionUtility = new MetalFunctionUtility(*logger);
            metalVertexDescriptorUtil = new MetalVertexDescriptorUtil();

            // TODO: create sampler util
        }
        
        //! Initialize the MetalUtil.
        //! @param withDefaultLogger If <code>true</code>,  creates default logger.
        static void initialize(bool withDefaultLogger) {

            if (MetalUtil::logger != nullptr) {
                delete MetalUtil::logger;
            }

            if (withDefaultLogger) {
                MetalUtil::logger = new SpdLogger();
            }
            else {
                MetalUtil::logger = new MockLogger();
            }
            MetalUtil::initialize(logger);
        }

        //! Gets the MetalBufferUtil for working with buffers.
        //! @return The MetalBufferUtil ptr.
        static MetalBufferUtil &getBuffer() { return *metalBufferUtil; }

        //! Gets the MetalTextureUtil for working with textures.
        //! @return Tee MetalTextureUtil ptr.
        static MetalTextureUtility &getTexture() { return *metalTextureUtil; }

        //! Gets the MetalSamplerStateUtil for working with sampler state.
        //! @return The MetalSamplerStateUtil reference.
        static MetalSamplerStateUtil &getSamplerState() { return *metalSamplerStateUtil; }

        //! Gets the MetalRenderPipelineStateUtility for working with MTL::RenderPipelineState.
        //! @return The MetalRenderPipelineStateUtility reference.
        static MetalRenderPipelineStateUtility &getRenderPipelineState() { return *metalRenderPipelineStateUtil; }

        //! Gets the MetalLibraryUtility for working with MTL::Library.
        //! @return The MetalLibraryUtility reference.
        static MetalLibraryUtility &getLibrary() { return *metalLibraryUtility; }

        //! Gets the MetalFunctionUtility for working with MTL::Function.
        //! @return The MetalFunctionUtility reference.
        static MetalFunctionUtility &getFunction() { return *metalFunctionUtility; }

        // Gets the MetalVertexDescriptorUtil for working with MTL::VertexDescriptor.
        //! @return The MetalVertexDescriptorUtil reference.
        static MetalVertexDescriptorUtil& getVertexDescriptor() { return *metalVertexDescriptorUtil; }

    private:
        static Logger* logger;
        static MetalBufferUtil *metalBufferUtil;
        static MetalTextureUtility *metalTextureUtil;
        static MetalSamplerStateUtil* metalSamplerStateUtil;
        static MetalRenderPipelineStateUtility *metalRenderPipelineStateUtil;
        static MetalLibraryUtility *metalLibraryUtility;
        static MetalFunctionUtility *metalFunctionUtility;
        static MetalVertexDescriptorUtil *metalVertexDescriptorUtil;
    };
}

#endif

#endif //METAL_UTIL_H
