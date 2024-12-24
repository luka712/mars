//
// Created by lukaa on 9.12.2024..
//

#include "ecs/transform/RectTransformSystem.h"

namespace mars {

    void RectTransformSystem::add(RectTransform* rectTransform) {
        rectTransforms.emplace_back(rectTransform);
    }

    void RectTransformSystem::remove(RectTransform *rectTransform) {
        for (int i = 0; i < rectTransforms.size(); i++) {
            if (rectTransforms[i].get() == rectTransform) {
                rectTransforms.erase(rectTransforms.begin() + i);
                break;
            }
        }
    }

    void RectTransformSystem::update(const Time &time) {
        for (std::shared_ptr<RectTransform>& rectTransform : rectTransforms) {
            rectTransform->update(time);
        }
    }

}