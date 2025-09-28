//
// Created by Erkapic Luka on 10.02.25.
//

#ifdef _WIN32

#include <glm/gtc/type_ptr.hpp>
#include "dx11/pipelines/sprite/dx11_sprite_render_pipeline.h"
#include <Framework.h>
#include <core/math/Matrix.h>
#include "gpu_util/DX11/DX11_util.h"
#include <dx11/buffers/dx11_vertex_buffer.h>
#include <dx11/buffers/dx11_index_buffer.h>

using namespace gpu_util;

namespace mars {
	DX11SpriteRenderPipeline::DX11SpriteRenderPipeline(
		Framework& framework, OrthographicCamera* camera, const Culling culling)
		: framework(framework),
		renderer(toDX11Renderer(&framework.getRenderer())),
		camera(camera),
		culling(culling),
		texture(nullptr)
	{
		device = renderer->getDevice();
		context = renderer->getDeviceContext();
		createInputAndShaders();
	}

	ATexture2D* DX11SpriteRenderPipeline::getSpriteTexture()
	{
		return texture;
	}

	void DX11SpriteRenderPipeline::setSpriteTexture(ATexture2D* spriteTexture) {
		texture = toDX11Texture2D(spriteTexture);
	}

	void DX11SpriteRenderPipeline::createInputAndShaders() {

		ComPtr<ID3D10Blob> vertexBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/sprite/sprite_vs.hlsl", "vs_5_0");
		ComPtr<ID3D10Blob> pixelBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/sprite/sprite_ps.hlsl", "ps_5_0");

		vertexShader = DX11Util::getVertexShader().create(device, vertexBlob);
		pixelShader = DX11Util::getPixelShader().create(device, pixelBlob);

		inputLayout = DX11Util::getInputLayout().createPositionColorTextureCoordinatesInputLayout(device, vertexBlob);

		// Safe to release the blobs after creating the shaders and input layout.
		pixelBlob->Release();
		vertexBlob->Release();
	}

	void DX11SpriteRenderPipeline::render(
		AVertexBuffer* vertexBuffer,
		AIndexBuffer* indexBuffer,
		const uint32_t indicesCount,
		const uint32_t indicesOffset) {

#if DEBUG
		assert(camera != nullptr);
#endif

		const DX11VertexBuffer& dx11VertexBuffer = *toDX11VertexBuffer(vertexBuffer);
		const DX11IndexBuffer& dx11IndexBuffer = *toDX11IndexBuffer(indexBuffer);

		// Bind the vertex buffer
		UINT stride = sizeof(float) * (3 + 4 + 2);
		UINT offset = 0;
		context->IASetVertexBuffers(0, 1, dx11VertexBuffer.getBuffer().GetAddressOf(), &stride, &offset);
		DXGI_FORMAT indexFormat = dx11IndexBuffer.getType() == IndexBufferType::Uint16 ? DXGI_FORMAT_R16_UINT : DXGI_FORMAT_R32_UINT;
		context->IASetIndexBuffer(dx11IndexBuffer.getBuffer().Get(), indexFormat, 0); // Assuming 16-bit indices
		context->IASetInputLayout(inputLayout.Get());

		// Set texture and samplers
		context->PSSetShaderResources(0, 1, texture->getView().GetAddressOf());
		context->PSSetSamplers(0, 1, texture->getSamplerState().GetAddressOf());

		// Set shaders
		context->VSSetShader(vertexShader.Get(), nullptr, 0);
		context->PSSetShader(pixelShader.Get(), nullptr, 0);
		context->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
		context->DrawIndexed(
			dx11IndexBuffer.getIndicesCount(), // Number of indices to draw
			0, // Index offset
			0 // Vertex offset
		);
	}

	void DX11SpriteRenderPipeline::destroy() {
		vertexShader->Release();
		pixelShader->Release();
		inputLayout->Release();
	}
}

#endif // _WIN32