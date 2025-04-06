//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef LDTK_JSON_ROOT_H
#define LDTK_JSON_ROOT_H

#include <vector>
#include "asset_toolkit/ldtk/data/LdtkLevel.h"

namespace asset_toolkit {
    //! This is the root of any Project JSON file.
    struct LdtkJsonRoot {

        //! Unique project identifier.
        std::string iid;

        //! File format version.
        std::string jsonVersion;

        //! All levels. The order of this array is only relevant in <code>LinearHorizontal</code> and <code>linearVertical</code>
        //! world layouts (see <code>worldLayout</code> value). <br/>
        //! Otherwise, you should refer to the <code>worldX</code>, <code>worldY</code> coordinates of each Level.
        std::vector<asset_tookit::LdtkLevel> levels;
    };
}

#endif //LDTK_JSON_ROOT_H
