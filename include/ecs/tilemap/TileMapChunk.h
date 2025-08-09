//
// Created by lukaa on 10.1.2025..
//

#ifndef TILEMAPCHUNK_H
#define TILEMAPCHUNK_H

#include <core/math/Rect.h>

#include "core/math/Quad.h"
#include "core/texture/a_texture2d.h"

namespace mars {
    //! The class that represents a chunk of the tile map.
    class TileMapChunk {
    public:
        //! The constructor for chunk of the tile map.
        //! @param x The x position of the chunk.
        //! @param y The y position of the chunk.
        //! @param sourceRect Defines source part of texture.
        TileMapChunk(int32_t x, int32_t y, Rect sourceRect);

        //! The x index for position on the map.
        //! @return The x index.
        [[nodiscard]] int32_t getX() const { return x; }

        //! The y index for position on the map.
        //! @return The y index.
        [[nodiscard]] int32_t getY() const { return y; }

        //! The source part of texture.
        //! @return The source rect.
        [[nodiscard]] Rect getSourceRect() const { return sourceRect; }

        //! If marked as empty, this chunk will not be rendered.
        bool empty;

    private:
        int32_t x;
        int32_t y;
        Rect sourceRect;
    };
}


#endif //TILEMAPCHUNK_H
