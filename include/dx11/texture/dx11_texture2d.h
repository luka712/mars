//
// Created by Erkapic Luka on 9.8.2025.
//

#ifdef _WIN32

#ifndef DX11_TEXTURE2D_H
#define DX11_TEXTURE2D_H

#include "dx11/dx11.h"
#include "dx11/renderer/dx11_renderer.h"
#include "core/texture/a_texture2d.h"

namespace mars {

	class Framework;

	//! The D3D11 implementation of the Texture2D.
	class DX11Texture2D : public ATexture2D {
	public:
		//! Construct a new DX11Texture2D object.
		//! @param framework The framework.
		//! @param imageData The image data.
		//! @param label The label.
		DX11Texture2D(Framework& framework,
			const ImageData& imageData,
			const std::string& label = "");

		//! Get the texture.
		//! @return The D3D11 texture.
		[[nodiscard]] ComPtr<ID3D11Texture2D> getTexture() const { return texture; }

		//! Gets the view.
		//! @return The D3D11 shader resource view.
		[[nodiscard]] ComPtr<ID3D11ShaderResourceView> getView() const { return view; }

		//! Gets the sampler state.
		//! @return The D3D11 sampler state.
		[[nodiscard]] ComPtr<ID3D11SamplerState> getSamplerState() const { return samplerState; }

		//! @inheritDoc
		void destroy() override;

		//! @inheritDoc
		std::string printInfo() override;
	private:
		Framework& framework;
		Logger& logger;

		DX11Renderer& renderer;

		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> deviceContext;

		//! The D3D11 texture.
		ComPtr<ID3D11Texture2D> texture;

		//! The D3D11 shader resource view.
		ComPtr<ID3D11ShaderResourceView> view;

		//! The sampler state.
		ComPtr<ID3D11SamplerState> samplerState;

		//! Format of the texture.
		DXGI_FORMAT d3d11Format;

		//! The usage of the texture.
		D3D11_USAGE d3d11Usage;

		//! The bind flags for the texture.
		UINT d3d11BindFlags;
	};

	//! Converts the @ref Texture2D to the @ref DX11Texture2D
	//! @param texture The @ref Texture2D
	//! @returns The DX11Texture2D.
	DX11Texture2D* toDX11Texture2D(ATexture2D* texture);
}
#endif //DX11_TEXTURE2D_H

#endif //DX11_TEXTURE2D_H