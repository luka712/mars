//
// Created by Erkapic Luka on 9.12.2024.
//

#ifndef ECS_MANAGER_H
#define ECS_MANAGER_H

#include <memory>
#include "Framework.h"
#include "ecs/entity/EntityManager.h"
#include "ecs/transform/RectTransformSystem.h"
#include "ecs/sprite/SpriteRendererSystem.h"
#include "ecs/script/ScriptSystem.h"
#include "ecs/tilemap/TileMapSystem.h"
#include "ecs/layer/LayerManager.h"
#include "ecs/camera/Camera2DSystem.h"
#include "ecs/collision/Collision2DSystem.h"
#include "ecs/entity/EntityBuilderLua.h"
#include "ecs/physics2d/Physics2DSystem.h"
#include "ecs/sprite/data/SpriteManager.h"

namespace mars {
    //! The ECSManager class.
	//! Entry point into the ECS part of the engine.
    //! Manages all the systems in ECS part of the engine.
    class ECSManager {
    public:
        //! The constructor of the ECSManager object.
        explicit ECSManager(Framework &framework);

        //! Initialize the ECSManager.
        void initialize() const;

        //! Get the framework.
        //! @return The framework.
        [[nodiscard]] Framework &getFramework() const;

        //! Get the entity manager.
        //! @return The entity manager.
        [[nodiscard]] EntityManager &getEntityManager() const;

        //! Get the sprite manager.
        //! @return The sprite manager.
        [[nodiscard]] SpriteManager &getSpriteManager() const;

        //! Get the layer manager.
        //! @return The layer manager.
        [[nodiscard]] LayerManager &getLayerManager() const { return *layerManager; }

        //! Get the entity builder from lua. Allows to create entities from lua scripts.
        //! @return The entity builder from lua.
        [[nodiscard]] EntityBuilderLua& getEntityBuilderLua() const { return *entityBuilderLua; }

        //! Passes the rect transform component to the rect transform system.
        //! @param component The rect transform component.
        void passComponentToSystem(RectTransform *component) const;

        //! Passes the sprite renderer component to the sprite renderer system.
        //! @param component The sprite renderer component.
        void passComponentToSystem(SpriteRenderer *component) const;

        //! Passes the script component to the script system.
        //! @param component The script component.
        void passComponentToSystem(AScript *component) const;

        //! Passes the tile map component to the tile map system.
        //! @param component The tile map component.
        void passComponentToSystem(TileMap *component) const;

        //! Passes the camera 2D component to the camera 2D system.
        //! @param component The camera 2D component.
        void passComponentToSystem(Camera2D *component) const;

        //! Passes the collider 2D component to the collision 2D system.
        //! @param component The collider 2D component.
        void passComponentToSystem(Collider2D *component) const;

        //! Passes the body 2D component to the physics 2D system.
        //! @param component The body 2D component.
        void passComponentToSystem(RigidBody2D *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const RectTransform *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const SpriteRenderer *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const AScript *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const TileMap *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const Camera2D *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const Collider2D *component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(const RigidBody2D *component) const;

        //! Called when frame starts. Prepares the system for rendering, by sorting according to layer order.
        void frameStart() const;

        //! Update the ECSManager and all the systems.
        //! @param time The game time.
        void update(const Time &time) const;

        //! Render the ECSManager and all the systems.
        void render() const;

    private:
        Framework &framework;
        std::unique_ptr<LayerManager> layerManager;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<RectTransformSystem> rectTransformSystem;
        std::unique_ptr<SpriteRendererSystem> spriteRendererSystem;
        std::unique_ptr<ScriptSystem> scriptSystem;
        std::unique_ptr<TileMapSystem> tileMapSystem;
        std::unique_ptr<Camera2DSystem> camera2DSystem;
        std::unique_ptr<Collision2DSystem> collision2DSystem;
        std::unique_ptr<EntityBuilderLua> entityBuilderLua;
        std::unique_ptr<Physics2DSystem> physics2DSystem;
        std::unique_ptr<SpriteManager> spriteManager;
    };
}


#endif //ECS_MANAGER_H
