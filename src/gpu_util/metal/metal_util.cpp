//
// Created by Luka Erkapic on 19.06.25.
//

#if __APPLE__

#include "gpu_util/metal/metal_util.h"

namespace gpu_util {
    Logger *MetalUtil::logger = nullptr;
    MetalBufferUtil *MetalUtil::metalBufferUtil = nullptr;
    MetalTextureUtility *MetalUtil::metalTextureUtil = nullptr;
    MetalSamplerStateUtil *MetalUtil::metalSamplerStateUtil = nullptr;
    MetalRenderPipelineStateUtility *MetalUtil::metalRenderPipelineStateUtil = nullptr;
    MetalLibraryUtility *MetalUtil::metalLibraryUtility = nullptr;
    MetalFunctionUtility *MetalUtil::metalFunctionUtility = nullptr;
}

#endif
