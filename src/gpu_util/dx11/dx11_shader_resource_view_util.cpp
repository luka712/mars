#include "gpu_util/dx11/dx11_shader_resource_view_util.h"
#include <stdexcept>

#ifdef _WIN32

ComPtr<ID3D11ShaderResourceView> gpu_util::DX11ShaderResourceViewUtil::createTexure2DView(
    ComPtr<ID3D11Device> device, 
    ComPtr<ID3D11Resource> texture,
    DXGI_FORMAT format,
    const std::string& label
    )
{
    D3D11_SHADER_RESOURCE_VIEW_DESC descriptor = {};
    descriptor.Format = format;
    descriptor.ViewDimension = D3D10_1_SRV_DIMENSION_TEXTURE2D;
    descriptor.Texture2D.MipLevels = 1;
    descriptor.Texture2D.MostDetailedMip = 0;

    ComPtr<ID3D11ShaderResourceView> shaderResourceView;
    HRESULT hr = device->CreateShaderResourceView(texture.Get(), &descriptor, &shaderResourceView);

    if (FAILED(hr)) {
        logger.error("Failed to create shader resource view for texture.");
        throw std::runtime_error("Failed to create shader resource view for texture.");
    }

    if (shaderResourceView == nullptr) {
        logger.error("Shader resource view is null after creation.");
        throw std::runtime_error("Shader resource view is null after creation.");
    }

    if (!label.empty()) {
        shaderResourceView->SetPrivateData(WKPDID_D3DDebugObjectName, static_cast<UINT>(label.size()), label.c_str());
    }

    logger.info("Shader resource view created successfully for texture.");

    return shaderResourceView;
}

#endif
