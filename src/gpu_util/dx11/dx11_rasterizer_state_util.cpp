#include "gpu_util/dx11/dx11_rasterizer_state_util.h"

#ifdef _WIN32

ComPtr<ID3D11RasterizerState> gpu_util::DX11RasterizerStateUtil::createRasterizerState(
	ComPtr<ID3D11Device>& device,
	D3D11_FILL_MODE fillMode,
	D3D11_CULL_MODE cullMode,
	BOOL frontCounterClockwise,
	INT depthBias,
	FLOAT depthBiasClamp,
	FLOAT slopeScaledDepthBias,
	BOOL depthClipEnable,
	BOOL scissorEnable,
	BOOL multisampleEnable,
	BOOL antialiasedLineEnable,
	const std::string& label
)
{
	ComPtr<ID3D11RasterizerState> rasterizerState;
	if (!device) {
		logger.error("DX11RasterizerStateUtil::createRasterizerState: Device is null.");
		return rasterizerState;
	}

	D3D11_RASTERIZER_DESC rasterizerDesc = {};
	rasterizerDesc.FillMode = fillMode;
	rasterizerDesc.CullMode = cullMode;
	rasterizerDesc.FrontCounterClockwise = frontCounterClockwise;
	rasterizerDesc.DepthBias = depthBias;
	rasterizerDesc.DepthBiasClamp = depthBiasClamp;
	rasterizerDesc.SlopeScaledDepthBias = slopeScaledDepthBias;
	rasterizerDesc.DepthClipEnable = depthClipEnable;
	rasterizerDesc.ScissorEnable = scissorEnable;
	rasterizerDesc.MultisampleEnable = multisampleEnable;
	rasterizerDesc.AntialiasedLineEnable = antialiasedLineEnable;
	HRESULT hr = device->CreateRasterizerState(&rasterizerDesc, &rasterizerState);
	if (FAILED(hr)) {
		logger.error("DX11RasterizerStateUtil::createRasterizerState: Failed to create rasterizer state.");
		return nullptr;
	}

	if (!label.empty()) {
		rasterizerState->SetPrivateData(WKPDID_D3DDebugObjectName, static_cast<UINT>(label.size()), label.c_str());
	}

	return rasterizerState;
}

#endif
