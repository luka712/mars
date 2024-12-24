//
// Created by lukaa on 9.12.2024..
//

#include "ecs/ECSManager.h"

namespace mars {

    ECSManager::ECSManager(Framework& framework)
        : framework(framework)
    {
        entityManager = std::make_unique<EntityManager>(*this);
        rectTransformSystem = std::make_unique<RectTransformSystem>();
        spriteRendererSystem = std::make_unique<SpriteRendererSystem>(framework);
    }

    EntityManager &ECSManager::getEntityManager() const {
        return *entityManager;
    }

    void ECSManager::passComponentToSystem(RectTransform *rectTransform) const {
        rectTransformSystem->add(rectTransform);
     }

    void ECSManager::passComponentToSystem(SpriteRenderer* spriteRenderer) const {
        spriteRendererSystem->add(spriteRenderer);
    }

    void ECSManager::removeComponentFromSystem(RectTransform* rectTransform) const {
        rectTransformSystem->remove(rectTransform);
    }

    void ECSManager::removeComponentFromSystem(SpriteRenderer* spriteRenderer) const {
        spriteRendererSystem->remove(spriteRenderer);
    }

    void ECSManager::update(const Time &time) {
        rectTransformSystem->update(time);
    }

    void ECSManager::render() {
        spriteRendererSystem->render();
    }

}