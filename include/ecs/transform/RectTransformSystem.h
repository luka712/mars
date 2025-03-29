//
// Created by Erkapic Luka on 9.12.2024.
//

#ifndef RECT_TRANSFORM_SYSTEM_H
#define RECT_TRANSFORM_SYSTEM_H

#include <vector>
#include <memory>
#include "ecs/transform/RectTransform.h"

namespace mars {
    //! System for the RectTransform components.
    class RectTransformSystem {

    public:
        //! Add a RectTransform component to the system.
        //! @param rectTransform The RectTransform component.
        void add(RectTransform* rectTransform);

        //! Remove a RectTransform component from the system.
        //! @param rectTransform The RectTransform component.
        void remove(const RectTransform *rectTransform);

        //! Update the RectTransform components.
        //! @param time The game time.
        void update(const Time &time);

    private:
        std::vector<std::shared_ptr<RectTransform>> rectTransforms;
    };
}

#endif //RECT_TRANSFORM_SYSTEM_H
