//
// Created by Erkapic Luka on 9.4.2025.
//

#ifndef ASSET_BUNDLE_LOADER_H
#define ASSET_BUNDLE_LOADER_H

#include "AssetBundle.h"
#include <memory>
#include <map>
#include <asset_toolkit/nlohmann/json.hpp>

namespace asset_toolkit {
    //! The loader for the asset bundle.
    class AssetBundleLoader {
    public:
        //! Load the asset bundle from a file and cache it.
        //! @param path The path to the asset bundle file.
        //! @return A shared pointer to the loaded asset bundle.
        std::shared_ptr<AssetBundle> load(const std::string &path);

        //! Unload the asset bundle from the cache.
        //! @param path The path to the asset bundle file.
        void unloadBundle(const std::string &path);

    private:
        std::map<std::string, std::shared_ptr<AssetBundle> > bundles;

        //! Parse the AssetBundle node from a string.
        //! @param bundleToFill The root to fill.
        //! @param bundleJson The root JSON.
        static void parseAssetBundle(AssetBundle& bundleToFill, nlohmann::json& bundleJson);

        //! Fill in array of sprite sheets from the JSON.
        //! @param arrayToFill The array to fill.
        //! @param spriteSheetsJson The JSON of SpriteSheet.
        static void parseSpriteSheets(std::vector<SpriteSheet>& arrayToFill, nlohmann::json& spriteSheetsJson);

        //! Fill in array of sprites from the JSON.
        //! @param arrayToFill The array to fill.
        //! @param spritesJson The JSON of Sprite.
        static void parseSprites(std::vector<Sprite>& arrayToFill, nlohmann::json& spritesJson);

        //! Fill in the rectangle from the JSON.
        //! @param rectangle The rectangle to fill.
        //! @param rectangleJson The JSON of the rectangle.
        static void parseRectangle(Rectangle& rectangle, nlohmann::json& rectangleJson);
    };
}

#endif //ASSET_BUNDLE_LOADER_H
