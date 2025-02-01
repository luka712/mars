//
// Created by lukaa on 27.11.2024..
//

#ifndef RECT_H
#define RECT_H

#include <cstdint>

namespace mars {
    //! The Rect struct represents a rectangle.
    struct Rect {

        //! The x position of the rectangle.
        int32_t x;

        //! The y position of the rectangle.
        int32_t y;

        //! The width of the rectangle.
        int32_t width;

        //! The height of the rectangle.
        int32_t height;

        //! Check if the rectangle intersects with another rectangle.
        //! @param other The other rectangle.
        //! @return True if the rectangles intersect, false otherwise.
        [[nodiscard]] bool intersects(const Rect &other) const;
    };
};

#endif //RECT_H
