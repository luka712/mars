//
// Created by Luka Erkapic on 19.06.25.
//

#if __APPLE__

#include "util/metal/metal_utility.h"

namespace gpu_util {
    Logger *MetalUtility::logger = nullptr;
    MetalBufferUtility *MetalUtility::metalBufferUtil = nullptr;
    MetalTextureUtility *MetalUtility::metalTextureUtil = nullptr;
    MetalSamplerStateUtil *MetalUtility::metalSamplerStateUtil = nullptr;
    MetalRenderPipelineStateUtility *MetalUtility::metalRenderPipelineStateUtil = nullptr;
    MetalLibraryUtility *MetalUtility::metalLibraryUtility = nullptr;
    MetalFunctionUtility *MetalUtility::metalFunctionUtility = nullptr;
}

#endif
