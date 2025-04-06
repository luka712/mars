//
// Created by Erkapic Luka on 2.4.2025.
//

#include <fstream>
#include "asset_toolkit/ldtk/LdtkLoader.h"

#include "asset_toolkit/ldtk/data/LdtkJsonRoot.h"

namespace asset_toolkit {

    Result<LdtkJsonRoot> LdtkLoader::load(const std::string& path) {

        std::ifstream fileStream(path);
        if (!fileStream.good()) {
            return Result<LdtkJsonRoot>::error("Failed to open file: " + path);
        }

        nlohmann::json data = nlohmann::json::parse(fileStream);
        LdtkJsonRoot root;
        root.iid = data["iid"];
        root.jsonVersion = data["jsonVersion"];

        return Result<LdtkJsonRoot>::success(root);
    }

}
