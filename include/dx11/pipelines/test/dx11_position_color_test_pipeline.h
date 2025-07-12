//
// Created by lukaa on 12.7.2025..
//

#ifdef _WIN32

#ifndef DX11_POSITION_COLOR_TEST_PIPELINE_H
#define DX11_POSITION_COLOR_TEST_PIPELINE_H

#include "core/pipelines/test/a_position_color_test_pipeline.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/dx11.h"

using namespace Microsoft::WRL;

namespace mars
{
	class Framework;

	//! A DirectX 11 implementation of the position color test pipeline.
	class DX11PositionColorTestPipeline : public APositionColorTestPipeline
	{
	public:
		//! Constructor for the DX11PositionColorTestPipeline.
		//! @param framework The framework to use for rendering.
		explicit DX11PositionColorTestPipeline(Framework& framework);

		void render(AVertexBuffer& vertexBuffer) override;

		void destroy() override;

	private:
		Framework& framework;
		DX11Renderer& renderer;

		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;

		ComPtr<ID3D11VertexShader> vertexShader;
		ComPtr<ID3D11PixelShader> pixelShader;
		ComPtr<ID3D11InputLayout> inputLayout;

		void createShaders(ComPtr<ID3D10Blob> vertexBlob);
		void createInputLayout(ComPtr<ID3D10Blob> vertexBlob);

	};

}

#endif //DX11_POSITION_COLOR_TEST_PIPELINE_H

#endif // _WIN32