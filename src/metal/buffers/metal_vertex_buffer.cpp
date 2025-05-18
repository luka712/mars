//
// Created by Luka Erkapic on 11.05.25.
//

#if __APPLE__

#include <sstream>
#include "Framework.h"
#include "metal/buffers/metal_vertex_buffer.h"
#include "metal/util/metal_util.h"
#include "metal/renderer/metal_renderer.h"

namespace mars {
    MetalVertexBuffer::MetalVertexBuffer(const Framework &framework, const std::string &label): AVertexBuffer(label),
        renderer(dynamic_cast<MetalRenderer&>(framework.getRenderer())),
        logger(framework.getLogger()), usage(BufferUsage::Vertex), buffer() {
    }

    void MetalVertexBuffer::initialize(
        const void *data,
        const uint32_t byteSize,
        uint32_t vertexCount,
        const BufferUsage usage)
    {
        device = renderer.getDevice();
        queue = renderer.getQueue();

        options = MetalUtil::getMetalConverter().convert(usage);
        buffer = MetalUtil::getBufferUtil().create(device, queue, data, byteSize, label, options);
    }

    void MetalVertexBuffer::initialize(uint32_t byteSize, uint32_t vertexCount) {
        device = renderer.getDevice();

    }

    void MetalVertexBuffer::update(void *data, uint32_t byteSize, uint32_t offset) {

    }

    std::string MetalVertexBuffer::printInfo() {
        std::string optionsStr;
        switch (options) {
            case MTL::ResourceStorageModeShared:
                optionsStr = "ResourceStorageModeShared";
                break;
            case MTL::ResourceStorageModePrivate:
                optionsStr = "ResourceStorageModePrivate";
                break;
            default:
                throw std::runtime_error("Unknown buffer hint.");
        }


        std::ostringstream oss;
        oss << "MetalVertexBuffer INFO.\n";
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

    void MetalVertexBuffer::destroy() {
        buffer->release();
    }

    MetalVertexBuffer *toMetalVertexBuffer(AVertexBuffer *vertexBuffer) {
        return dynamic_cast<MetalVertexBuffer *>(vertexBuffer);
    }
}

#endif