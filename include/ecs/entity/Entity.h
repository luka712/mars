//
// Created by lukaa on 8.12.2024..
//

#ifndef ENTITY_H
#define ENTITY_H

#include <vector>
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
        std::shared_ptr<T> getComponent() {
            for (const std::shared_ptr<AComponent>& component : components) {
                if (std::dynamic_pointer_cast<T>(component)) {
                    return std::dynamic_pointer_cast<T>(component);
                }
            }
            return nullptr;
        }

        //! Add a new component to the entity.
        template<typename T>
        std::shared_ptr<T> addComponent() {

            // Make a shared pointer to self, in order to pass to the component.
            std::shared_ptr<Entity> self = std::make_shared<Entity>(*this);

            // Create a component.
            std::shared_ptr<T> component = std::make_shared<T>(self);
            components.emplace_back(component);

            // Pass the component to the system.
            ecsManager.passComponentToSystem(component);

            component->initialize();

            return component;
        }

        //! Remove a component from the entity.
        template <typename T>
        void removeComponent() {
            for (int i = 0; i < components.size(); i++) {

                // If the component is of the type T.
                if (std::shared_ptr<T> component = std::dynamic_pointer_cast<T>(components[i])) {

                    // Remove the component from the system.
                    ecsManager.removeComponentFromSystem(component);

                    // Remove the component from the entity.
                    components.erase(components.begin() + i);
                    break;
                }
            }
        }

        //! Get the information about the entity.
        //! @return The information about the entity.
        std::string toString();

    private:
        ECSManager &ecsManager;
        std::string name;
        std::vector<std::shared_ptr<AComponent>> components;
    };
}


#endif //ENTITY_H
