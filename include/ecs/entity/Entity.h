//
// Created by lukaa on 8.12.2024..
//

#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>

#include "ecs/ECSManager.h"
#include "ecs/components/AComponent.h"

namespace mars {
    class EntityManager;
    class ECSManager;

    class Entity {
    public:
        //! Construct a new Entity object.
        //! @param ecsManager The systems' manager.
        //! @param name The name of the entity.
        Entity(ECSManager& ecsManager, std::string name);

        //! Get the name of the entity.
        [[nodiscard]] std::string getName() const;

        //! Set the name of the entity.
        //! @param name The name of the entity.
        void setName(const std::string &name);

        //! Get a component of the entity.
        template<typename T>
        T* getComponent() {
            const std::string key = typeid(T).name();
            if (componentsMap.contains(key)) {
                return dynamic_cast<T*>(componentsMap[key].get());
            }

            return nullptr;
        }

        //! Add a new component to the entity.
        template<typename T>
        T* addComponent() {

            std::string key = typeid(T).name();
            componentsMap[key] = std::make_shared<T>(this);
            T* component = dynamic_cast<T*>(componentsMap[key].get());

            // Pass the component to the system.
            ecsManager.passComponentToSystem(component);

            // Initialize it.
            component->initialize();

            return component;
        }

        //! Remove a component from the entity.
        template <typename T>
        void removeComponent() {
            const std::string key = typeid(T).name();
            if (componentsMap.contains(key)) {
                T* component = dynamic_cast<T*>(componentsMap[key].get());
                ecsManager.removeComponentFromSystem(component);
                componentsMap.erase(key);
            }
        }

        //! Get the information about the entity.
        //! @return The information about the entity.
        std::string toString() const;

    private:
        ECSManager &ecsManager;
        std::string name;
        std::map<std::string, std::shared_ptr<AComponent>> componentsMap;
    };
}


#endif //ENTITY_H
