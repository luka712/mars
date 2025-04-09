#include <catch.h>
#include "asset_toolkit/asset_bundle/AssetBundleLoader.h"

using namespace asset_toolkit;

//! Tests if trying to load non-existing file fails.
bool test_trying_to_load_non_existing_json_throws() {
    try {
        AssetBundleLoader loader;
        const auto result = loader.load("does_not_exists.json");
    }
    catch (const std::runtime_error&) {
        return true;
    }

    return false;
}

bool test_trying_to_load_existing_json_does_not_throw() {
    try {
        AssetBundleLoader loader;
        const auto result = loader.load("content/asset_bundles/components/components.json");
    }
    catch (const std::runtime_error&) {
        return false;
    }

    return true;
}

bool test_sprite_sheets_exist() {
    AssetBundleLoader loader;
    const auto result = loader.load("content/asset_bundles/components/components.json");

    return !result->spriteSheets.empty();
}

bool test_sprite_sheets_sprites_exist() {
    AssetBundleLoader loader;
    const auto result = loader.load("content/asset_bundles/components/components.json");

    return !result->spriteSheets[0].sprites.empty();
}

TEST_CASE( "Asset Bundle loading.", "[test_trying_to_load_non_existing_json_throws, test_trying_to_load_existing_json_does_not_throw]" ) {
    REQUIRE( test_trying_to_load_non_existing_json_throws() == true );
    REQUIRE( test_trying_to_load_existing_json_does_not_throw() == true );
}

TEST_CASE( "Asset Bundle Format is correct.", "[test_sprite_sheets_exist, test_sprite_sheets_sprites_exist]" ) {
    REQUIRE( test_sprite_sheets_exist() == true );
    REQUIRE( test_sprite_sheets_sprites_exist() == true );
}
