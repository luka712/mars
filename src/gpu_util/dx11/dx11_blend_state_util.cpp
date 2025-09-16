//
// Created by Erkapic Luka on 16.8.2025.
//

#ifdef _WIN32
#include "gpu_util/dx11/dx11_blend_state_util.h"

namespace gpu_util {

    ComPtr<ID3D11BlendState> DX11BlendStateUtil::create(
        ComPtr<ID3D11Device> device,
        bool blendEnable,
        D3D11_BLEND srcBlend,
        D3D11_BLEND destBlend,
        D3D11_BLEND_OP blendOp
    ) {
        ComPtr<ID3D11BlendState> blendState;
        D3D11_BLEND_DESC blendDesc = {};
        blendDesc.AlphaToCoverageEnable = false;
        blendDesc.IndependentBlendEnable = false;

        blendDesc.RenderTarget[0].BlendEnable = blendEnable;
        blendDesc.RenderTarget[0].SrcBlend = srcBlend;
        blendDesc.RenderTarget[0].DestBlend = destBlend;
        blendDesc.RenderTarget[0].BlendOp = blendOp;
        blendDesc.RenderTarget[0].SrcBlendAlpha = D3D11_BLEND_ONE;
        blendDesc.RenderTarget[0].DestBlendAlpha = D3D11_BLEND_ZERO;
        blendDesc.RenderTarget[0].BlendOpAlpha = D3D11_BLEND_OP_ADD;
        blendDesc.RenderTarget[0].RenderTargetWriteMask = D3D11_COLOR_WRITE_ENABLE_ALL;

        HRESULT hr = device->CreateBlendState(&blendDesc, &blendState);
        if (FAILED(hr)) {
            logger.error("DX11BlendStateUtil:: Failed to create blend state.");
            return nullptr; // Return nullptr if creation failed
        }

        return blendState;
    }

}

#endif