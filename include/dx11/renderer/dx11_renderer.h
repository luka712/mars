//
// Created by Erkapic Luka on 27.5.2025.
//

#ifndef DX11_RENDERER_H
#define DX11_RENDERER_H

#if ALLOW_DX11

#include "dx11/dx11.h"
#include "core/renderer/Renderer.h"

namespace mars {
    class Framework;

    class DX11Renderer final : public Renderer {
    public:
        //! Construct a new DX11Renderer object.
        //! @param framework The framework.
        //! @param frameBufferSize The frame buffer size.
        explicit DX11Renderer(Framework &framework, glm::vec2 frameBufferSize);

        //! Gets the DX11 device.
        //! @return The ID3D11Device pointer.
        [[nodiscard]] const Microsoft::WRL::ComPtr<ID3D11Device> &getDevice() const {
            return device;
        }

        //! Gets the DX11 device context.
        //! @return The ID3D11DeviceContext pointer.
        [[nodiscard]] const Microsoft::WRL::ComPtr<ID3D11DeviceContext> &getDeviceContext() const {
            return deviceContext;
        }

        //! @copydoc Renderer::initialize()
        void initialize() override;

        //! @copydoc Renderer::beginRenderPass()
        void beginRenderPass() override;

        //! @copydoc Renderer::endRenderPass()
        void endRenderPass() override;

        //! @copydoc Renderer::destroy()
        void destroy() override;

    private:
        SDL_Window *window;

        //! The factory for the DXGI objects, such as swap chains.
        Microsoft::WRL::ComPtr<IDXGIFactory1> dxgiFactory;

        //! Swap chain for the window.
        Microsoft::WRL::ComPtr<IDXGISwapChain> swapChain;

        //! The device
        Microsoft::WRL::ComPtr<ID3D11Device> device;

        //! The device context
        Microsoft::WRL::ComPtr<ID3D11DeviceContext> deviceContext;

        void createDevice();

        //! Create a new render pass.
        void setupNewRenderPass();
    };

    //! Convert the renderer to the DX11 renderer.
    //! @param renderer The renderer.
    //! @return The DX11Renderer.
    static DX11Renderer &toDX11Renderer(Renderer &renderer);
}

#endif

#endif //D3D11_RENDERER_H
