//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef LDTK_LOADER_H
#define LDTK_LOADER_H

#include "asset_toolkit/nlohmann/json.hpp"
#include "asset_toolkit/ldtk/Result.h"
#include <string>

#include "data/LdtkJsonRoot.h"

namespace asset_toolkit {

    //! The LdtkLoader class.
    class LdtkLoader {
    public:

        //! Load the LDTK file.
        //! @param path The path to the LDTK file.
        Result<LdtkJsonRoot> load(const std::string& path);

    private:
        LdtkJsonRoot loadJsonRootNode(const std::string& path);
    };

}

#endif //LDTK_LOADER_H
