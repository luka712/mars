//
// Created by Erkapic Luka on 26.6.2025.
//


#include "Framework.h"
#include "dx11/pipelines/test/dx11_texture_test_pipeline.h"
#include "gpu_util/dx11/dx11_util.h"
#include "dx11/buffers/dx11_vertex_buffer.h"
#include "dx11/buffers/dx11_index_buffer.h"
#include "dx11/texture/dx11_texture2d.h"

using namespace gpu_util;

namespace mars
{

	DX11TextureTestPipeline::DX11TextureTestPipeline(Framework& framework)
		: framework(framework), renderer(*dynamic_cast<mars::DX11Renderer*>(&framework.getRenderer()))
	{
		device = renderer.getDevice();
		deviceContext = renderer.getDeviceContext();
		ComPtr<ID3D10Blob> vertexShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/texture_vs.hlsl", "vs_5_0");

		if (vertexShaderBlob == nullptr || vertexShaderBlob->GetBufferSize() == 0) {
			throw std::runtime_error("DX11TextureTestPipeline::DX11TextureTestPipeline: vertex shader blob is empty or not found.");
		}

		createShaders(vertexShaderBlob);
		createInputLayout(vertexShaderBlob);
		vertexShaderBlob->Release();
	}

	void DX11TextureTestPipeline::createShaders(ComPtr<ID3D10Blob> vertexShaderBlob)
	{
		ComPtr<ID3D10Blob> pixelShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/texture_ps.hlsl", "ps_5_0");

		vertexShader = DX11Util::getVertexShader().create(device, vertexShaderBlob);
		pixelShader = DX11Util::getPixelShader().create(device, pixelShaderBlob);

		pixelShaderBlob->Release();
	}

	void DX11TextureTestPipeline::createInputLayout(ComPtr<ID3D10Blob> vertexShaderBlob)
	{
		inputLayout = DX11Util::getInputLayout()
			.createPositionColorTextureCoordinatesInputLayout(device, vertexShaderBlob);

		if (inputLayout == nullptr) {
			throw std::runtime_error("DX11TextureTestPipeline::createInputLayout: Failed to create input layout.");
		}
	}

	void DX11TextureTestPipeline::setTexture2D(ATexture2D* texture)
	{
		this->texture = toDX11Texture2D(texture);
	}

	void DX11TextureTestPipeline::render(AVertexBuffer& vertexBuffer)
	{
		DX11VertexBuffer& dx11VertexBuffer = *toDX11VertexBuffer(&vertexBuffer);

		// Bind the vertex buffer
		UINT stride = sizeof(float) * (3 + 4 + 2);
		UINT offset = 0;
		deviceContext->IASetVertexBuffers(0, 1, dx11VertexBuffer.getBuffer().GetAddressOf(), &stride, &offset);
		deviceContext->IASetInputLayout(inputLayout.Get());

		// Set texture and samplers
		deviceContext->PSSetShaderResources(0, 1, texture->getView().GetAddressOf());
		deviceContext->PSSetSamplers(0, 1, texture->getSamplerState().GetAddressOf());

		// Set shaders
		deviceContext->VSSetShader(vertexShader.Get(), nullptr, 0);
		deviceContext->PSSetShader(pixelShader.Get(), nullptr, 0);
		deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		deviceContext->Draw(vertexBuffer.getVertexCount(), 0); // Draw a triangle with 3 vertices
	}

	void DX11TextureTestPipeline::render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer)
	{
		DX11VertexBuffer& dx11VertexBuffer = *toDX11VertexBuffer(&vertexBuffer);
		DX11IndexBuffer& dx11IndexBuffer = *toDX11IndexBuffer(&indexBuffer);

		// Bind the vertex buffer
		UINT stride = sizeof(float) * (3 + 4 + 2);
		UINT offset = 0;
		deviceContext->IASetVertexBuffers(0, 1, dx11VertexBuffer.getBuffer().GetAddressOf(), &stride, &offset);
		DXGI_FORMAT indexFormat = dx11IndexBuffer.getType() == IndexBufferType::Uint16 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT;
		deviceContext->IASetIndexBuffer(dx11IndexBuffer.getBuffer().Get(), indexFormat, 0); // Assuming 16-bit indices
		deviceContext->IASetInputLayout(inputLayout.Get());

		// Set texture and samplers
		deviceContext->PSSetShaderResources(0, 1, texture->getView().GetAddressOf());
		deviceContext->PSSetSamplers(0, 1, texture->getSamplerState().GetAddressOf());

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

	void DX11TextureTestPipeline::destroy()
	{
		if (vertexShader) {
			vertexShader.Reset();
		}

		if (pixelShader) {
			pixelShader.Reset();
		}
	}

}