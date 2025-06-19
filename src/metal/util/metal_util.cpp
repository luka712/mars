//
// Created by Luka Erkapic on 19.06.25.
//

#if __APPLE__

#include "metal/util/metal_util.h"

namespace mars {
    mars::MetalConverter* mars::MetalUtil::metalConverter = nullptr;
    MetalBufferUtil *MetalUtil::metalBufferUtil= nullptr;
    MetalTextureUtil *MetalUtil::metalTextureUtil= nullptr;
    gpu_util::MetalSamplerStateUtil* MetalUtil::metalSamplerStateUtil= nullptr;
    gpu_util::MetalRenderPipelineStateUtility *MetalUtil::metalRenderPipelineStateUtil= nullptr;
    gpu_util::MetalLibraryUtility *MetalUtil::metalLibraryUtility= nullptr;
    gpu_util::MetalFunctionUtility *MetalUtil::metalFunctionUtility= nullptr;
}

#endif