#include <catch.h>
#include <asset_toolkit/tiled/tiled_loader.h>

using namespace asset_toolkit;

//! Tests if trying to load non-existing file fails.
bool test_tile_loader_callback() {

	bool tileLoadedCalled = false;
	TiledLoader loader;
	loader.onTileLoaded([&](const TileInfo& info)
		{
			tileLoadedCalled = true;
		});
	loader.load("content/tiled/DinoRunner.tmx");
	return tileLoadedCalled;
}

TEST_CASE("Tiled Loader", "[test_tile_loader_callback]") {
	REQUIRE(test_tile_loader_callback());
}

