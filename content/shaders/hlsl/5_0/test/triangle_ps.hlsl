#pragma pack_matrix(column_major)
#ifdef SLANG_HLSL_ENABLE_NVAPI
#include "nvHLSLExtns.h"
#endif

#ifndef __DXC_VERSION_MAJOR
// warning X3557: loop doesn't seem to do anything, forcing loop to unroll
#pragma warning(disable : 3557)
#endif


#line 1 "D:/Projects/ShaderToolkit/shader-toolkit-cli/target/release/temp_input.slang"
struct VSOutput_0
{
    float4 position_0 : SV_Position;
    float3 color_0 : COLOR0;
};


float4 main(VSOutput_0 input_0) : SV_TARGET
{
    return float4(input_0.color_0, 1.0f);
}

