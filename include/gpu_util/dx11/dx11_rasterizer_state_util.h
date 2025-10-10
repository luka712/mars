#if _WIN32

#ifndef DX11_RASTERIZER_STATE_UTIL_H
#define DX11_RASTERIZER_STATE_UTIL_H

#include "gpu_util/dx11.h"
#include "gpu_util/logger.h"

using namespace Microsoft::WRL;

namespace gpu_util {

	//! The utility class for working with DirectX 11 rasterizer states.
	class DX11RasterizerStateUtil {

	public:

		//! Construct a new DX11RasterizerStateUtil object.
		//! @param logger The logger.
		explicit DX11RasterizerStateUtil(Logger& logger) : logger(logger) {
		}

		//! Creates a rasterizer state with the specified parameters.
		//! @param device The Direct3D 11 device.
		//! @param fillMode The fill mode (default is D3D11_FILL_SOLID).
		//! @param cullMode The cull mode (default is D3D11_CULL_BACK).
		//! @param frontCounterClockwise Specifies whether front-facing triangles are counter-clockwise (default is TRUE).
		//! @param depthBias The depth bias (default is 0).
		//! @param depthBiasClamp The depth bias clamp (default is 0.0f).
		//! @param slopeScaledDepthBias The slope-scaled depth bias (default is 0.0f).
		//! @param depthClipEnable Specifies whether depth clipping is enabled (default is TRUE).
		//! @param scissorEnable Specifies whether scissor testing is enabled (default is FALSE).
		//! @param multisampleEnable Specifies whether multisampling is enabled (default is FALSE).
		//! @param antialiasedLineEnable Specifies whether antialiased lines are enabled (default is FALSE).
		ComPtr<ID3D11RasterizerState> createRasterizerState(
			ComPtr<ID3D11Device>& device,
			D3D11_FILL_MODE fillMode = D3D11_FILL_SOLID,
			D3D11_CULL_MODE cullMode = D3D11_CULL_BACK,
			BOOL frontCounterClockwise = TRUE,
			INT depthBias = 0,
			FLOAT depthBiasClamp = 0.0f,
			FLOAT slopeScaledDepthBias = 0.0f,
			BOOL depthClipEnable = TRUE,
			BOOL scissorEnable = FALSE,
			BOOL multisampleEnable = FALSE,
			BOOL antialiasedLineEnable = FALSE,
			const std::string& label = ""
		);

	private:
		Logger& logger; // Logger for logging messages

	};
}
#endif //DX11_RASTERIZER_STATE_UTIL_H

#endif