//
// Created by lukaa on 9.8.2025..
//

#ifndef DX11_SAMPLER_STATE_UTIL_H
#define DX11_SAMPLER_STATE_UTIL_H

#include <dx11/dx11.h>
#include <gpu_util/logger.h>

using namespace Microsoft::WRL;

namespace gpu_util {

	//! Utility class for creating DirectX 11 sampler states.
	class DX11SamplerStateUtil
	{
	public:
		//! Construct a new DX11Sampler object.
		 //! @param logger The logger.
		explicit DX11SamplerStateUtil(Logger& logger) : logger(logger) {}


		//! Creates a sampler state with the specified parameters.
		//! @param device The DirectX 11 device.
		//! @param filter The filter mode for the sampler state (default is D3D11_FILTER_MIN_MAG_MIP_LINEAR).
		//! @param addressU The addressing mode in the U direction (default is D3D11_TEXTURE_ADDRESS_WRAP).
		//! @param addressV The addressing mode in the V direction (default is D3D11_TEXTURE_ADDRESS_WRAP).
		//! @param addressW The addressing mode in the W direction (default is D3D11_TEXTURE_ADDRESS_WRAP).
        //! @param label Optional label for debugging purposes.
		//! @return The created sampler state.
		ComPtr<ID3D11SamplerState> createSamplerState(
			ComPtr<ID3D11Device> device,
			D3D11_FILTER filter = D3D11_FILTER_MIN_MAG_MIP_LINEAR,
			D3D11_TEXTURE_ADDRESS_MODE addressU = D3D11_TEXTURE_ADDRESS_WRAP,
			D3D11_TEXTURE_ADDRESS_MODE addressV = D3D11_TEXTURE_ADDRESS_WRAP,
			D3D11_TEXTURE_ADDRESS_MODE addressW = D3D11_TEXTURE_ADDRESS_WRAP,
                    			const std::string& label = ""
		);

	private:
		Logger& logger;

	};
}
#endif //DX11_SAMPLER_STATE_UTIL_H
