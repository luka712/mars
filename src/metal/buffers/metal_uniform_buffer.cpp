//
// Created by Luka Erkapic on 18.05.25.
//

#if ALLOW_METAL

#include "metal/buffers/metal_uniform_buffer.h"
#include "metal/util/metal_util.h"
#include <sstream>

namespace mars {
    MetalUniformBuffer::MetalUniformBuffer(Framework &framework, const std::string &label, uint32_t byteSize,
                                           const BufferUsage bufferUsage)
        : AUniformBuffer(framework, label, byteSize, bufferUsage),
          renderer(dynamic_cast<MetalRenderer &>(framework.getRenderer())),
          logger(framework.getLogger()) {
    }

    MetalUniformBuffer::MetalUniformBuffer(Framework &framework, const void *inputData, const std::string &label,
                                           uint32_t byteSize,
                                           BufferUsage bufferUsage)
        : AUniformBuffer(framework, label, byteSize, bufferUsage),
          renderer(dynamic_cast<MetalRenderer &>(framework.getRenderer())),
          logger(framework.getLogger()) {
    }

    void MetalUniformBuffer::update(void *data, uint32_t byteSize) {

        if (options == MTL::StorageModeShared) {
            MetalUtil::getBufferUtil().updateSharedBuffer(buffer, data, byteSize);
        }
        else {
            const std::string msg = "MetalUniformBuffer::update: Unable to update buffer. Update not implemented.";
            logger.error(msg);
            throw std::runtime_error(msg);
        }
    }

    //! @inheritDoc
    std::string MetalUniformBuffer::printInfo() {
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
        oss << "MetalUniformBuffer INFO.\n";
        oss << "\tMetal DATA:\n";
        oss << "\t\tLabel: " << label << ",\n";
        oss << "\t\tOptions: " << optionsStr << "\n";

        oss << "\tFRAMEWORK DATA:\n";
        oss << "\t\tType: UniformBuffer\n";
        //  oss << "\t\tFramework Usage: " << usage << "\n"; // High level usage from framework.
        oss << "\t\tByte Size: " << byteSize << "\n";

        logger.info(oss.str());

        return oss.str();
    }

    //! @inheritDoc
    void MetalUniformBuffer::destroy() {
        buffer->release();
    }
}

#endif
