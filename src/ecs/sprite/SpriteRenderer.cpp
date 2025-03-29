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
        return sprite.get();
    }

    // ReSharper disable once CppPassValueParameterByConstReference
    void SpriteRenderer::setSprite(std::shared_ptr<Sprite> sprite) {
        this->sprite = sprite;
    }

    void SpriteRenderer::initialize() {
        // Entity must have RectTransform component.
        rectTransform = entity->getComponent<RectTransform>("SpriteRenderer component requires RectTransform component.");
    }

    void SpriteRenderer::destroy() {
        sprite.reset();
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
