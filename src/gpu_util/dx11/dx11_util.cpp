//
// Created by Erkapic Luka on 26.6.2025..
//

#ifndef _DX11

#define _DX11

#include "gpu_util/dx11/dx11_util.h"

namespace gpu_util {

    Logger *DX11Util::logger = nullptr;
    DX11DxgiFactoryUtil *DX11Util::dxgiFactoryUtil = nullptr;
    DX11DeviceUtil *DX11Util::dx11DeviceUtil = nullptr;
    DX11DxgiDeviceUtil *DX11Util::dxgiDeviceUtil = nullptr;
    DX11DxgiSwapChainUtil *DX11Util::dxgiSwapChainUtil = nullptr;
    DX11RenderTargetViewUtility *DX11Util::renderTargetViewUtility = nullptr;
	DX11BlobUtil* DX11Util::dx11BlobUtil = nullptr;
	DX11VertexShaderUtil* DX11Util::dx11VertexShaderUtil = nullptr;
	DX11PixelShaderUtil* DX11Util::dx11PixelShaderUtil = nullptr;

} // namespace mars

#endif
