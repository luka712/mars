//
// Created by Erkapic Luka on 27.5.2025.
//

#ifdef _WIN32

#include "Framework.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/util/dx11_util.h"
#include <SDL2/SDL.h>
#include <SDL2/SDL_syswm.h>

// Link automatically if using MSVC and CMake is configured right
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace mars {
	static Logger* staticLogger = nullptr;

	DX11Renderer::DX11Renderer(Framework& framework, const glm::vec2 frameBufferSize)
		: Renderer(framework), device(nullptr), deviceContext(nullptr),
		dxgiFactory(nullptr), swapChain(nullptr) {
		this->frameBufferSize = frameBufferSize;
	}

	void DX11Renderer::initialize() {
		Logger& logger = framework.getLogger();
		staticLogger = &logger;

		DX11Util::initialize(*staticLogger);

		dxgiFactory = DX11Util::getDxgiFactory().create();

		createDevice();
		createSwapChain();
	}

	void DX11Renderer::createDevice()
	{
		Logger& logger = framework.getLogger();

		const auto result = DX11Util::getDevice().createDeviceAndDeviceContext();
		device = std::get<0>(result);
		deviceContext = std::get<1>(result);

		dxgiDevice = DX11Util::getDxgiDevice().create(device);

		std::string deviceName = DX11Util::getDevice().getDeviceName(dxgiDevice, device);
		logger.info("DX11Renderer::initialize: Created DirectX 11 device: " + deviceName);
	}

	void DX11Renderer::createSwapChain()
	{
		Logger& logger = framework.getLogger();

		HWND hwnd = framework.getWindowManager().getWin32Handle();

		swapChain = DX11Util::getDxgiSwapChain().create(
			dxgiFactory, device, hwnd, DXGI_FORMAT_R8G8B8A8_UNORM, 2, DXGI_SWAP_EFFECT_FLIP_SEQUENTIAL);

		swapChainBackBuffer = DX11Util::getDxgiSwapChain().getBackBuffer(swapChain);
		swapChainRenderTargetView = DX11Util::getRenderTargetView().createRenderTargetView(
			device, swapChainBackBuffer, DXGI_FORMAT_R8G8B8A8_UNORM);


		logger.info("DX11Renderer::initialize: Swap chain created successfully.");
	}

	void DX11Renderer::setupNewRenderPass() {
	}


	void DX11Renderer::beginRenderPass() {
		setupNewRenderPass();

		// - CLEAR COLOR 
		const float clear_color[4] = { clearColor.r, clearColor.g, clearColor.b, clearColor.a }; // RGBA
		deviceContext->ClearRenderTargetView(
			swapChainRenderTargetView.Get(),
			clear_color);

		// - VIEWPORT 
		const CD3D11_VIEWPORT viewport(0.0f, 0.0f, frameBufferSize.x, frameBufferSize.y);
		deviceContext->RSSetViewports(1, &viewport);

		// - RENDER TARGET
		ID3D11RenderTargetView* renderTargets[] = {
			swapChainRenderTargetView.Get()
		};
		deviceContext->OMSetRenderTargets(1, renderTargets, nullptr);
	}

	void DX11Renderer::endRenderPass() {

		swapChain->Present(1, 0); // Present the swap chain with vsync enabled
	}

	void DX11Renderer::destroy() {
	}

	DX11Renderer& toDX11Renderer(Renderer& renderer) {
		return *dynamic_cast<DX11Renderer*>(&renderer);
	}
}

#endif
