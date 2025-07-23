//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#include "Framework.h"
#include "dx11/pipelines/test/dx11_position_color_test_pipeline.h"
#include "gpu_util/dx11/dx11_util.h"
#include "dx11/buffers/dx11_vertex_buffer.h"
#include "dx11/buffers/dx11_index_buffer.h"

using namespace gpu_util;

mars::DX11PositionColorTestPipeline::DX11PositionColorTestPipeline(Framework& framework)
	: framework(framework), renderer(*dynamic_cast<mars::DX11Renderer*>(&framework.getRenderer()))
{
	device = renderer.getDevice();
	deviceContext = renderer.getDeviceContext();
	ComPtr<ID3D10Blob> vertexShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/position_color_vs.hlsl", "vs_5_0");
	createShaders(vertexShaderBlob);
	createInputLayout(vertexShaderBlob);
	vertexShaderBlob->Release();
}

void mars::DX11PositionColorTestPipeline::createShaders(ComPtr<ID3D10Blob> vertexShaderBlob)
{
	ComPtr<ID3D10Blob> pixelShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/position_color_ps.hlsl", "ps_5_0");

	vertexShader = DX11Util::getVertexShader().create(device, vertexShaderBlob);
	pixelShader = DX11Util::getPixelShader().create(device, pixelShaderBlob);

	pixelShaderBlob->Release();
}

void mars::DX11PositionColorTestPipeline::createInputLayout(ComPtr<ID3D10Blob> vertexShaderBlob)
{
	// Define the input layout for the vertex shader
	std::vector<D3D11_INPUT_ELEMENT_DESC> layout =
	{
		{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
		{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, 12, D3D11_INPUT_PER_VERTEX_DATA, 0 }
	};

	inputLayout = DX11Util::getInputLayout().create(device, vertexShaderBlob, layout);
}

void mars::DX11PositionColorTestPipeline::render(AVertexBuffer& vertexBuffer)
{
	DX11VertexBuffer& dx11VertexBuffer = *toDX11VertexBuffer(&vertexBuffer);

	// Bind the vertex buffer
	UINT stride = sizeof(float) * 7; // Assuming 3 floats for position and 4 floats for color
	UINT offset = 0;
	deviceContext->IASetVertexBuffers(0, 1, dx11VertexBuffer.getBuffer().GetAddressOf(), &stride, &offset);
	deviceContext->IASetInputLayout(inputLayout.Get());

	// Set shaders
	deviceContext->VSSetShader(vertexShader.Get(), nullptr, 0);
	deviceContext->PSSetShader(pixelShader.Get(), nullptr, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	deviceContext->Draw(vertexBuffer.getVertexCount(), 0); // Draw a triangle with 3 vertices
}

void mars::DX11PositionColorTestPipeline::render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer)
{
	DX11VertexBuffer& dx11VertexBuffer = *toDX11VertexBuffer(&vertexBuffer);
	DX11IndexBuffer& dx11IndexBuffer = *toDX11IndexBuffer(&indexBuffer);

	// Bind the vertex buffer
	UINT stride = sizeof(float) * 7; // Assuming 3 floats for position and 4 floats for color
	UINT offset = 0;
	deviceContext->IASetVertexBuffers(0, 1, dx11VertexBuffer.getBuffer().GetAddressOf(), &stride, &offset);
	DXGI_FORMAT indexFormat = dx11IndexBuffer.getType() == IndexBufferType::Uint16 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT;
	deviceContext->IASetIndexBuffer(dx11IndexBuffer.getBuffer().Get(), indexFormat, 0); // Assuming 16-bit indices
	deviceContext->IASetInputLayout(inputLayout.Get());

	// Set shaders
	deviceContext->VSSetShader(vertexShader.Get(), nullptr, 0);
	deviceContext->PSSetShader(pixelShader.Get(), nullptr, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	deviceContext->DrawIndexed(
		dx11IndexBuffer.getIndicesCount(), // Number of indices to draw
		0, // Index offset
		0 // Vertex offset
	);
}

void mars::DX11PositionColorTestPipeline::destroy()
{
	if (vertexShader) {
		vertexShader.Reset();
	}

	if (pixelShader) {
		pixelShader.Reset();
	}
}



#endif // _WIN32
