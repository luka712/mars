#pragma pack_matrix(column_major)
#ifdef SLANG_HLSL_ENABLE_NVAPI
#include "nvHLSLExtns.h"
#endif

#ifndef __DXC_VERSION_MAJOR
// warning X3557: loop doesn't seem to do anything, forcing loop to unroll
#pragma warning(disable : 3557)
#endif


#line 4 "D:/Projects/ShaderToolkit/shader-toolkit-cli/target/release/temp_input.slang"
struct VSOutput_0
{
    float4 position_0 : SV_Position;
    float3 color_0 : COLOR0;
};

VSOutput_0 main(uint vertexID_0 : SV_VertexID)
{
    float2  positions_0[int(3)] = { float2(0.0f, 0.5f), float2(0.5f, -0.5f), float2(-0.5f, -0.5f) };

#line 18
    float3  colors_0[int(3)] = { float3(1.0f, 0.0f, 0.0f), float3(0.0f, 1.0f, 0.0f), float3(0.0f, 0.0f, 1.0f) };

#line 24
    VSOutput_0 output_0;
    output_0.position_0 = float4(positions_0[vertexID_0], 0.0f, 1.0f);
    output_0.color_0 = colors_0[vertexID_0];
    return output_0;
}

