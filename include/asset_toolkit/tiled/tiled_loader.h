
#ifndef TILED_LOADER_H
#define TILED_LOADER_H

#include <tmxlite/Map.hpp>
#include <tmxlite/Tileset.hpp>
#include <tmxlite/TileLayer.hpp>
#include <functional>
#include "asset_toolkit/common/Rectangle.h"


namespace asset_toolkit {

	//! The information about loaded tile.
	struct TileInfo 
	{
		//! The source rectangle in sprite sheet.
		Rectangle sourceRectangle;

		//! The destination rectangle in the world.
		Rectangle destinationRectangle;

		//! The name of the texture (sprite sheet).
		std::string textureName;
	};

	//! TiledLoader is responsible for loading and parsing Tiled map files.
	class TiledLoader 
	{
	private:
		std::vector<std::function<void(const TileInfo&)>> tileLoadedCallbacks;

		void checkTile(
			const tmx::Tileset& tileset, 
			const tmx::TileLayer::Chunk& chunk, 
			uint32_t globalTileId, int32_t index);

	public:
		void onTileLoaded(const std::function<void(const TileInfo&)>& callback);
		void load(const std::string& filePath);

	};

}

#endif //TILED_LOADER_H
