//
// Created by lukaa on 9.12.2024..
//

#ifndef ECSMANAGER_H
#define ECSMANAGER_H

#include <memory>
#include "Framework.h"
#include "ecs/entity/EntityManager.h"
#include "ecs/transform/RectTransformSystem.h"
#include "ecs/sprite/SpriteRendererSystem.h"
#include "ecs/script/ScriptSystem.h"

namespace mars {

    //! The ECSManager class.
	//! Entry point into the ECS part of the engine.
    //! Manages all the systems in ecs part of the engine.
    class ECSManager {

      public:
        //! The constructor of the ECSManager object.
        explicit ECSManager(Framework& framework);

        //! Get the framework.
        //! @return The framework.
        [[nodiscard]] Framework& getFramework() const;

        //! Get the entity manager.
        //! @return The entity manager.
        [[nodiscard]] EntityManager &getEntityManager() const;

        //! Passes the rect transform component to the rect transform system.
        //! @param component The rect transform component.
        void passComponentToSystem(RectTransform *component) const;

        //! Passes the sprite renderer component to the sprite renderer system.
        //! @param component The sprite renderer component.
        void passComponentToSystem(SpriteRenderer* component) const;

        //! Passes the script component to the script system.
        //! @param component The script component.
        void passComponentToSystem(AScript* component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(RectTransform* component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(SpriteRenderer* component) const;

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(AScript* component) const;

        //! Update the ECSManager and all the systems.
        //! @param time The game time.
        void update(const Time &time) const;

        //! Render the ECSManager and all the systems.
        void render() const;

      private:
        Framework& framework;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<RectTransformSystem> rectTransformSystem;
        std::unique_ptr<SpriteRendererSystem> spriteRendererSystem;
        std::unique_ptr<ScriptSystem> scriptSystem;
    };
}


#endif //ECSMANAGER_H
