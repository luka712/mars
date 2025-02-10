//
// Created by luka on 10.02.25.
//

#include "core/buffers/AUniformBuffer.h"
#include <Framework.h>

mars::AUniformBuffer::AUniformBuffer(Framework &framework, const std::string &label, uint32_t byteSize, BufferUsage bufferUsage)
    : framework(framework), logger(framework.getLogger()), label(label), byteSize(byteSize), bufferUsage(bufferUsage)
{
}
