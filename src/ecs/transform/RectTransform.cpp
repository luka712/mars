//
// Created by lukaa on 8.12.2024..
//

#include <sstream>
#include "ecs/transform/RectTransform.h"

namespace mars {
    RectTransform::RectTransform(Entity* entity)
        : AComponent(entity), drawRectangle(), rotation(0) {
    }

    void RectTransform::setPosition(const glm::vec2 position) {
        drawRectangle.x = static_cast<int32_t>(position.x);
        drawRectangle.y = static_cast<int32_t>(position.y);
    }

    Rect RectTransform::getDrawRectangle() const {
        return drawRectangle;
    }

    void RectTransform::setDrawRectangle(const Rect drawRectangle) {
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
