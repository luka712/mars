//
// Created by Erkapic Luka on 26.6.2025.
//

#ifdef _WIN32

#include "gpu_util/dx11/dx11_vertex_shader_util.h"

ComPtr<ID3D11VertexShader> gpu_util::DX11VertexShaderUtil::create(ComPtr<ID3D11Device> device, ComPtr<ID3D10Blob> shaderBlob)
{
	ComPtr<ID3D11VertexShader> vertexShader;
	HRESULT hr = device->CreateVertexShader(
		shaderBlob->GetBufferPointer(),
		shaderBlob->GetBufferSize(),
		nullptr,
		&vertexShader
	);

	if (FAILED(hr)) {
		logger.error("DX11VertexShaderUtil::create: Failed to create vertex shader. HRESULT: " + std::to_string(hr));
		return nullptr;
	}

	logger.info("DX11VertexShaderUtil::create: Successfully created vertex shader.");

	return vertexShader;
}

#endif