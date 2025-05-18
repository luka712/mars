//
// Created by luka on 18/05/25.
//

#ifndef LAYER_TAG_H
#define LAYER_TAG_H

#include <cstdint>

namespace mars_entt_ecs {

    //! The first layer within the game.
    struct Layer0Tag {
        int32_t layer = 0;
    };

    //! The second layer within the game.
    struct Layer1Tag {
        int32_t layer = 1;
    };

    //! The third layer within the game.
    struct Layer2Tag {
        int32_t layer = 2;
    };
}

#endif //LAYER_TAG_H
