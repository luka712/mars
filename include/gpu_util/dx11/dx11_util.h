#ifndef DX11_UTIL_H
#define DX11_UTIL_H

#ifdef _WIN32

#include "gpu_util/logger.h"
#include "gpu_util/dx11/dx11_dxgi_factory_util.h"
#include "gpu_util/dx11/dx11_device_util.h"
#include "gpu_util/dx11/dx11_dxgi_device_util.h"
#include "gpu_util/dx11/dx11_dxgi_swap_chain_util.h"
#include "gpu_util/dx11/dx11_render_target_view_utility.h"
#include "gpu_util/dx11/dx11_blob_util.h"
#include "gpu_util/dx11/dx11_vertex_shader_util.h"
#include "gpu_util/dx11/dx11_pixel_shader_util.h"
#include "gpu_util/dx11/dx11_input_layout_util.h"
#include "gpu_util/dx11/dx11_buffer_util.h"
#include "gpu_util/dx11/dx11_texture2d_util.h"
#include "gpu_util/dx11/dx11_shader_resource_view_util.h"
#include "gpu_util/dx11/dx11_sampler_state_util.h"
#include "gpu_util/dx11/dx11_blend_state_util.h"
#include "gpu_util/dx11/dx11_rasterizer_state_util.h"

namespace gpu_util {

	//! The utility class for working with DirectX 11.
	class DX11Util {
	public:
		//! Initialize the MetalUtil.
		//! @param logger The logger.
		static void initialize(Logger& logger) {
			dxgiFactoryUtil = new DX11DxgiFactoryUtil(logger);
			dxgiDeviceUtil = new DX11DxgiDeviceUtil(logger);
			dx11DeviceUtil = new DX11DeviceUtil(logger);
			dxgiSwapChainUtil = new DX11DxgiSwapChainUtil(logger);
			renderTargetViewUtility = new DX11RenderTargetViewUtility(logger);
			dx11BlobUtil = new DX11BlobUtil(logger);
			dx11VertexShaderUtil = new DX11VertexShaderUtil(logger);
			dx11PixelShaderUtil = new DX11PixelShaderUtil(logger);
			dx11InputLayoutUtil = new DX11InputLayoutUtil(logger);
			dx11BufferUtil = new DX11BufferUtil(logger);
			dx11Texture2DUtil = new DX11Texture2DUtil(logger);
			dx11ShaderResourceViewUtil = new DX11ShaderResourceViewUtil(logger);
			dx11SamplerStateUtil = new DX11SamplerStateUtil(logger);
			dx11BlendStateUtil = new DX11BlendStateUtil(logger);
			dx11RasterizerStateUtil = new DX11RasterizerStateUtil(logger);
		}

		//! Initialize the MetalUtil.
		//! @param withDefaultLogger If <code>true</code>,  creates default logger.
		static void initialize(bool withDefaultLogger) {

			if (DX11Util::logger != nullptr) {
				delete DX11Util::logger;
			}

			if (withDefaultLogger) {
				DX11Util::logger = new SpdLogger();
			}
			else {
				DX11Util::logger = new MockLogger();
			}
			DX11Util::initialize(*logger);
		}

		//! Gets the DX11BlobUtil for working with DirectX 11 blobs.
		//! @return The DX11BlobUtil ptr.
		static DX11BlobUtil& getBlob() { return *dx11BlobUtil; }

		//! Gets the DX11VertexShaderUtil for working with DirectX 11 vertex shaders.
		//! @return The DX11VertexShaderUtil ptr.
		static DX11VertexShaderUtil& getVertexShader() { return *dx11VertexShaderUtil; }

		//! Gets the DX11PixelShaderUtil for working with DirectX 11 pixel shaders.
		//! @return The DX11PixelShaderUtil ptr.
		static DX11PixelShaderUtil& getPixelShader() { return *dx11PixelShaderUtil; }

