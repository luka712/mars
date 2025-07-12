#pragma pack_matrix(column_major)
#ifdef SLANG_HLSL_ENABLE_NVAPI
#include "nvHLSLExtns.h"
#endif

#ifndef __DXC_VERSION_MAJOR
// warning X3557: loop doesn't seem to do anything, forcing loop to unroll
#pragma warning(disable : 3557)
#endif


#line 8 "D:/Projects/ShaderToolkit/shader-toolkit-cli/target/release/temp_input.slang"
struct VSOutput_0
{
    float4 position_0 : SV_Position;
    float4 color_0 : COLOR0;
};


#line 3
struct VertexInput_0
{
    float3 position_1 : POSITION;
    float4 color_1 : COLOR0;
};


#line 14
VSOutput_0 main(VertexInput_0 input_0)
{
    VSOutput_0 output_0;
    output_0.position_0 = float4(input_0.position_1, 1.0f);
    output_0.color_0 = input_0.color_1;
    return output_0;
}

