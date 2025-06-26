//
// Created by Luka Erkapic on 18.06.25.
//
#pragma once

#if __APPLE__

#ifndef METAL_RENDER_PIPELINE_STATE_UTILITY_H
#define METAL_RENDER_PIPELINE_STATE_UTILITY_H

#include "metal/metal.h"
#include "gpu_util/logger.h"

namespace gpu_util {
    class MetalRenderPipelineStateUtility {
    public:

        //! The constructor.
        //! @param logger The optional logger.
        explicit MetalRenderPipelineStateUtility(Logger &logger) : logger(logger) {}

        //! Creates a new MTL::RenderPipelineState.
        //!
        //! @param device The pointer to the MTL::Device.
        //! @param vertexFunction The pointer to the MTL::Function used by vertex shader.
        //! @param fragmentFunction The pointer to the MTL::Function used by fragment shader.
        //! @parma label The label. By default, it is empty string.
        //!
        //! @return A new pointer to MTL::RenderPipelineState if successful, or nullptr if failed.
        //!
        //! @note The caller is responsible for managing the lifetime of the returned pipeline state.
        //!
        //! @see https://developer.apple.com/documentation/metal/mtlrenderpipelinestate
        MTL::RenderPipelineState *create(MTL::Device* device,
            MTL::Function* vertexFunction,
            MTL::Function* fragmentFunction,
            const std::string& label = "");

        private:
            Logger &logger;
    };
}

#endif //METAL_RENDER_PIPELINE_STATE_UTILITY_H

#endif
