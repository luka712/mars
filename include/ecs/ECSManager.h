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

namespace mars {

    //! The ECSManager class.
	//! Entry point into the ECS part of the engine.
    //! Manages all the systems in ecs part of the engine.
    class ECSManager {

      public:
        //! The constructor of the ECSManager object.
        ECSManager(Framework& framework);

        //! Get the entity manager.
        //! @return The entity manager.
        EntityManager &getEntityManager() const;

        //! Passes the rect transform component to the rect transform system.
        //! @param component The rect transform component.
        void passComponentToSystem(std::shared_ptr<RectTransform> component);

        //! Passes the sprite renderer component to the sprite renderer system.
        //! @param component The sprite renderer component.
        void passComponentToSystem(std::shared_ptr<SpriteRenderer> component);

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(std::shared_ptr<RectTransform> component);

        //! Removes the component from the system.
        //! @param component The component to remove.
        void removeComponentFromSystem(std::shared_ptr<SpriteRenderer> component);

        //! Update the ECSManager and all the systems.
        //! @param time The game time.
        void update(const Time &time);

        //! Render the ECSManager and all the systems.
        void render();

      private:
        Framework& framework;
        std::unique_ptr<EntityManager> entityManager;
        std::unique_ptr<RectTransformSystem> rectTransformSystem;
        std::unique_ptr<SpriteRendererSystem> spriteRendererSystem;
    };
}


#endif //ECSMANAGER_H
