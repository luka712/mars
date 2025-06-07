//
// Created by Luka Erkapic on 11.05.25.
//

#if ALLOW_METAL

#include <string>
#include <stdexcept>
#include "metal/util/metal_converter.h"

namespace mars {
    MetalConverter::MetalConverter(Logger &logger) : logger(logger) {
    }

    MTL::ResourceOptions MetalConverter::convert(const BufferUsage usage) {
        switch (usage) {
            case BufferUsage::Vertex:
            case BufferUsage::Index:
                return MTL::ResourceStorageModePrivate;
            case BufferUsage::Vertex_CopyDst:
                return MTL::ResourceStorageModeShared;
                break;

            default:
                const std::string msg = "MetalConverter::convert: Unsupported buffer usage.";
                logger.error(msg);
                throw std::runtime_error(msg);
        }
    }
}

#endif
