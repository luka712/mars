//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef LDTK_LEVEL_H
#define LDTK_LEVEL_H

#include <vector>
#include "asset_toolkit/ldtk/data/LdtkLayerInstance.h"

namespace asset_toolkit {

    //! Contains all the information about a level.
    struct LdtkLevel {

        //! User defined unique identifier.
        std::string identifier;

        //! Width of the level in pixels.
        int32_t pxWid;

        //! Height of the level in pixels.
        int32_t pxHei;


        std::vector<LdtkLayerInstance> layerInstances;

    };
}

#endif //LDTK_LEVEL_H
