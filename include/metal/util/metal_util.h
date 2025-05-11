//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_UTIL_H
#define METAL_UTIL_H

#include "metal/util/metal_buffer_util.h"
#include "metal/util/metal_converter.h"

namespace mars {
    static MetalConverter *metalConverter = nullptr;
    static MetalBufferUtil *metalBufferUtil = nullptr;

    class MetalUtil {
    public:
        //! Initialize the MetalUtil.
        //! @param logger The logger.
        static void initialize(Logger &logger) {
            metalConverter = new MetalConverter(logger);
            metalBufferUtil = new MetalBufferUtil(logger);
        }

        //! Gets the MetalConverter. Used to convert framework formats to Metal formats.
        //! @return The MetalConverter pointer.
        static MetalConverter &getMetalConverter() { return *metalConverter; }

        //! Gets the MetalBufferUtil for working with buffers.
        //! @return The MetalBufferUtil ptr.
        static MetalBufferUtil &getBufferUtil() { return *metalBufferUtil; }
    };
}

#endif //METAL_UTIL_H