		//! Gets the DXGIFactoryUtil. Used to create DXGI factories.
		//! @return The DXGIFactoryUtil pointer.
		static DX11DxgiFactoryUtil& getDxgiFactory() { return *dxgiFactoryUtil; }

		//! Gets the DXGIDeviceUtil. Used to create DXGI devices.
		//! @return The DXGIDeviceUtil.
		static DX11DxgiDeviceUtil& getDxgiDevice() { return *dxgiDeviceUtil; }

		//! Gets the DX11DeviceUtil for working with DirectX 11 devices.
		//! @return The DX11DeviceUtil.
		static DX11DeviceUtil& getDevice() { return *dx11DeviceUtil; }

		// Gets the DX11DxgiSwapChainUtil for working with DirectX 11 swap chains.
		//! @return The DX11DxgiSwapChainUtil.
		static DX11DxgiSwapChainUtil& getDxgiSwapChain() { return *dxgiSwapChainUtil; }

		// Gets the DX11RenderTargetViewUtility for working with DirectX 11 render target views.
		//! @return The DX11RenderTargetViewUtility.
		static DX11RenderTargetViewUtility& getRenderTargetView() { return *renderTargetViewUtility; }

		//! Gets the DX11InputLayoutUtil for working with DirectX 11 input layouts.
		//! @return The DX11InputLayoutUtil.
		static DX11InputLayoutUtil& getInputLayout() { return *dx11InputLayoutUtil; }

		//! Gets the DX11BufferUtil for working with DirectX 11 buffers.
		//! @return The DX11BufferUtil.
		static DX11BufferUtil& getBuffer() { return *dx11BufferUtil; }

		//! Gets the DX11Texture2DUtility for working with DirectX 11 textures.
		//! @return The DX11Texture2DUtility.
		static DX11Texture2DUtil& getTexture2D() { return *dx11Texture2DUtil; }

		//! Gets the DX11ShaderResourceViewUtil for working with DirectX 11 shader resource views.
		//! @return The DX11ShaderResourceViewUtil.
		static DX11ShaderResourceViewUtil& getShaderResourceView() { return *dx11ShaderResourceViewUtil; }

		//! Gets the DX11SamplerStateUtil for working with DirectX 11 sampler states.
	  //! @return The DX11SamplerStateUtil.
		static DX11SamplerStateUtil& getSamplerState() { return *dx11SamplerStateUtil; }

		//! Gets the DX11BlendStateUtil for working with DirectX 11 blend states.
		//! @return The DX11BlendStateUtil.
		static DX11BlendStateUtil& getBlendState() { return *dx11BlendStateUtil; }

		//! Gets the DX11RasterizerStateUtil for working with DirectX 11 rasterizer states.
		//! @return The DX11RasterizerStateUtil.
		static DX11RasterizerStateUtil& getRasterizerState() { return *dx11RasterizerStateUtil; }

	private:
		static Logger* logger;
		static DX11DxgiFactoryUtil* dxgiFactoryUtil;
		static DX11DeviceUtil* dx11DeviceUtil;
		static DX11DxgiDeviceUtil* dxgiDeviceUtil;
		static DX11DxgiSwapChainUtil* dxgiSwapChainUtil;
		static DX11RenderTargetViewUtility* renderTargetViewUtility;
		static DX11BlobUtil* dx11BlobUtil;
		static DX11VertexShaderUtil* dx11VertexShaderUtil;
		static DX11PixelShaderUtil* dx11PixelShaderUtil;
		static DX11InputLayoutUtil* dx11InputLayoutUtil;
		static DX11BufferUtil* dx11BufferUtil;
		static DX11Texture2DUtil* dx11Texture2DUtil;
		static DX11ShaderResourceViewUtil* dx11ShaderResourceViewUtil;
		static DX11SamplerStateUtil* dx11SamplerStateUtil;
		static DX11BlendStateUtil* dx11BlendStateUtil;
		static DX11RasterizerStateUtil* dx11RasterizerStateUtil;
	};
}

#endif

#endif //DX11_UTIL_H
