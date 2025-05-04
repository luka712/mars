//
// Created by Erkapic_Luka on 4.5.2025.
//

#ifndef ENTT_RECT_TRANSFORM_H
#define ENTT_RECT_TRANSFORM_H

#include "glm/glm.hpp"

namespace mars_entt_ecs {

    struct RectTransform {

        RectTransform(): position(0, 0), size(100, 100) {}

        //! The position of the rect transform.
        glm::vec2 position;

        //! The size of the rect transform.
        glm::vec2 size;
    };
}

#endif //RECT_TRANSFORM_H
