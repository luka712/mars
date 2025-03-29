//
// Created by Erkapic Luka on 29.3.2025.
//

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <cstdint>

namespace asset_toolkit {

    //! The Rectangle struct.
    struct Rectangle {
        //! The x coordinate of the rectangle.
        int32_t x;

        //! The y coordinate of the rectangle.
        int32_t y;

        //! The width of the rectangle.
        int32_t width;

        //! The height of the rectangle.
        int32_t height;

        //! Construct a new Rectangle object.
        //! @param x The x coordinate of the rectangle.
        //! @param y The y coordinate of the rectangle.
        //! @param width The width of the rectangle.
        //! @param height The height of the rectangle.
        Rectangle(const int32_t x, const int32_t y, const int32_t width, const int32_t height)
            : x(x), y(y), width(width), height(height) {
        }
    };
}

#endif //RECTANGLE_H
