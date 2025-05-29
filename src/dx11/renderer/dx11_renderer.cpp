//
// Created by Erkapic Luka on 27.5.2025.
//

#if ALLOW_DX11

#include "Framework.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/util/dx11_util.h"

// Link automatically if using MSVC and CMake is configured right
#pragma comment(lib, "d3d11.lib")
#pragma comment(lib, "dxgi.lib")
#pragma comment(lib, "d3dcompiler.lib")

namespace mars {
 static Logger *staticLogger = nullptr;


    DX11Renderer::DX11Renderer(Framework &framework, const glm::vec2 frameBufferSize)
        : Renderer(framework), window(nullptr), device(nullptr), deviceContext(nullptr),
          dxgiFactory(nullptr), swapChain(nullptr) {
        this->frameBufferSize = frameBufferSize;
    }

    void DX11Renderer::initialize() {

        window = framework.getWindowManager().getWindow();
        Logger &logger = framework.getLogger();
        staticLogger = &logger;

        DX11Util::initialize(*staticLogger);

        dxgiFactory = DX11Util::getDxgiFactory().create();
		dxgiDevice = DX11Util::getDxgiDevice().create();

        auto result = DX11Util::getDevice().createDeviceAndDeviceContext();
        device = std::get<0>(result);
        deviceContext = std::get<1>(result);

        std::string deviceName = DX11Util::getDevice().getDeviceName(device);
        logger.info("DX11Renderer::initialize: Created DirectX 11 device: " + deviceName);
    }

    void DX11Renderer::setupNewRenderPass() {


    }


    void DX11Renderer::beginRenderPass() {

        setupNewRenderPass();
    }

    void DX11Renderer::endRenderPass() {

    }

    void DX11Renderer::destroy() {
    }

    DX11Renderer& toDX11Renderer(Renderer& renderer) {
        return *dynamic_cast<DX11Renderer*>(&renderer);
    }
}

#endif