//
// Created by Erkapic Luka on 1.1.2025.
//

#ifndef A_SCRIPT_H
#define A_SCRIPT_H

#include "ecs/components/AComponent.h"

namespace mars {

    //! The AScript class.
    //! Represents a script component.
    class AScript : public AComponent {
    public:
        explicit AScript(Entity *entity);
    };

}

#endif //A_SCRIPT_H
