//
// Created by Erkapic Luka on 12.7.2025.
//

#include "gpu_util/dx11/dx11_input_layout_util.h"

#ifdef _WIN32

namespace gpu_util {

	ComPtr<ID3D11InputLayout> DX11InputLayoutUtil::create(
		ComPtr<ID3D11Device> device,
		ComPtr<ID3D10Blob> vertexShaderBlob,
		std::vector<D3D11_INPUT_ELEMENT_DESC>& layout
		) {

		Microsoft::WRL::ComPtr<ID3D11InputLayout> inputLayout;
		HRESULT hr = device->CreateInputLayout(
			layout.data(),
			layout.size(),
			vertexShaderBlob->GetBufferPointer(),
			vertexShaderBlob->GetBufferSize(),
			inputLayout.GetAddressOf()
		);

		if (FAILED(hr)) {
			logger.error("DX11InputLayoutUtil::createInputLayout: Failed to create input layout. HRESULT: " + std::to_string(hr));
			return nullptr;
		}

		logger.info("DX11InputLayoutUtil::createInputLayout: Successfully created input layout.");
		return inputLayout;
	}

	ComPtr<ID3D11InputLayout> DX11InputLayoutUtil::createPositionColorTextureCoordinatesInputLayout(
		ComPtr<ID3D11Device> device,
		ComPtr<ID3D10Blob> shaderBlob)
	{
		// Define the input layout for the vertex shader
		std::vector<D3D11_INPUT_ELEMENT_DESC> layout =
		{
			{ "POSITION", 0, DXGI_FORMAT_R32G32B32_FLOAT, 0, 0, D3D11_INPUT_PER_VERTEX_DATA, 0 },
			{ "COLOR", 0, DXGI_FORMAT_R32G32B32A32_FLOAT, 0, sizeof(float) * 3, D3D11_INPUT_PER_VERTEX_DATA, 0},
			{ "TEXCOORD", 0, DXGI_FORMAT_R32G32_FLOAT, 0, sizeof(float) * (3 + 4), D3D11_INPUT_PER_VERTEX_DATA, 0}
		};

		return create(device, shaderBlob, layout);
	}

} // namespace gpu_util


#endif
