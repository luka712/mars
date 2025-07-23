//
// Created by Erkapic Luka on 23.7.2025.
//

#ifdef _WIN32

#include <sstream>
#include "Framework.h"
#include "dx11/buffers/dx11_index_buffer.h"
#include "gpu_util/dx11/dx11_util.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/util/dx11_converter.h"

namespace mars {

	DX11IndexBuffer::DX11IndexBuffer(const Framework& framework, const std::string& label) : AIndexBuffer(label),
		renderer(dynamic_cast<DX11Renderer&>(framework.getRenderer())),
		logger(framework.getLogger()), buffer() {
		device = renderer.getDevice();
	}

	void DX11IndexBuffer::initialize(const std::vector<uint16_t>& data)
	{
		buffer = gpu_util::DX11Util::getBuffer().createIndexBuffer(device, data, label);
		indicesCount = static_cast<uint32_t>(data.size());
		type = IndexBufferType::Uint16; // Assuming uint16_t for this case.
	}

	void DX11IndexBuffer::initialize(const std::vector<uint32_t>& data)
	{
		buffer = gpu_util::DX11Util::getBuffer().createIndexBuffer(device, data, label);
		indicesCount = static_cast<uint32_t>(data.size());
		type = IndexBufferType::Uint32; // Assuming uint32_t for this case.
	}

	std::string DX11IndexBuffer::printInfo() {
		std::ostringstream oss;
		oss << "DX11IndexBuffer INFO.\n";
		oss << "\tDX11 DATA:\n";
		oss << "\t\tLabel: " << label << ",\n";
		oss << "\t\tTarget: GL_ELEMENT_ARRAY_BUFFER\n";
		oss << "\t\tHint: GL_STATIC_DRAW\n";

		oss << "\tFRAMEWORK DATA:\n";
		oss << "\t\tType: IndexBuffer\n";
		//  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
		oss << "\t\tIndices Count: " << indicesCount << "\n";
		oss << "\t\tByte Size: " << byteSize << "\n";
		oss << "\t\tElement Size: " << getElementByteSize() << "\n";

		logger.info(oss.str());

		return oss.str();
	}

	void DX11IndexBuffer::destroy() {
		buffer->Release();
	}

	DX11IndexBuffer* toDX11IndexBuffer(AIndexBuffer* vertexBuffer) {
		return dynamic_cast<DX11IndexBuffer*>(vertexBuffer);
	}

}

#endif
