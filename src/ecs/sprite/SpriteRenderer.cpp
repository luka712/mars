//
// Created by lukaa on 10.12.2024..
//

#include "core/log/Logger.h"
#include "ecs/sprite/SpriteRenderer.h"
#include <ecs/entity/Entity.h>

namespace mars {
    SpriteRenderer::SpriteRenderer(std::shared_ptr<Entity> entity)
        : AComponent(std::move(entity)), color(Color::white()) {
    }

    const RectTransform *SpriteRenderer::getRectTransform() const {
        return rectTransform.get();
    }

    void SpriteRenderer::initialize() {
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            std::string msg = "SpriteRenderer component requires RectTransform component.";
            // TODO: add logger somehow and log message.
            throw std::runtime_error(msg);
        }
    }
}
