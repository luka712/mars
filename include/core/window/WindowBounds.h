//
// Created by lukaa on 23.11.2024..
//

#ifndef WINDOWBOUNDS_H
#define WINDOWBOUNDS_H

#include <stdint.h>

namespace mars
{
    /**
     * @brief The WindowBounds struct represents the width and height of a window.
     */
    struct WindowBounds
    {
        /**
         * @brief Construct a new WindowBounds object.
         *
         * @param width The width of the window.
         * @param height The height of the window.
         */
        WindowBounds(const int32_t width, const int32_t height) : width(width), height(height) {}

        /**
         * @brief The width of the window.
         */
        int32_t width;

        /**
         * @brief The height of the window.
         */
        int32_t height;
    };
};

#endif //WINDOWBOUNDS_H
