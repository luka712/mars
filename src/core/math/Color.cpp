//
// Created by lukaa on 23.11.2024..
//

#include "core/math/Color.h"

namespace mars {
    Color::Color(const float r, const float g, const float b, const float a)
        : r(r), g(g), b(b), a(a)
    {
    }

    Color::Color() {
        r = 1.0f;
        g = 1.0f;
        b = 1.0f;
        a = 1.0f;
    }


}