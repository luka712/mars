//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_UTIL_H
#define METAL_UTIL_H

#if __APPLE__

#include "metal/util/metal_buffer_util.h"
#include "metal/util/metal_converter.h"
#include "metal/util/metal_texture_util.h"
#include "util/metal/metal_sampler_state_util.h"
#include "util/metal/metal_render_pipeline_state_utility.h"
#include "util/metal/metal_library_utility.h"
#include "util/metal/metal_function_utility.h"

namespace mars {


    class MetalUtil {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            logger.info("metal util initialize");
            metalConverter = new MetalConverter(logger);
            metalBufferUtil = new MetalBufferUtil(logger);
            metalTextureUtil = new MetalTextureUtil(logger);
            metalRenderPipelineStateUtil = new gpu_util::MetalRenderPipelineStateUtility(&logger);
            metalLibraryUtility = new gpu_util::MetalLibraryUtility(&logger);
            metalFunctionUtility = new gpu_util::MetalFunctionUtility(&logger);

            // TODO: create sampler util
        }

        //! Gets the MetalConverter. Used to convert framework formats to Metal formats.
        //! @return The MetalConverter pointer.
        static MetalConverter &getMetalConverter() { return *metalConverter; }

        //! Gets the MetalBufferUtil for working with buffers.
        //! @return The MetalBufferUtil ptr.
        static MetalBufferUtil &getBuffer() { return *metalBufferUtil; }

        //! Gets the MetalTextureUtil for working with textures.
        //! @return Tee MetalTextureUtil ptr.
        static MetalTextureUtil &getTexture() { return *metalTextureUtil; }

        //! Gets the MetalSamplerStateUtil for working with sampler state.
        //! @return The MetalSamplerStateUtil reference.
        static gpu_util::MetalSamplerStateUtil &getSamplerState() { return *metalSamplerStateUtil; }

        //! Gets the MetalRenderPipelineStateUtility for working with MTL::RenderPipelineState.
        //! @return The MetalRenderPipelineStateUtility reference.
        static gpu_util::MetalRenderPipelineStateUtility &getRenderPipelineState() { return *metalRenderPipelineStateUtil; }

        //! Gets the MetalLibraryUtility for working with MTL::Library.
        //! @return The MetalLibraryUtility reference.
        static gpu_util::MetalLibraryUtility &getLibrary() { return *metalLibraryUtility; }

        //! Gets the MetalFunctionUtility for working with MTL::Function.
        //! @return The MetalFunctionUtility reference.
        static gpu_util::MetalFunctionUtility &getFunction() { return *metalFunctionUtility; }

    private:
        static MetalConverter *metalConverter;
        static MetalBufferUtil *metalBufferUtil;
        static MetalTextureUtil *metalTextureUtil;
        static gpu_util::MetalSamplerStateUtil* metalSamplerStateUtil;
        static gpu_util::MetalRenderPipelineStateUtility *metalRenderPipelineStateUtil;
        static gpu_util::MetalLibraryUtility *metalLibraryUtility;
        static gpu_util::MetalFunctionUtility *metalFunctionUtility;
    };
}

#endif

#endif //METAL_UTIL_H
