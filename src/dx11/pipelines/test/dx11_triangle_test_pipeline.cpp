//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#include "Framework.h"
#include "dx11/pipelines/test/dx11_triangle_test_pipeline.h"
#include "dx11/util/dx11_util.h"

mars::DX11TriangleTestPipeline::DX11TriangleTestPipeline(Framework& framework)
	: framework(framework), renderer(*dynamic_cast<mars::DX11Renderer*>(&framework.getRenderer()))
{
	device = renderer.getDevice();
	deviceContext = renderer.getDeviceContext();
	createShaders();
}

void mars::DX11TriangleTestPipeline::createShaders()
{
	ComPtr<ID3D10Blob> vertexShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/triangle_vs.hlsl", "vs_5_0");
	ComPtr<ID3D10Blob> pixelShaderBlob = DX11Util::getBlob().create("content/shaders/hlsl/5_0/test/triangle_ps.hlsl", "ps_5_0");

	vertexShader = DX11Util::getVertexShader().create(device, vertexShaderBlob);
	pixelShader = DX11Util::getPixelShader().create(device, pixelShaderBlob);

	vertexShaderBlob->Release();
	pixelShaderBlob->Release();
}

void mars::DX11TriangleTestPipeline::render()
{
	deviceContext->VSSetShader(vertexShader.Get(), nullptr, 0);
	deviceContext->PSSetShader(pixelShader.Get(), nullptr, 0);
	deviceContext->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
	deviceContext->Draw(3, 0); // Draw a triangle with 3 vertices
}

void mars::DX11TriangleTestPipeline::destroy()
{
	if (vertexShader) {
		vertexShader.Reset();
	}

	if (pixelShader) {
		pixelShader.Reset();
	}
}



#endif // _WIN32
