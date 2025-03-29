//
// Created by Erkapic Luka on 8.12.2024.
//

#ifndef A_COMPONENT_H
#define A_COMPONENT_H

#include <string>
#include "core/life_management/State.h"
#include "core/time/Time.h"

namespace mars {
    class Framework;
    class Entity;

    class AComponent {
    public:
        //! The constructor of the AComponent object.
        //! @param entity The entity that the component is attached to.
        explicit AComponent(Entity* entity);

        //! Destroy the Component object.
        virtual ~AComponent() = default;

        //! Gets the entity that this component is attached to.
        [[nodiscard]] Entity& getEntity() const;

        //! Initialize the component.
        virtual void initialize();

        //! Update the component.
        //! @param time The game time.
        virtual void update(const Time &time) {}

        //! Render the component.
        virtual void render() {}

        //! Destroy the component.
        virtual void destroy();

        //! Get the string representation of the component.
        //! @return The string representation of the component.
        virtual std::string toString();

    protected:
        Framework& framework;
        State state = CREATED;
        Entity* entity;

    };
}


#endif //A_COMPONENT_H
