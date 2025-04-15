//
// Created by Erkapic Luka on 2.4.2025.
//

#include <fstream>
#include "asset_toolkit/ldtk/LdtkLoader.h"
#include "asset_toolkit/ldtk/data/LdtkJsonRoot.h"

namespace asset_toolkit {
    Result<LdtkJsonRoot> LdtkLoader::load(const std::string &path) {
        std::ifstream fileStream(path);
        if (!fileStream.good()) {
            return Result<LdtkJsonRoot>::error("Failed to open file: " + path);
        }

        nlohmann::json data = nlohmann::json::parse(fileStream);
        LdtkJsonRoot root;
        parseJsonRootNode(root, data);


        return Result<LdtkJsonRoot>::success(root);
    }

    void LdtkLoader::fillArrayData(int32_t *arrayToFill, nlohmann::json &jsonArray) {
        for (size_t i = 0; i < jsonArray.size(); i++) {
            arrayToFill[i] = jsonArray[i].get<int>();
        }
    }

    void LdtkLoader::parseJsonRootNode(LdtkJsonRoot &rootToFill, nlohmann::json &rootJson) {
        rootToFill.iid = rootJson["iid"];
        rootToFill.jsonVersion = rootJson["jsonVersion"];

        parseLevelNodes(rootToFill, rootJson["levels"]);
    }

    void LdtkLoader::parseLevelNodes(LdtkJsonRoot &rootToFill, nlohmann::json &levelsJson) {
        for (const nlohmann::json &levelNode: levelsJson) {
            LdtkLevel level;
            level.identifier = levelNode["identifier"];
            level.pxWid = levelNode["pxWid"].get<int>();
            level.pxHei = levelNode["pxHei"].get<int>();

            // - LAYER INSTANCES
            nlohmann::json layerInstancesJson = levelNode["layerInstances"];
            parseLayerInstances(level, layerInstancesJson);

            rootToFill.levels.push_back(level);
        }
    }

    void LdtkLoader::parseLayerInstances(LdtkLevel &levelToFill, nlohmann::json &layerInstancesJson) {
        for (const nlohmann::json &layerInstance: layerInstancesJson) {
            LdtkLayerInstance layer;
            layer.levelId = layerInstance["levelId"];
            layer.__tilesetRelPath = layerInstance["__tilesetRelPath"];
            layer.visible = layerInstance["visible"];
            layer.__cWid = layerInstance["__cWid"];
            layer.__cHei = layerInstance["__cHei"];

            // - INT GRID CSV
            for (const nlohmann::json &value: layerInstance["intGridCsv"]) {
                layer.intGridCsv.push_back(value);
            }

            // - AUTO LAYER TILES
            nlohmann::json autoLayerTiles = layerInstance["autoLayerTiles"];
            parseTileInstances(layer.autoLayerTiles, autoLayerTiles);

            // - GRID TILES
            nlohmann::json gridTiles = layerInstance["gridTiles"];
            parseTileInstances(layer.gridTiles, gridTiles);

            levelToFill.layerInstances.push_back(layer);
        }
    }

    void LdtkLoader::parseTileInstances(std::vector<LdtkTileInstance> &arrayToFill, nlohmann::json &tileInstancesJson) {
        for (const nlohmann::json &tileInstanceJson: tileInstancesJson) {
            LdtkTileInstance tileInstance{};
            tileInstance.a = tileInstanceJson["a"];
            tileInstance.f = tileInstanceJson["f"];
            tileInstance.t = tileInstanceJson["t"];

            // - PX
            nlohmann::json pxJson = tileInstanceJson["px"];
            fillArrayData(tileInstance.px,pxJson);

            // - SRC
            nlohmann::json srcJson = tileInstanceJson["src"];
            fillArrayData(tileInstance.src, srcJson);

            arrayToFill.push_back(tileInstance);
        }
    }
}
