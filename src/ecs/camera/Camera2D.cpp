//
// Created by lukaa on 22.1.2025..
//

#include <sstream>
#include "ecs/entity/Entity.h"
#include "ecs/camera/Camera2D.h"

namespace mars {
    Camera2D::Camera2D(Entity *entity)
        : AComponent(entity) {
    }

    void Camera2D::setWidth(uint32_t width) {
        this->width = width;
    }

    void Camera2D::setHeight(uint32_t height) {
        this->height = height;
    }

    void Camera2D::initialize() {
        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            const std::string msg = "Camera2D component requires RectTransform component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }

    RectTransform *Camera2D::getRectTransform() {
        return rectTransform;
    }

    std::string Camera2D::toString()  {
        std::stringstream result;

        result << "Camera2D\n";

        return result.str();
    }
}
