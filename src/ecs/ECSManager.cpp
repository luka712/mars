//
// Created by Erkapic Luka on 9.12.2024.
//

#include "ecs/ECSManager.h"
#include <ecs/entity/Entity.h>

namespace mars {
    ECSManager::ECSManager(Framework &framework)
        : framework(framework) {
        layerManager = std::make_unique<LayerManager>(framework);
        entityManager = std::make_unique<EntityManager>(*this);
        rectTransformSystem = std::make_unique<RectTransformSystem>();
        spriteRendererSystem = std::make_unique<SpriteRendererSystem>(framework);
        scriptSystem = std::make_unique<ScriptSystem>(framework);
        tileMapSystem = std::make_unique<TileMapSystem>(framework);
        camera2DSystem = std::make_unique<Camera2DSystem>(framework);
        entityBuilderLua = std::make_unique<EntityBuilderLua>(framework, *this);
        physics2DSystem = std::make_unique<Physics2DSystem>(framework);
        spriteManager = std::make_unique<SpriteManager>(framework);
    }

    void ECSManager::initialize() const {
        physics2DSystem->initialize();
    }

    Framework &ECSManager::getFramework() const {
        return framework;
    }

    EntityManager &ECSManager::getEntityManager() const {
        return *entityManager;
    }

    SpriteManager &ECSManager::getSpriteManager() const {
        return *spriteManager;
    }

    void ECSManager::passComponentToSystem(RectTransform *component) const {
        rectTransformSystem->add(component);
    }

    void ECSManager::passComponentToSystem(SpriteRenderer *component) const {
        spriteRendererSystem->add(component);
    }

    void ECSManager::passComponentToSystem(AScript *component) const {
        scriptSystem->add(component);
    }

    void ECSManager::passComponentToSystem(TileMap *component) const {
        tileMapSystem->add(component);
    }

    void ECSManager::passComponentToSystem(Camera2D *component) const {
        camera2DSystem->add(component);
    }

    void ECSManager::passComponentToSystem(ACollider2D *component) const {
        physics2DSystem->add(component);
    }

    void ECSManager::passComponentToSystem(RigidBody2D *component) const {
        physics2DSystem->add(component);
    }

    void ECSManager::removeComponentFromSystem(const RectTransform *component) const {
        rectTransformSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const SpriteRenderer *component) const {
        spriteRendererSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const AScript *component) const {
        scriptSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const TileMap *component) const {
        tileMapSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const Camera2D *component) const {
        camera2DSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const ACollider2D *component) const {
        physics2DSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const RigidBody2D *component) const {
        physics2DSystem->remove(component);
    }

    void ECSManager::frameStart() const {
        spriteRendererSystem->frameStart();
        tileMapSystem->frameStart();
    }

    void ECSManager::update(const Time &time) const {
        const std::vector<std::shared_ptr<Layer> > &layers = layerManager->getLayers();

        physics2DSystem->update(time);
        scriptSystem->update(time);
        rectTransformSystem->update(time);

        for (auto &layer: layers) {
            const uint32_t currentLayerOrder = layer->getOrder();
            spriteRendererSystem->update(time, currentLayerOrder);
        }
    }

    void ECSManager::render() const {
        const std::vector<std::shared_ptr<Layer> > &layers = layerManager->getLayers();

        scriptSystem->render();

        const std::vector<Camera2D*>& cameras = camera2DSystem->getCameraComponents();

        for (auto& camera : cameras) {
            for (auto &layer: layers) {
                const uint32_t currentLayerOrder = layer->getOrder();
                tileMapSystem->render(currentLayerOrder, *camera);
                spriteRendererSystem->render(currentLayerOrder, *camera);
            }
        }

        physics2DSystem->render();
    }
}
