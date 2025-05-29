//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_CONVERTER_H
#define METAL_CONVERTER_H

#if ALLOW_METAL

#include "metal/metal.h"
#include "core/buffers/BufferEnums.h"
#include "core/log/Logger.h"

namespace mars {

    class MetalConverter {

    public:
        //! The constructor.
        //! @param logger The logger.
        explicit MetalConverter(Logger &logger);

        //! Converts the BufferUsage to MTL::ResourceOptions
        //! @param usage The BufferUsage enum.
        //! @return The MTL::ResourceOptions.
        MTL::ResourceOptions convert(const BufferUsage usage);
private:
        Logger& logger;
    };

}

#endif

#endif //METAL_CONVERTER_H
