//
// Created by Erkapic Luka on 12.7.2025.
//

#include "gpu_util/dx11/dx11_input_layout_util.h"

#ifdef _WIN32

namespace gpu_util {

	Microsoft::WRL::ComPtr<ID3D11InputLayout> DX11InputLayoutUtil::create(
		Microsoft::WRL::ComPtr<ID3D11Device> device,
		Microsoft::WRL::ComPtr<ID3D10Blob> vertexShaderBlob,
		std::vector<D3D11_INPUT_ELEMENT_DESC> layout
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

} // namespace gpu_util


#endif
