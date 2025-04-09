//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef LDTK_LOADER_H
#define LDTK_LOADER_H

#include <string>
#include "asset_toolkit/nlohmann/json.hpp"
#include "asset_toolkit/ldtk/Result.h"
#include "data/LdtkJsonRoot.h"

namespace asset_toolkit {

    //! The LdtkLoader class.
    class LdtkLoader {
    public:

        //! Load the LDTK file.
        //! @param path The path to the LDTK file.
        Result<LdtkJsonRoot> load(const std::string& path);

    private:

        //! Fill the array data from a JSON array.
        //! NOTE: this is for pre-allocated arrays only. Such as when mappings vectors or points from LDTK.
        //! @param arrayToFill The array to fill.
        //! @param jsonArray The JSON array.
        static void fillArrayData(int32_t *arrayToFill, nlohmann::json& jsonArray);

        //! Parse the LDTK root node from a string.
        //! @param rootToFill The root to fill.
        //! @param rootJson The root JSON.
        void parseJsonRootNode(LdtkJsonRoot& rootToFill, nlohmann::json& rootJson);

        //! Fill in level data to the root node.
        //! @param rootToFill The root to fill.
        //! @param levelsJson The JSON of levels.
        void parseLevelNodes(LdtkJsonRoot& rootToFill, nlohmann::json& levelsJson);

        //! Fill in layer instances to the level node.
        //! @param levelToFill The level to fill.
        //! @param layerInstancesJson The JSON of layer instances.
        void parseLayerInstances(LdtkLevel& levelToFill, nlohmann::json& layerInstancesJson);

        //! Fill in array of tile instances from the JSON.
        //! @param arrayToFill The array to fill.
        //! @param tileInstancesJson The JSON of LdtkTileInstances.
        void parseTileInstances(std::vector<LdtkTileInstance>& arrayToFill, nlohmann::json& tileInstancesJson);
    };

}

#endif //LDTK_LOADER_H
