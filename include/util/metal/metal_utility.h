//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_UTIL_H
#define METAL_UTIL_H

#if __APPLE__

#include "util/metal/metal_buffer_utility.h"
#include "metal/util/metal_converter.h"
#include "metal_texture_utility.h"
#include "spdlog/logger.h"
#include "util/metal/metal_sampler_state_util.h"
#include "util/metal/metal_render_pipeline_state_utility.h"
#include "util/metal/metal_library_utility.h"
#include "util/metal/metal_function_utility.h"


namespace gpu_util {

    //! The helper class for working with Metal.
    class MetalUtility {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger *logger) {
            logger->info("metal util initialize");
            metalBufferUtil = new MetalBufferUtility(*logger);
            metalTextureUtil = new MetalTextureUtility(*logger);
            metalRenderPipelineStateUtil = new MetalRenderPipelineStateUtility(*logger);
            metalLibraryUtility = new MetalLibraryUtility(*logger);
            metalFunctionUtility = new MetalFunctionUtility(*logger);

            // TODO: create sampler util
        }
        
        //! Initialize the MetalUtil.
        //! @param withDefaultLogger If <code>true</code>,  creates default logger.
        static void initialize(bool withDefaultLogger) {

            if (MetalUtility::logger != nullptr) {
                delete MetalUtility::logger;
            }

            if (withDefaultLogger) {
                MetalUtility::logger = new SpdLogger();
            }
            else {
                MetalUtility::logger = new MockLogger();
            }
            MetalUtility::initialize(logger);
        }

        //! Gets the MetalBufferUtil for working with buffers.
        //! @return The MetalBufferUtil ptr.
        static MetalBufferUtility &getBuffer() { return *metalBufferUtil; }

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

    private:
        static Logger* logger;
        static MetalBufferUtility *metalBufferUtil;
        static MetalTextureUtility *metalTextureUtil;
        static MetalSamplerStateUtil* metalSamplerStateUtil;
        static MetalRenderPipelineStateUtility *metalRenderPipelineStateUtil;
        static MetalLibraryUtility *metalLibraryUtility;
        static MetalFunctionUtility *metalFunctionUtility;
    };
}

#endif

#endif //METAL_UTIL_H
