//
// Created by Luka Erkapic on 11.05.25.
//

#if __APPLE__

#include <sstream>
#include "metal/buffers/metal_index_buffer.h"
#include "metal/renderer/metal_renderer.h"
#include <gpu_util/metal/metal_util.h>

namespace mars {

    MetalIndexBuffer::MetalIndexBuffer(const Framework &framework, const std::string &label)
        : AIndexBuffer(label), renderer(dynamic_cast<MetalRenderer &>(framework.getRenderer())), logger(framework.getLogger()),
          usage(), options(MTL::ResourceStorageModePrivate) {
              device = renderer.getDevice();
    }

    void MetalIndexBuffer::initialize(const std::vector<uint16_t>& data) {
        byteSize = data.size() * sizeof(uint16_t);
        indicesCount = data.size();
        buffer = gpu_util::MetalUtil::getBuffer()
            .create(device,data.data(),byteSize);
    }

    void  MetalIndexBuffer::initialize(const std::vector<uint32_t>& data) {
        byteSize = data.size() * sizeof(uint32_t);
        indicesCount = data.size();
        buffer = gpu_util::MetalUtil::getBuffer()
            .create( device, data.data(),byteSize);
    }

    std::string  MetalIndexBuffer::printInfo() {
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
        oss << "MetalIndexBuffer INFO.\n";
        oss << "\tMetal DATA:\n";
        oss << "\t\tLabel: " << label << ",\n";
        oss << "\t\tOptions: " << optionsStr << "\n";

        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: IndexBuffer\n";
        //  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
        oss << "\t\tByte Size: " << byteSize << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    void  MetalIndexBuffer::destroy() {
        buffer->release();
    }

    MetalIndexBuffer* toMetalIndexBuffer(AIndexBuffer* indexBuffer) {
        return dynamic_cast<MetalIndexBuffer *>(indexBuffer);

    }
}



#endif
