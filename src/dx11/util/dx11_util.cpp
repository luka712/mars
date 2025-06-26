//
// Created by Erkapic Luka on 26.6.2025..
//

#ifndef _DX11

#define _DX11

#include "dx11/util/dx11_util.h"

namespace mars {

    DX11DxgiFactoryUtil *DX11Util::dxgiFactoryUtil = nullptr;
    DX11DeviceUtil *DX11Util::dx11DeviceUtil = nullptr;
    DX11DxgiDeviceUtil *DX11Util::dxgiDeviceUtil = nullptr;
    DX11DxgiSwapChainUtil *DX11Util::dxgiSwapChainUtil = nullptr;
    DX11RenderTargetViewUtility *DX11Util::renderTargetViewUtility = nullptr;
	gpu_util::DX11BlobUtil* DX11Util::dx11BlobUtil = nullptr;
	gpu_util::DX11VertexShaderUtil* DX11Util::dx11VertexShaderUtil = nullptr;
	gpu_util::DX11PixelShaderUtil* DX11Util::dx11PixelShaderUtil = nullptr;

} // namespace mars

#endif
