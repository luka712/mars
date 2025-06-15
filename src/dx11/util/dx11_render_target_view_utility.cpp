//
// Created by Erkapic Luka on 12.6.2025.
//

#ifdef _WIN32

#include "dx11/util/dx11_render_target_view_utility.h"

namespace mars {

    ComPtr<ID3D11RenderTargetView> DX11RenderTargetViewUtility::createRenderTargetView(
        ComPtr<ID3D11Device> device,
        ComPtr<ID3D11Texture2D> texture,
        const DXGI_FORMAT format) {

        D3D11_RENDER_TARGET_VIEW_DESC rtvDesc = {};
        rtvDesc.Format = format;
        rtvDesc.ViewDimension = D3D11_RTV_DIMENSION_TEXTURE2D;
        rtvDesc.Texture2D.MipSlice = 0;

        ComPtr<ID3D11RenderTargetView> renderTargetView;
        HRESULT hr = device->CreateRenderTargetView(texture.Get(), &rtvDesc, renderTargetView.GetAddressOf());

        if (FAILED(hr)) {
            std::string msg = "DX11RenderTargetViewUtility::createRenderTargetView: Failed to create render target view. HRESULT: " + std::to_string(hr);
            logger.error(msg);
            throw std::runtime_error(msg);
        }

        return renderTargetView;
    }

} // namespace mars

#endif
