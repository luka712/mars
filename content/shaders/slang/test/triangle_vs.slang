// Slang version of vertex shader with hardcoded triangle and colors
// Works in graphics APIs like Vulkan, D3D12 when using Slang

struct VSOutput {
    float4 position : SV_Position;
    float3 color    : COLOR0;
};

[shader("vertex")]
VSOutput main(uint vertexID : SV_VertexID)
{
    float2 positions[3] = {
        float2(0.0,  0.5),   // Top
        float2(0.5, -0.5),    // Bottom-right
        float2(-0.5, -0.5),  // Bottom-left
    };

    float3 colors[3] = {
        float3(1.0, 0.0, 0.0), // Red
        float3(0.0, 1.0, 0.0), // Green
        float3(0.0, 0.0, 1.0)  // Blue
    };

    VSOutput output;
    output.position = float4(positions[vertexID], 0.0, 1.0);
    output.color = colors[vertexID];
    return output;
}
