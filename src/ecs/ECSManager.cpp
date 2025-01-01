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
        scriptSystem = std::make_unique<ScriptSystem>(framework);
    }

    Framework &ECSManager::getFramework() const {
        return framework;
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

    void ECSManager::passComponentToSystem(AScript* script) const {
        scriptSystem->add(script);
    }

    void ECSManager::removeComponentFromSystem(RectTransform* rectTransform) const {
        rectTransformSystem->remove(rectTransform);
    }

    void ECSManager::removeComponentFromSystem(SpriteRenderer* spriteRenderer) const {
        spriteRendererSystem->remove(spriteRenderer);
    }

    void ECSManager::removeComponentFromSystem(AScript* script) const {
        scriptSystem->remove(script);
    }

    void ECSManager::update(const Time &time) const {
        scriptSystem->update(time);
        rectTransformSystem->update(time);
        spriteRendererSystem->update(time);
    }

    void ECSManager::render() const {
        scriptSystem->render();
        spriteRendererSystem->render();
    }

}