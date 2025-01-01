//
// Created by lukaa on 1.1.2025..
//

#ifndef ASCRIPT_H
#define ASCRIPT_H

#include "ecs/components/AComponent.h"

namespace mars {

    //! The AScript class.
    //! Represents a script component.
    class AScript : public AComponent {
    public:
        explicit AScript(Entity *entity);
    };

}

#endif //ASCRIPT_H
