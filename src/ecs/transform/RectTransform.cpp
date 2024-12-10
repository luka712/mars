//
// Created by lukaa on 8.12.2024..
//

#include <utility>

#include "ecs/transform/RectTransform.h"

#include <iostream>

namespace mars {
    RectTransform::RectTransform(std::shared_ptr<Entity> entity)
        : AComponent(std::move(entity)) {
    }

    Rect RectTransform::getDrawRectangle() const {
        return drawRectangle;
    }

    void RectTransform::setDrawRectangle(const Rect &drawRectangle) {
        this->drawRectangle = drawRectangle;
        isDirty = true;
    }

    void RectTransform::update(const Time &time) {
        if (isDirty) {
            // Update the position of the entity.
            isDirty = false;
        }
    }

}
