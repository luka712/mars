//
// Created by lukaa on 21.12.2024.
//

#ifndef IMAGEDATA_H
#define IMAGEDATA_H

#include <vector>
#include <cstdint>

namespace mars {
    //! The ImageData class.
    //! Represents the image data.
    class ImageData {
    public:
        //! Construct a new ImageData object.
        //! @param width The width of the image.
        //! @param height The height of the image.
        //! @param data The image data.
        //! @param channels The number of channels.
        ImageData(uint32_t width, uint32_t height, unsigned char *data, uint32_t channels);

        //! Get the width of the image.
        //! @return The width of the image.
        [[nodiscard]] virtual uint32_t getWidth() const;

        //! Get the height of the image.
        //! @return The height of the image.
        [[nodiscard]] virtual uint32_t getHeight() const;

        //! Get the image data.
        //! @return The image data.
        [[nodiscard]] virtual const uint8_t *getData() const;

        //! Get the number of channels.
        //! @return The number of channels.
        [[nodiscard]] virtual uint32_t getChannels() const;

        //! Destroy the image data.
        virtual void destroy();

    protected:
        uint32_t width;
        uint32_t height;
        std::vector<uint8_t> data;
        uint32_t channels;
    };
}

#endif //IMAGEDATA_H
