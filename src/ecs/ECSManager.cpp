//
// Created by lukaa on 9.12.2024..
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
        collision2DSystem = std::make_unique<Collision2DSystem>(framework);
    }

    void ECSManager::initialize() const {
        collision2DSystem->initialize();
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

    void ECSManager::passComponentToSystem(Collider2D *component) const {
        collision2DSystem->add(component);
    }

    void ECSManager::removeComponentFromSystem(RectTransform *component) const {
        rectTransformSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const SpriteRenderer *component) const {
        spriteRendererSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(AScript *component) const {
        scriptSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const TileMap *component) const {
        tileMapSystem->remove(component);
    }

    void ECSManager::removeComponentFromSystem(const Camera2D *camera) const {
        camera2DSystem->remove(camera);
    }

    void ECSManager::removeComponentFromSystem(const Collider2D *collider) const {
        collision2DSystem->remove(collider);
    }

    void ECSManager::frameStart() const {
        spriteRendererSystem->frameStart();
        tileMapSystem->frameStart();
    }

    void ECSManager::update(const Time &time) const {
        const std::vector<std::shared_ptr<Layer> > &layers = layerManager->getLayers();

        scriptSystem->update(time);
        rectTransformSystem->update(time);
        collision2DSystem->update(time);

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
            collision2DSystem->render(*camera);
        }

    }
}
