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
VSOutput main(VertexInput input)
{
    VSOutput output;
    output.position = float4(input.position, 1.0);
    output.color = input.color;
    output.texCoord = input.texCoord;
    return output;
}
