//
// Created by Erkapic Luka on 8.12.2024.
//

#ifndef ENTITY_H
#define ENTITY_H

#include <map>
#include <string>

#include "ecs/ECSManager.h"
#include "ecs/components/AComponent.h"

namespace mars {
    class Layer;
    class Framework;
    class EntityManager;
    class ECSManager;

    class Entity {
    public:
        //! Construct a new Entity object.
        //! @param ecsManager The systems' manager.
        //! @param name The name of the entity.
        Entity(ECSManager& ecsManager, std::string name);

        //! Gets the framework.
        //! @return The framework.
        [[nodiscard]] Framework& getFramework() const;

        //! Gets the ECS manager.
        //! @return The ECS manager.
        [[nodiscard]] ECSManager& getECSManager() const { return ecsManager; }

        //! Get the name of the entity.
        [[nodiscard]] std::string getName() const;

        //! Get the layer of the entity.
        [[nodiscard]] const Layer& getLayer() const { return *layer; }

        //! Set the layer of the entity.
        //! @param layer Set the layer of the entity.
        void setLayer(const std::shared_ptr<Layer> &layer);

        //! Unset the layer of the entity. This will create default layer.
        void unsetLayer();

        //! Set the name of the entity.
        //! @param name The name of the entity.
        void setName(const std::string &name);

        //! Get a component of the entity.
        //! Throws an exception if the component is not found.
        //! @tparam T The type of the component.
        //! @param validationMessage The override message to throw if the component is not found. If empty, default message is thrown.
        //! @return The component.
        template<typename T>
        T* getComponent(const std::string& validationMessage = "") {

            const std::string key = typeid(T).name();
            if (componentsMap.contains(key)) {
                return dynamic_cast<T*>(componentsMap[key].get());
            }

            // If validation message is provided, throw an exception with that message.
            const std::string msg = validationMessage == "" ? "Entity::getComponent does not have a valid component of type " + key : validationMessage;
            framework.getLogger().error(msg);
            throw std::runtime_error(msg);
        }

        //! Get a component of the entity.
        //! Returns nullptr if the component is not found.
        //! @tparam T The type of the component.
        //! @return The component.
        template<typename T>
        T* getComponentOrNull() {

            if (const std::string key = typeid(T).name(); componentsMap.contains(key)) {
                return dynamic_cast<T*>(componentsMap[key].get());
            }

            return nullptr;
        }

        //! Add a new component to the entity.
        template<typename T>
        T* addComponent() {

            // Check if component is already added. If so, fail because it cannot be added twice.
            const std::string key = typeid(T).name();
            if ( componentsMap.contains(key)) {
                int32_t status = 0;
                // char* demangledName = abi::__cxa_demangle(key.c_str(), nullptr, nullptr, &status);
                const std::string name = key;
                const std::string msg = "Component of type " + name + " is already added to the entity.";
                framework.getLogger().error(msg.c_str());
                throw std::runtime_error(msg);
            }

            componentsMap[key] = std::make_shared<T>(this);
            T* component = dynamic_cast<T*>(componentsMap[key].get());

            // Initialize it.
            component->initialize();

            // Pass the component to the system.
            ecsManager.passComponentToSystem(component);

            return component;
        }

        //! Remove a component from the entity.
        template <typename T>
        void removeComponent() {
            if (const std::string key = typeid(T).name(); componentsMap.contains(key)) {
                T* component = dynamic_cast<T*>(componentsMap[key].get());
                ecsManager.removeComponentFromSystem(component);
                componentsMap.erase(key);
            }
        }

        //! Get the information about the entity.
        //! @return The information about the entity.
        [[nodiscard]] std::string toString() const;

    private:
        Framework& framework;
        ECSManager &ecsManager;
        std::string name;
        std::map<std::string, std::shared_ptr<AComponent>> componentsMap;
        std::shared_ptr<Layer> layer;
    };
}


#endif //ENTITY_H
