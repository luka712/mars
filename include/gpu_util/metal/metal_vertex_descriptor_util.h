//
// Created by Luka Erkapic on 15.08.25.
//

#ifdef __APPLE__

#ifndef METAL_VERTEX_DESCRIPTOR_UTIL_H
#define METAL_VERTEX_DESCRIPTOR_UTIL_H

#include <string>
#include "metal/metal.h"
#include "gpu_util/logger.h"

namespace gpu_util {
    //! Utility class for creating Metal vertex descriptors.
    class MetalVertexDescriptorUtil {
    public:
        //! Creates a Metal Vertex Descriptor for position, color, and texture coordinates in interleaved format.
        //! @return A VertexDescriptor,
        MTL::VertexDescriptor* createPositionColorTextureCoordinatesVertexDescriptor();
    };
}

#endif //METAL_VERTEX_DESCRIPTOR_UTIL_H

#endif
