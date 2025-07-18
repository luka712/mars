//
// Created by Luka Erkapic on 11.05.25.
//

#ifndef METAL_CONVERTER_H
#define METAL_CONVERTER_H

#if __APPLE__

#include "metal/metal.h"
#include "core/buffers/buffer_enums.h"
#include "core/log/Logger.h"

namespace mars {

    //! The class that helps with converting <b>mars</b> types to <b>metal</b> types and vice-versa.
    class MetalConverter {

    public:
        //! Initialize the converted and assign logger.
        //! @param logger The logger.
        static void initialize(Logger *logger);

        //! Converts the BufferUsage to MTL::ResourceOptions
        //! @param usage The BufferUsage enum.
        //! @return The MTL::ResourceOptions.
        static MTL::ResourceOptions convert(const BufferUsage usage);
private:
        static Logger* logger;
    };

}

#endif

#endif //METAL_CONVERTER_H
