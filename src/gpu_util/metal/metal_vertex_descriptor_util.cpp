//
// Created by Luka Erkapic on 15.08.25.
//

#ifdef __APPLE__

#include "gpu_util/metal/metal_vertex_descriptor_util.h"

namespace gpu_util {

    MTL::VertexDescriptor* MetalVertexDescriptorUtil::createPositionColorTextureCoordinatesVertexDescriptor() {

        MTL::VertexDescriptor *vertexDescriptor = MTL::VertexDescriptor::alloc()->init();

        // Attribute 0: position (float3)
        vertexDescriptor->attributes()->object(0)->setFormat(MTL::VertexFormatFloat3);
        vertexDescriptor->attributes()->object(0)->setOffset(0);
        vertexDescriptor->attributes()->object(0)->setBufferIndex(0);

        // Attribute 1: color (float4)
        vertexDescriptor->attributes()->object(1)->setFormat(MTL::VertexFormatFloat4);
        vertexDescriptor->attributes()->object(1)->setOffset(sizeof(float) * 3);
        vertexDescriptor->attributes()->object(1)->setBufferIndex(0); // Interleaved buffer

        // Attribute 2: tex coords (float2)
        vertexDescriptor->attributes()->object(2)->setFormat(MTL::VertexFormatFloat4);
        vertexDescriptor->attributes()->object(2)->setOffset(sizeof(float) * 3 + sizeof(float) * 4);
        vertexDescriptor->attributes()->object(2)->setBufferIndex(0); // Interleaved buffer

        // Layout for buffer index 0
        vertexDescriptor->layouts()->object(0)->setStride(sizeof(float) * (4 + 3 + 2));
        vertexDescriptor->layouts()->object(0)->setStepRate(1);
        vertexDescriptor->layouts()->object(0)->setStepFunction(MTL::VertexStepFunctionPerVertex);

        return vertexDescriptor;
    }

}

#endif