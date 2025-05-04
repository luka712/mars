//
// Created by Erkapic Luka on 4.5.2025.
//

#ifndef ENTT_RECT_TRANSFORM_SYSTEM_H
#define ENTT_RECT_TRANSFORM_SYSTEM_H

#include "core/time/Time.h"

namespace mars_entt_ecs {

    class EnttEcs;

    class RectTransformSystem {
    public:
        //! Constructor
        //! @param ecs The ECS manager.
        explicit RectTransformSystem(EnttEcs &ecs);

        //! Destructor
        ~RectTransformSystem() = default;

        //! Update the rect transform system.
        void update(mars::Time &gameTime);

    private:
        //! The ECS manager.
        EnttEcs &ecsManager;
    };
}

#endif //RECT_TRANSFORM_SYSTEM_H
