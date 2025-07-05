//
// Created by Erkapic Luka on 26.6.2025.
//

#ifndef DX11_TRIANGLE_TEST_PIPELINE_H
#define DX11_TRIANGLE_TEST_PIPELINE_H

#ifdef _WIN32

#include "core/pipelines/test/a_triangle_test_pipeline.h"
#include "dx11/renderer/dx11_renderer.h"

namespace mars
{
	class Framework;

	//! A DirectX 11 implementation of the triangle test pipeline.
	class DX11TriangleTestPipeline : public ATriangleTestPipeline
	{
	public:
		//! Constructor for the DX11TriangleTestPipeline.
		//! @param framework The framework to use for rendering.
		DX11TriangleTestPipeline(Framework& framework);

		void render() override;

		void destroy() override;
	private:
		Framework& framework;

		DX11Renderer& renderer;

		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;

		ComPtr<ID3D11VertexShader> vertexShader;
		ComPtr<ID3D11PixelShader> pixelShader;

		void createShaders();

	};

}

#endif // _WIN32

#endif //DX11_TRIANGLE_TEST_PIPELINE_H
