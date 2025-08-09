struct VSOutput
{
    float4 position : SV_Position;
    float4 color : COLOR0;
    float2 texCoord : TEXCOORD0;
};

texture2D t_texture : register(t0);
sampler s_texture : register(s0);

float4 main(VSOutput input) : SV_Target
{
    // Output the color directly
    float4 tex_color = t_texture.Sample(s_texture, input.texCoord);
    return tex_color * input.color;
}