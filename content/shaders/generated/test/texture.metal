#include <metal_stdlib>
#include <metal_math>
#include <metal_texture>
using namespace metal;

#line 1875 "hlsl.meta.slang"
struct pixelOutput_0
{
    float4 output_0 [[color(0)]];
};


#line 1875
struct pixelInput_0
{
    float4 color_0 [[user(COLOR)]];
    float2 texCoord_0 [[user(TEXCOORD)]];
};


#line 1875
struct KernelContext_0
{
    texture2d<float, access::sample> t_texture_0;
    sampler s_sampler_0;
};


#line 29 "/var/folders/th/gm4_84wx0xz04n6mx9h2092w0000gn/T/__temp__.slang"
[[fragment]] pixelOutput_0 main_fs(pixelInput_0 _S1 [[stage_in]], float4 position_0 [[position]], texture2d<float, access::sample> t_texture_1 [[texture(0)]], sampler s_sampler_1 [[sampler(0)]])
{

#line 29
    KernelContext_0 kernelContext_0;

#line 29
    (&kernelContext_0)->t_texture_0 = t_texture_1;

#line 29
    (&kernelContext_0)->s_sampler_0 = s_sampler_1;

#line 29
    pixelOutput_0 _S2 = { (((&kernelContext_0)->t_texture_0).sample((s_sampler_1), (_S1.texCoord_0))) * _S1.color_0 };



    return _S2;
}


#line 33
struct main_vs_Result_0
{
    float4 position_1 [[position]];
    float4 color_1 [[user(COLOR)]];
    float2 texCoord_1 [[user(TEXCOORD)]];
};


#line 2193 "core.meta.slang"
struct vertexInput_0
{
    float3 position_2 [[attribute(0)]];
    float4 color_2 [[attribute(1)]];
    float2 texCoord_2 [[attribute(2)]];
};


#line 9 "/var/folders/th/gm4_84wx0xz04n6mx9h2092w0000gn/T/__temp__.slang"
struct VSOutput_0
{
    float4 position_3;
    float4 color_3;
    float2 texCoord_3;
};


#line 9
[[vertex]] main_vs_Result_0 main_vs(vertexInput_0 _S3 [[stage_in]], texture2d<float, access::sample> t_texture_2 [[texture(0)]], sampler s_sampler_2 [[sampler(0)]])
{

#line 9
    KernelContext_0 kernelContext_1;

#line 9
    (&kernelContext_1)->t_texture_0 = t_texture_2;

#line 9
    (&kernelContext_1)->s_sampler_0 = s_sampler_2;

#line 18
    thread VSOutput_0 output_1;
    (&output_1)->position_3 = float4(_S3.position_2, 1.0);
    (&output_1)->color_3 = _S3.color_2;
    (&output_1)->texCoord_3 = _S3.texCoord_2;

#line 21
    thread main_vs_Result_0 _S4;

#line 21
    (&_S4)->position_1 = output_1.position_3;

#line 21
    (&_S4)->color_1 = output_1.color_3;

#line 21
    (&_S4)->texCoord_1 = output_1.texCoord_3;

#line 21
    return _S4;
}

