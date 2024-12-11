//
// Created by lukaa on 8.12.2024..
//

#ifndef ACOMPONENT_H
#define ACOMPONENT_H

#include <memory>
#include <core/life_management/State.h>

#include "core/time/Time.h"

namespace mars {
    class Entity;

    class AComponent {
    public:
        //! The constructor of the AComponent object.
        //! @param entity The entity that the component is attached to.
        explicit AComponent(std::shared_ptr<Entity> entity);

        //! Destroy the Component object.
        virtual ~AComponent() = default;

        //! Gets the entity that the component is attached to.
        [[nodiscard]] Entity& getEntity() const;

        //! Initialize the component.
        virtual void initialize();

        //! Update the component.
        //! @param time The game time.
        virtual void update(const Time &time) {
        }

        //! Render the component.
        virtual void render() {
        }

        //! Destroy the component.
        virtual void destroy();

        //! Get the string representation of the component.
        //! @return The string representation of the component.
        virtual std::string toString();

    protected:
        State state = State::CREATED;
        std::shared_ptr<Entity> entity;

    };
}


#endif //ACOMPONENT_H
