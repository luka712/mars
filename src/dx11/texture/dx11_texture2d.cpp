//
// Created by Erkapic Luka on 11.02.25.
//

#ifdef _WIN32

#include <sstream>
#include "Framework.h"
#include "dx11/texture/dx11_texture2d.h"
#include "gpu_util/dx11/dx11_util.h"

using namespace gpu_util;

namespace mars
{
	DX11Texture2D::DX11Texture2D(Framework& framework, const ImageData& imageData, const std::string& label)
		: framework(framework), logger(framework.getLogger()), renderer(*static_cast<DX11Renderer*>(&framework.getRenderer()))
	{

		device = renderer.getDevice();
		deviceContext = renderer.getDeviceContext();
		d3d11Format = DXGI_FORMAT_R8G8B8A8_UNORM; // Default format
		d3d11Usage = D3D11_USAGE_DEFAULT; // Default usage
		d3d11BindFlags = D3D11_BIND_SHADER_RESOURCE; // Default bind flags

		this->label = label;
		this->width = imageData.getWidth();
		this->height = imageData.getHeight();
		texture = DX11Util::getTexture2D().create(
			device,
			deviceContext,
			imageData.getData(),
			width,
			height,
			d3d11Format,
			d3d11Usage,
			d3d11BindFlags,
			label
		);

		view = DX11Util::getShaderResourceView().createTexure2DView(device, texture, d3d11Format, label);

		samplerState = DX11Util::getSamplerState().createSamplerState(device);
	
	}

	void DX11Texture2D::destroy()
	{
		texture->Release();
	}

	std::string DX11Texture2D::printInfo() {
		std::ostringstream oss;
		oss << "DX11Texture2D INFO.\n";
		oss << "\tFRAMEWORK DATA:\n";
		oss << "\t\tType: Texture2D\n";
		oss << "\t\tLabel: " << label << "\n";
		// oss << "\t\tByte Size: " << byteSize << "\n";
		oss << "\t\tWidth: " << width << "\n";
		oss << "\t\tHeight: " << height << "\n";

		oss << "\tD3D11 DATA:\n";
		oss << "\t\tD3D11 Format: " << d3d11Format << "\n";
		oss << "\t\tD3D11 Usage: " << d3d11Usage << "\n";
		oss << "\t\tD3D11 Bind Flags: " << d3d11BindFlags << "\n";

		logger.info(oss.str());

		return oss.str();
	}

	DX11Texture2D* toDX11Texture2D(ATexture2D* texture) {
		return dynamic_cast<DX11Texture2D*>(texture);
	}

}


#endif 
