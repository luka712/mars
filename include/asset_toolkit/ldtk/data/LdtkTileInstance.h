//
// Created by Erkapic Luka on 2.4.2025.
//

#ifndef LDTK_TILE_INSTANCE_H
#define LDTK_TILE_INSTANCE_H

#include <cstdint>

namespace asset_toolkit {
    //! This structure represents a single tile from a given Tile set.
    struct LdtkTileInstance {
        //! Alpha/opacity of the tile (0-1, defaults to 1).
        float a;

        //! "Flip bits", a 2-bits integer to represent the mirror transformations of the tile.
        //! - Bit 0 = X flip
        //! - Bit 1 = Y flip
        //! Examples: f=0 (no flip), f=1 (X flip only), f=2 (Y flip only), f=3 (both flips)
        int32_t f;

        //! Pixel coordinates of the tile in the layer ([x,y] format). Don't forget optional layer offsets, if they exist!
        int32_t px[2];

        //! Pixel coordinates of the tile in the tile set ([x,y] format).
        int32_t src[2];

        //! The Tile ID in the corresponding tile set.
        int32_t t;

    };
}

#endif // LDTK_TILE_INSTANCE_H
