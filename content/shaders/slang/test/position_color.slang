// Simple shaders used for testing of passing position and color data.

struct VertexInput {
    float3 position : POSITION;
    float4 color    : COLOR0;
};

struct VSOutput {
    float4 position : SV_Position;
    float4 color    : COLOR0;
};

[shader("vertex")]
VSOutput main_vs(VertexInput input)
{
    VSOutput output;
    output.position = float4(input.position, 1.0);
    output.color = input.color;
    return output;
}

[shader("fragment")]
float4 main_fs(VSOutput input) : SV_TARGET
{
    return input.color;
}