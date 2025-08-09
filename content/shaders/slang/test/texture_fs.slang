struct VSOutput
{
    float4 position : SV_Position;
    float4 color    : COLOR0;
    float2 texCoord : TEXCOORD0; // Added texture coordinate for testing
}

[format("rgba8")]
Texture2D<float4> t_texture;

[playground::SAMPLER]
SamplerState s_sampler;

[shader("fragment")]
float4 main(VSOutput input) : SV_TARGET
{
    // texture
    float4 texture = s_sampler.Sample(t_texture, input.texCoord);
    return texture * input.color;
}