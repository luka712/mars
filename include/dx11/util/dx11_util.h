//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DX11_UTIL_H
#define DX11_UTIL_H

#ifdef _WIN32

#include "gpu_util/logger.h"
#include "dx11/util/dx11_dxgi_factory_util.h"
#include "dx11/util/dx11_device_util.h"
#include "dx11/util/dx11_dxgi_device_util.h"
#include "dx11/util/dx11_dxgi_swap_chain_util.h"
#include "dx11/util/dx11_render_target_view_utility.h"
#include "gpu_util/dx11/dx11_blob_util.h"
#include "gpu_util/dx11/dx11_vertex_shader_util.h"
#include "gpu_util/dx11/dx11_pixel_shader_util.h"

namespace mars {


    class DX11Util {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            dxgiFactoryUtil = new DX11DxgiFactoryUtil(logger);
            dxgiDeviceUtil = new DX11DxgiDeviceUtil(logger);
            dx11DeviceUtil = new DX11DeviceUtil(logger);
            dxgiSwapChainUtil = new DX11DxgiSwapChainUtil(logger);
            renderTargetViewUtility = new DX11RenderTargetViewUtility(logger);

            // TODO: remove this logger when refactored.
            gpu_util::Logger* sdpLogger = new gpu_util::SpdLogger();
			dx11BlobUtil = new gpu_util::DX11BlobUtil(*sdpLogger);
			dx11VertexShaderUtil = new gpu_util::DX11VertexShaderUtil(*sdpLogger);
			dx11PixelShaderUtil = new gpu_util::DX11PixelShaderUtil(*sdpLogger);
        }

		//! Gets the DX11BlobUtil for working with DirectX 11 blobs.
		//! @return The DX11BlobUtil ptr.
		static gpu_util::DX11BlobUtil& getBlob() { return *dx11BlobUtil; }

		//! Gets the DX11VertexShaderUtil for working with DirectX 11 vertex shaders.
		//! @return The DX11VertexShaderUtil ptr.
		static gpu_util::DX11VertexShaderUtil& getVertexShader() { return *dx11VertexShaderUtil; }

		//! Gets the DX11PixelShaderUtil for working with DirectX 11 pixel shaders.
		//! @return The DX11PixelShaderUtil ptr.
		static gpu_util::DX11PixelShaderUtil& getPixelShader() { return *dx11PixelShaderUtil; }

        //! Gets the DXGIFactoryUtil. Used to create DXGI factories.
        //! @return The DXGIFactoryUtil pointer.
        static DX11DxgiFactoryUtil &getDxgiFactory() { return *dxgiFactoryUtil; }

        //! Gets the DXGIDeviceUtil. Used to create DXGI devices.
        //! @return The DXGIDeviceUtil pointer.
        static DX11DxgiDeviceUtil &getDxgiDevice() { return *dxgiDeviceUtil; }

        //! Gets the DX11DeviceUtil for working with DirectX 11 devices.
        //! @return The DX11DeviceUtil ptr.
        static DX11DeviceUtil &getDevice() { return *dx11DeviceUtil; }

        // Gets the DX11DxgiSwapChainUtil for working with DirectX 11 swap chains.
        //! @return The DX11DxgiSwapChainUtil ptr.
        static DX11DxgiSwapChainUtil &getDxgiSwapChain() { return *dxgiSwapChainUtil; }

        // Gets the DX11RenderTargetViewUtility for working with DirectX 11 render target views.
        //! @return The DX11RenderTargetViewUtility ptr.
        static DX11RenderTargetViewUtility &getRenderTargetView() {return *renderTargetViewUtility;}

    private:
        static DX11DxgiFactoryUtil* dxgiFactoryUtil;
        static DX11DeviceUtil* dx11DeviceUtil;
        static DX11DxgiDeviceUtil* dxgiDeviceUtil;
        static DX11DxgiSwapChainUtil* dxgiSwapChainUtil;
        static DX11RenderTargetViewUtility* renderTargetViewUtility;
		static gpu_util::DX11BlobUtil* dx11BlobUtil;
		static gpu_util::DX11VertexShaderUtil* dx11VertexShaderUtil;
		static gpu_util::DX11PixelShaderUtil* dx11PixelShaderUtil;
};
}

#endif

#endif //DX11_UTIL_H
