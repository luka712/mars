#include "gpu_util/dx11/dx11_sampler_state_util.h"
#include <stdexcept>

#ifdef _WIN32

//
// Created by lukaa on 9.8.2025..
//

ComPtr<ID3D11SamplerState> gpu_util::DX11SamplerStateUtil::createSamplerState(
    ComPtr<ID3D11Device> device,
    D3D11_FILTER filter,
    D3D11_TEXTURE_ADDRESS_MODE addressU,
    D3D11_TEXTURE_ADDRESS_MODE addressV,
    D3D11_TEXTURE_ADDRESS_MODE addressW,
    const std::string& label)
{
    ComPtr<ID3D11SamplerState> samplerState;
    D3D11_SAMPLER_DESC samplerDesc = {};
    samplerDesc.Filter = filter;
    samplerDesc.AddressU = addressU;
    samplerDesc.AddressV = addressV;
    samplerDesc.AddressW = addressW;
    samplerDesc.ComparisonFunc = D3D11_COMPARISON_NEVER; // No comparison
    samplerDesc.MinLOD = 0.0f;
    samplerDesc.MaxLOD = D3D11_FLOAT32_MAX; // No LOD limit
    samplerDesc.MipLODBias = 0.0f;
    samplerDesc.MaxAnisotropy = 1; // No anisotropic filtering
    HRESULT hr = device->CreateSamplerState(&samplerDesc, &samplerState);

    if (FAILED(hr)) {
        logger.error("Failed to create sampler state.");
        throw std::runtime_error("Failed to create sampler state.");
    }

    if (samplerState == nullptr) {
        logger.error("Sampler state is null after creation.");
        throw std::runtime_error("Sampler state is null after creation.");
    }

    if (!label.empty()) {
        samplerState->SetPrivateData(WKPDID_D3DDebugObjectName, static_cast<UINT>(label.size()), label.c_str());
    }

    logger.info("Sampler state created successfully.");

    return samplerState;
}

#endif 
