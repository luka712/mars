//
// Created by Erkapic Luka on 1.10.2025.
//

#include "Framework.h"
#include "dx11/buffers/dx11_uniform_buffer.h"
#include "gpu_util/dx11/dx11_util.h"
#include "dx11/util/dx11_converter.h"
#include <sstream>

mars::DX11UniformBuffer::DX11UniformBuffer(
	Framework& framework,
	const std::string& label,
	uint32_t byteSize,
	BufferUsage bufferUsage)
	: AUniformBuffer(framework, label, byteSize, bufferUsage), 
	 renderer(toDX11Renderer(&framework.getRenderer()))
{
	device = renderer->getDevice();
	deviceContext = renderer->getDeviceContext();

	d3d11Usage = DX11Converter::convertBufferUsage(bufferUsage);
	d3d11CpuAccessFlags = D3D11_CPU_ACCESS_WRITE;

	buffer = gpu_util::DX11Util::getBuffer().createConstantBuffer(
		device,
		byteSize,
		d3d11Usage,
		d3d11CpuAccessFlags,
		label);
}

mars::DX11UniformBuffer::DX11UniformBuffer(
	Framework& framework, 
	const void* inputData,
	const std::string& label, 
	uint32_t byteSize,
	BufferUsage bufferUsage)
	: AUniformBuffer(framework, label, byteSize, bufferUsage),
	 renderer(toDX11Renderer(&framework.getRenderer()))
{
	device = renderer->getDevice();
	deviceContext = renderer->getDeviceContext();

	d3d11Usage = DX11Converter::convertBufferUsage(bufferUsage);
	d3d11CpuAccessFlags = 0;
	buffer = gpu_util::DX11Util::getBuffer().createConstantBuffer(
		device,
		byteSize,
		d3d11Usage,
		d3d11CpuAccessFlags,
		label);

	if (inputData != nullptr) 
	{
		update(const_cast<void*>(inputData), byteSize);
	}
}

void mars::DX11UniformBuffer::update(void* data, uint32_t byteSize)
{
	gpu_util::DX11Util::getBuffer()
		.writeUniformBuffer(deviceContext,buffer, data, byteSize);
}

std::string mars::DX11UniformBuffer::printInfo()
{
	std::ostringstream oss;
	oss << "DX11UniformBuffer INFO.\n";
	oss << "\tDX11 DATA:\n";
	oss << "\t\tLabel: " << label << ",\n";
	oss << "\t\tUsage: " << d3d11Usage << "\n";
	oss << "\t\CPU Acess Flags: " << d3d11CpuAccessFlags << "\n";

	oss << "\tFRAMEWORK DATA:\n";
	oss << "\t\tType: UniformBuffer\n";
	// oss << "\t\tFramework Usage: " << std::to_string(bufferUsage) << "\n"; // High level usage from framework.
	oss << "\t\tByte Size: " << byteSize << "\n";;

	logger.info(oss.str());

	return oss.str();
}

void mars::DX11UniformBuffer::destroy()
{
	buffer->Release();
}
