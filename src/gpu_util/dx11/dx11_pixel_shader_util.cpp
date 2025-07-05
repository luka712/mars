//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#include "gpu_util/dx11/dx11_pixel_shader_util.h"

ComPtr<ID3D11PixelShader> gpu_util::DX11PixelShaderUtil::create(ComPtr<ID3D11Device> device, ComPtr<ID3D10Blob> shaderBlob)
{
	ComPtr<ID3D11PixelShader> pixelShader;

	HRESULT hr = device->CreatePixelShader(
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		nullptr,
		&pixelShader
	);

	if (FAILED(hr)) {
		logger.error("DX11PixelShaderUtil::create: Failed to create pixel shader. HRESULT: " + std::to_string(hr));
		return nullptr;
	}

	logger.info("DX11PixelShaderUtil::create: Successfully created pixel shader.");
	return pixelShader;
}

#endif