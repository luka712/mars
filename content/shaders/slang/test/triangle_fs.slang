struct VSOutput
{
    float4 position : SV_Position;
    float3 color    : COLOR0;
}

[shader("fragment")]
float4 main(VSOutput input) : SV_TARGET
{
    return float4(input.color, 1.0);
}