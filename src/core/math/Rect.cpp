//
// Created by lukaa on 1.2.2025.
//

#include "core/math/Rect.h"

namespace mars {
    bool Rect::intersects(const Rect &other) const {
        return x < other.x + other.width &&
               x + width > other.x &&
               y < other.y + other.height &&
               y + height > other.y;
    }
}
