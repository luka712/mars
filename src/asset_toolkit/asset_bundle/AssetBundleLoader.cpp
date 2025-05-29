#include <fstream>
#include <stdexcept>
#include "asset_toolkit/asset_bundle/AssetBundleLoader.h"
#include <nlohmann/json.hpp>

namespace asset_toolkit {

    std::shared_ptr<AssetBundle> AssetBundleLoader::load(const std::string &path) {

        if (bundles.contains(path)) {
            return bundles[path];
        }

        // Try to load the asset bundle from the file.
        std::fstream file;
        file.open(path, std::ios::in);
        if (!file.is_open()) {
            throw std::runtime_error("Could not open file " + path);
        }

        // Load the JSON data from the file.
        nlohmann::json json;
        file >> json;
        file.close();

        auto bundle = std::make_shared<AssetBundle>();
        parseAssetBundle(*bundle, json);
        return bundle;
    }

    void AssetBundleLoader::unloadBundle(const std::string &path) {
        if (bundles.contains(path)) {
            bundles.erase(path);
        }
    }

    void AssetBundleLoader::parseAssetBundle(AssetBundle &bundleToFill, nlohmann::json &bundleJson) {

        // SPRITE SHEETS
        nlohmann::json spriteSheetsJson = bundleJson["sprite_sheets"];
        parseSpriteSheets(bundleToFill.spriteSheets, spriteSheetsJson);

    }

    void AssetBundleLoader::parseSpriteSheets(std::vector<SpriteSheet> &arrayToFill, nlohmann::json &spriteSheetsJson) {
        for (auto& spriteSheetJson : spriteSheetsJson) {
            SpriteSheet spriteSheet;
            spriteSheet.spriteSheetName = spriteSheetJson["sprite_sheet_name"];
            spriteSheet.spriteSheetImage = spriteSheetJson["sprite_sheet_image"];

            // SPRITES
            nlohmann::json spritesJson = spriteSheetJson["sprites"];
            parseSprites(spriteSheet.sprites, spritesJson);

            arrayToFill.push_back(spriteSheet);
        }
    }

    void AssetBundleLoader::parseSprites(std::vector<Sprite> &arrayToFill, nlohmann::json &spritesJson) {
        for (auto& spriteJson : spritesJson) {
            Sprite sprite;
            sprite.spriteName = spriteJson["sprite_name"];

            // SOURCE RECTANGLE
            nlohmann::json sourceRectangleJson = spriteJson["source_rect"];
            parseRectangle(sprite.sourceRectangle, sourceRectangleJson);

            arrayToFill.push_back(sprite);
        }
    }

    void AssetBundleLoader::parseRectangle(Rectangle &rectangle, nlohmann::json &rectangleJson) {
        rectangle.x = rectangleJson["x"];
        rectangle.y = rectangleJson["y"];
        rectangle.width = rectangleJson["width"];
        rectangle.height = rectangleJson["height"];
    }
}
