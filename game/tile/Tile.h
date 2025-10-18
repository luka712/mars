#ifndef TILE_H
#define TILE_H

#include <core/math/Rect.h>
#include <core/texture/a_texture2d.h>
#include <memory>

struct Tile {
	
	//! The draw rectangle of the tile in the tileset texture.
	mars::Rect rectangle;

	//! The source rectangle of the tile in the world.
	mars::Rect sourceRectangle;

	//! The texture of the tile.
	std::shared_ptr<mars::ATexture2D> texture;

};



#endif //TILE_H
