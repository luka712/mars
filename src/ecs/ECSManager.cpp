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
        tileMapSystem = std::make_unique<TileMapSystem>(framework);
    }

    Framework &ECSManager::getFramework() const {
        return framework;
    }

    EntityManager &ECSManager::getEntityManager() const {
        return *entityManager;
    }

    void ECSManager::passComponentToSystem(RectTransform *component) const {
        rectTransformSystem->add(component);
     }

    void ECSManager::passComponentToSystem(SpriteRenderer* component) const {
        spriteRendererSystem->add(component);
    }

    void ECSManager::passComponentToSystem(AScript* component) const {
        scriptSystem->add(component);
    }

    void ECSManager::passComponentToSystem(TileMap *component) const {
        tileMapSystem->add(component);
    }

    void ECSManager::removeComponentFromSystem(RectTransform* component) const {
        rectTransformSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const SpriteRenderer* spriteRenderer) const {
        spriteRendererSystem->remove(spriteRenderer);
    }

    void ECSManager::removeComponentFromSystem(AScript* component) const {
        scriptSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(TileMap *component) const {
        tileMapSystem->remove(component);
    }

    void ECSManager::update(const Time &time) const {
        scriptSystem->update(time);
        rectTransformSystem->update(time);
        spriteRendererSystem->update(time);
    }

    void ECSManager::render() const {
        SpriteBatch& spriteBatch = framework.getSpriteBatch();
        spriteBatch.begin();
        scriptSystem->render();
        tileMapSystem->render();
        spriteRendererSystem->render();
        spriteBatch.end();
    }

}