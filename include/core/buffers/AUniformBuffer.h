//
// Created by luka on 09.02.25.
//

#ifndef AUNIFORMBUFFER_H
#define AUNIFORMBUFFER_H

#include <cstdint>
#include <string>
#include "core/buffers/BufferEnums.h"

namespace mars
{
    class Framework;
    class Logger;

    //! The uniform buffer.
    class AUniformBuffer
    {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param label The label.
        //! @param byteSize The size of the buffer.
        //! @param bufferUsage The usage of the buffer.
        AUniformBuffer(Framework& framework, const std::string& label, uint32_t byteSize, BufferUsage bufferUsage);

        //! Gets the label of this uniform buffer.
        //! @return The label of this uniform buffer.
        [[nodiscard]] std::string getLabel() const { return label; }

        //! Gets the size of this uniform buffer in bytes.
        //! @return The size of this uniform buffer.
        [[nodiscard]] uint32_t getSize() const { return byteSize; }

        //! Gets the buffer usage.
        //! @return The buffer usage.
        [[nodiscard]] BufferUsage getBufferUsage() const { return bufferUsage; }

        //! Update the uniform buffer.
        //! @param data The data to update the buffer with.
        //! @param byteSize The size of the data in bytes.
        virtual void update(void* data, uint32_t byteSize) = 0;

        //! Logs information about the buffer and returns it as a string.
        //! @return The information about the buffer.
        virtual std::string printInfo() = 0;

        //! Destroys the uniform buffer.
        virtual void destroy() = 0;

    protected:
        Framework& framework;
        Logger& logger;
        std::string label;
        uint32_t byteSize{};
        BufferUsage bufferUsage{};
    };
}


#endif //AUNIFORMBUFFER_H
