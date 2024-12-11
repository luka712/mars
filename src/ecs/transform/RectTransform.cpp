//
// Created by lukaa on 8.12.2024..
//

#include <utility>
#include <bits/stdc++.h>
#include "ecs/transform/RectTransform.h"


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

    std::string RectTransform::toString() {
        std::stringstream result;
        result << "RectTransform\n"
            << "\t - drawRectangle("
            << drawRectangle.x << ", "
            << drawRectangle.y << ", "
            << drawRectangle.width << ", "
            << drawRectangle.height << ")\n"
            << "\t - rotation("  << rotation << ")\n";
        return result.str();
    }

}
