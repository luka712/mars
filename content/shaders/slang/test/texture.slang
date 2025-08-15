// Simple shaders used for testing of passing position and color data.

struct VertexInput {
    float3 position : POSITION;
    float4 color    : COLOR0;
    float2 texCoord : TEXCOORD0; // Added texture coordinate for testing
};

struct VSOutput {
    float4 position : SV_Position;
    float4 color    : COLOR0;
    float2 texCoord : TEXCOORD0; // Pass through texture coordinate
};

[shader("vertex")]
VSOutput main_vs(VertexInput input)
{
    VSOutput output;
    output.position = float4(input.position, 1.0);
    output.color = input.color;
    output.texCoord = input.texCoord;
    return output;
}

Texture2D t_texture;
SamplerState s_sampler;

[shader("fragment")]
float4 main_vf(VSOutput input) : SV_TARGET
{
    // texture
    float4 texture = t_texture.Sample(s_sampler, input.texCoord);
    return texture * input.color;
}