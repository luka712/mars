//
// Created by Luka Erkapic on 11.05.25.
//

#if _WIN32

#include <sstream>
#include "Framework.h"
#include "dx11/buffers/dx11_vertex_buffer.h"
#include "gpu_util/dx11/dx11_util.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/util/dx11_converter.h"

namespace mars {
    DX11VertexBuffer::DX11VertexBuffer(const Framework &framework, const std::string &label): AVertexBuffer(label),
        renderer(dynamic_cast<DX11Renderer&>(framework.getRenderer())),
        logger(framework.getLogger()), usage(BufferUsage::Vertex), buffer() {

		device = renderer.getDevice();
    }

    void DX11VertexBuffer::initialize(
        const void *data,
        const uint32_t byteSize,
		const uint32_t byteStride,
        const uint32_t vertexCount,
        const BufferUsage usage)
    {
        device = renderer.getDevice();

		D3D11_USAGE d3d11BufferUsage = DX11Converter::convertBufferUsage(usage);
		UINT d3d11BindFlags = DX11Converter::convertToBindFlags(usage);
        UINT d3d11MiscFlags = DX11Converter::convertToResourceMiscFlags(usage);

        buffer = gpu_util::DX11Util::getBuffer().create(
            device, 
            data, 
            byteSize,
            byteStride,
            d3d11BufferUsage, 
            d3d11BindFlags,
			0, // CPU access flags, not needed for vertex buffers
            d3d11MiscFlags,
            label);
    }

    void DX11VertexBuffer::initialize(
        const uint32_t byteSize, 
		const uint32_t byteStride,
        const uint32_t vertexCount) {
        device = renderer.getDevice();

    }

    void DX11VertexBuffer::update(void *data, uint32_t byteSize, uint32_t offset) {

    }

    std::string DX11VertexBuffer::printInfo() {
        std::string optionsStr;
       /* switch (options) {
            case MTL::ResourceStorageModeShared:
                optionsStr = "ResourceStorageModeShared";
                break;
            case MTL::ResourceStorageModePrivate:
                optionsStr = "ResourceStorageModePrivate";
                break;
            default:
                throw std::runtime_error("Unknown buffer hint.");
        }*/


        std::ostringstream oss;
        oss << "DX11VertexBuffer INFO.\n";
        oss << "\tMetal DATA:\n";
        oss << "\t\tLabel: " << label << ",\n";
        oss << "\t\tOptions: " << optionsStr << "\n";

        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: VertexBuffer\n";
        //  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
        oss << "\t\tVertex Count: " << vertexCount << "\n";
        oss << "\t\tByte Size: " << byteSize << "\n";
        oss << "\t\tByte Stride: " << byteStride << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    void DX11VertexBuffer::destroy() {
        buffer->Release();
    }

    DX11VertexBuffer *toDX11VertexBuffer(AVertexBuffer *vertexBuffer) {
        return dynamic_cast<DX11VertexBuffer *>(vertexBuffer);
    }
}

#endif
