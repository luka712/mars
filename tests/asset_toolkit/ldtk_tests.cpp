#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file
#include <catch.h>
#include "asset_toolkit/ldtk/LdtkLoader.h"

using namespace asset_toolkit;

//! Tests if trying to load non-existing file fails.
bool test_failed_to_load_ldtk() {
    LdtkLoader loader;
    const auto result = loader.load("does_not_exists.ldtk");
    return result.isSuccess;
}

//! Tests if trying to load existing file succeeds.
bool test_loaded_ldtk() {
      LdtkLoader loader;
      const auto result = loader.load("content/ldtk/basic_map.ldtk");
      return result.isSuccess;
}

//! Tests if the root is loaded.
bool test_root_is_loaded() {
    LdtkLoader loader;
    const auto result = loader.load("content/ldtk/basic_map.ldtk");
    return result.value.jsonVersion == "1.5.3" &&
        result.value.iid != "";
}

bool test_levels_are_loaded() {
    LdtkLoader loader;
    const auto result = loader.load("content/ldtk/basic_map.ldtk");

    return result.value.levels.size() > 0;
}

bool test_layer_instances_are_loaded() {
    LdtkLoader loader;
    const auto result = loader.load("content/ldtk/basic_map.ldtk");

    return result.value.levels[0].layerInstances.size() > 0;
}

bool test_auto_layer_tiles_are_loaded() {
    LdtkLoader loader;
    const auto result = loader.load("content/ldtk/basic_map.ldtk");

    return result.value.levels[0].layerInstances[0].autoLayerTiles.size() > 0;
}

TEST_CASE( "Ldtk loading.", "[test_failed_to_load_ldtk, test_loaded_ldtk]" ) {
    REQUIRE( test_failed_to_load_ldtk() == false );
    REQUIRE(  test_loaded_ldtk() );
}

TEST_CASE( "Ldtk Format is correct.", "[test_root_is_loaded, test_levels_are_loaded, test_layer_instances_are_loaded, test_auto_layer_tiles_are_loaded]" ) {
    REQUIRE( test_root_is_loaded());
    REQUIRE( test_levels_are_loaded());
    REQUIRE( test_layer_instances_are_loaded());
    REQUIRE( test_auto_layer_tiles_are_loaded());
}
