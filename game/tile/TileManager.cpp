#include "tile/TileManager.h"
#include <iostream>

asset_toolkit::TiledLoader TileManager::loader;
std::map < std::string, std::shared_ptr<mars::ATexture2D>> TileManager::tileTextures;
std::vector<Tile*> TileManager::tiles;

void TileManager::Initialize(mars::ContentManager& contentManager)
{
	TileManager::tileTextures.emplace("content/tiled/Tile1x1.png", std::move(contentManager.load<mars::ATexture2D>("tiled/Tile1x1.png", "tile1x1")));
	TileManager::tileTextures.emplace("content/tiled/Tile2x1.png", std::move(contentManager.load<mars::ATexture2D>("tiled/Tile2x1.png", "tile2x1")));
	TileManager::tileTextures.emplace("content/tiled/Tile3x1.png", std::move(contentManager.load<mars::ATexture2D>("tiled/Tile3x1.png", "tile3x1")));
	TileManager::tileTextures.emplace("content/tiled/Tile3x3.png", std::move(contentManager.load<mars::ATexture2D>("tiled/Tile3x3.png", "tile3x3")));

	loader.onTileLoaded([&](const asset_toolkit::TileInfo& tileInfo)
		{
			Tile* tile = new Tile();
			tile->texture = TileManager::tileTextures.at(tileInfo.textureName);
			tile->rectangle = mars::Rect(
				tileInfo.destinationRectangle.x,
				tileInfo.destinationRectangle.y,
				tileInfo.destinationRectangle.width,
				tileInfo.destinationRectangle.height);
			tile->sourceRectangle = mars::Rect(
				tileInfo.sourceRectangle.x,
				tileInfo.sourceRectangle.y,
				tileInfo.sourceRectangle.width,
				tileInfo.sourceRectangle.height);

			TileManager::tiles.emplace_back(tile);

		});
	loader.load("content/tiled/DinoRunner.tmx");
}

void TileManager::Draw(mars::SpriteBatch& spriteBatch)
{
	for (const Tile* tile : tiles)
	{
		std::cout << "Loaded tile with texture: " << tile->texture->getWidth() << std::endl;

		TileManager::tileTextures;

		spriteBatch.draw(
			tile->texture.get(),
			tile->rectangle,
			tile->sourceRectangle,
			mars::Color::white());
	}
}
