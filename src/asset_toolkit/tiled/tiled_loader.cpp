#include "asset_toolkit/tiled/tiled_loader.h"


namespace asset_toolkit
{
	void TiledLoader::checkTile(const tmx::Tileset& tileset, const tmx::TileLayer::Chunk& chunk, uint32_t globalTileId, int32_t index)
	{
		uint32_t tileSetStart = tileset.getFirstGID();
		uint32_t tileSetEnd = tileSetStart + tileset.getTileCount();

		// It's valid
		if(globalTileId >= tileSetStart && globalTileId < tileSetEnd)
		{
			std::string imageName = tileset.getImagePath();

			int32_t localId = globalTileId - tileSetStart;

			int32_t columns = tileset.getColumnCount();
			int32_t tw = tileset.getTileSize().x;
			int32_t th = tileset.getTileSize().y;

			int32_t tileX = (localId % columns);
			int32_t tileY = (localId / columns);

			// Pixel position inside the tile set image
			int32_t px = tileX * tw;
			int32_t py = tileY * th;

			float worldX = (index % chunk.size.x) * tw;
			float worldY = (index / chunk.size.x) * th;

			TileInfo info;
			info.sourceRectangle = Rectangle(px, py, tw, th);
			info.destinationRectangle = Rectangle(worldX, worldY, tw, th);
			info.textureName = imageName;
			for (auto& callback : tileLoadedCallbacks)
			{
				callback(info);
			}
		}
	}

	void TiledLoader::onTileLoaded(const std::function<void(const TileInfo&)>& callback)
	{
		tileLoadedCallbacks.push_back(callback);
	}

	void TiledLoader::load(const std::string& filePath)
	{
		tmx::Map map;
		if (!map.load(filePath))
		{
			throw std::runtime_error("Failed to load Tiled map: " + filePath);
		}

		// Process the map data as needed
		for (auto& baseLayer : map.getLayers())
		{
			// If it's a tile layer
			if (baseLayer->getType() == tmx::Layer::Type::Tile)
			{
				tmx::TileLayer& tileLayer = dynamic_cast<tmx::TileLayer&>(*baseLayer.get());

				for (auto& chunk : tileLayer.getChunks())
				{
					int index = -1;

					for (auto& tile : chunk.tiles)
					{
						index++;

						for (auto& tileset : map.getTilesets())
						{
							checkTile(tileset, chunk, tile.ID, index);
						}
					}
				}
			}

		}
	}
}