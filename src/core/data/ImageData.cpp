//
// Created by lukaa on 21.12.2024.
//

#include "core/data/ImageData.h"

namespace mars {

    ImageData::ImageData(uint32_t width, uint32_t height, unsigned char *data, uint32_t channels)
        : width(width), height(height), data(data, data + width * height * channels), channels(channels) {
    }

    uint32_t ImageData::getWidth() const {
        return width;
    }

    uint32_t ImageData::getHeight() const {
        return height;
    }

    const uint8_t *ImageData::getData() const {
        return data.data();
    }

    uint32_t ImageData::getChannels() const {
        return channels;
    }

    void ImageData::destroy() {
        data.clear();
    }

}