//
// Created by Erkapic Luka on 10.12.2024.
//

#include <sstream>
#include "ecs/sprite/SpriteRenderer.h"
#include "ecs/sprite/AnimatedSpriteRenderer.h"
#include "ecs/entity/Entity.h"

namespace mars {

    SpriteRenderer::SpriteRenderer(Entity* entity)
        : AComponent(entity), color(Color::white()) {
    }

    const RectTransform* SpriteRenderer::getRectTransform() const {
        return rectTransform;
    }

    Sprite* SpriteRenderer::getSprite() const {
        return sprite;
    }

    void SpriteRenderer::setSprite(Sprite* sprite) {
        this->sprite = sprite;
    }

    void SpriteRenderer::initialize() {

        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>();
        if (rectTransform == nullptr) {
            std::string msg = "SpriteRenderer component requires RectTransform component.";
            framework.getLogger().error(msg.c_str());
            throw std::runtime_error(msg);
        }
    }

    std::string SpriteRenderer::toString() {
        std::stringstream result;

        Sprite* sprite = getSprite();

        result << "SpriteRenderer\n"
           //  << "\t - sprite(" << sprite->getTexture()->getLabel() << ")\n"
            << "\t - color(" << this->color.r << ", "
            << this->color.g << ", "
            << this->color.b << ", "
            << this->color.a << ")\n";

        return result.str();
    }
}
