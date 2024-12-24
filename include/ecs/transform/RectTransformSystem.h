//
// Created by lukaa on 9.12.2024.
//

#ifndef RECTTRANSFORMSYSTEM_H
#define RECTTRANSFORMSYSTEM_H

#include <vector>
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
        void remove(RectTransform *rectTransform);

        //! Update the RectTransform components.
        //! @param time The game time.
        void update(const Time &time);

    private:
        std::vector<std::shared_ptr<RectTransform>> rectTransforms;
    };
}

#endif //RECTTRANSFORMSYSTEM_H
