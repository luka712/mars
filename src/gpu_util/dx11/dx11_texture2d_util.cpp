//
// Created by Erkapic Luka on 9.8.2025.
//

#include "gpu_util/dx11/dx11_texture2d_util.h"

#ifdef _WIN32

namespace gpu_util {

    ComPtr<ID3D11Texture2D> DX11Texture2DUtil::create(
        ComPtr<ID3D11Device> device,
        ComPtr<ID3D11DeviceContext> context,
        const void *data,
        uint32_t width,
        uint32_t height,
        const DXGI_FORMAT format,
        const D3D11_USAGE usage,
        UINT bindFlags,
        const std::string& label
        ) {

        D3D11_TEXTURE2D_DESC textureDesc = {};
        textureDesc.Width = width;
        textureDesc.Height = height;
        textureDesc.MipLevels = 1;
        textureDesc.ArraySize = 1;
        textureDesc.Format = format;
        textureDesc.SampleDesc.Count = 1;
        textureDesc.Usage = usage;
        textureDesc.BindFlags = bindFlags;
        textureDesc.CPUAccessFlags = 0; // No CPU access for this example
        textureDesc.MiscFlags = 0;

        D3D11_SUBRESOURCE_DATA initData = {};
        initData.pSysMem = data;
        initData.SysMemPitch = width * 4; // Assuming 4 bytes per pixel (RGBA)

        ComPtr<ID3D11Texture2D> texture;
        HRESULT hr = device->CreateTexture2D(&textureDesc, data ? &initData : nullptr, &texture);

        if (FAILED(hr)) {
            logger.error("Failed to create DirectX 11 Texture2D. HRESULT: " + std::to_string(hr));
            return nullptr;
        }

		if (!label.empty()) {
			texture->SetPrivateData(WKPDID_D3DDebugObjectName, static_cast<UINT>(label.size()), label.c_str());
		}

        logger.info("Successfully created DirectX 11 Texture2D with label: " + std::to_string(reinterpret_cast<uintptr_t>(texture.Get())));

        return texture;
    }

} // namespace gpu_util

#endif
