

#ifndef TILEMANAGER_H
#define TILEMANAGER_H

#include "tile/Tile.h"
#include <core/content/ContentManager.h>
#include <core/sprite/SpriteBatch.h>
#include <asset_toolkit/tiled/tiled_loader.h>


class TileManager {
public:
	//! Initialize the tile manager by loading all tile types
	//! @param contentManager The content manager to load tile types from
	static void Initialize(mars::ContentManager& contentManager);

	//! Draw all tiles in the tile map
	//! @param spriteBatch The sprite batch to draw tiles with
	static void Draw(mars::SpriteBatch& spriteBatch);
private:
	static asset_toolkit::TiledLoader loader;
	static std::map < std::string, std::shared_ptr<mars::ATexture2D>> tileTextures;
	static std::vector<Tile*> tiles;
};



#endif //TILEMANAGER_H
