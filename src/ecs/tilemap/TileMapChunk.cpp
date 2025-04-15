//
// Created by lukaa on 10.1.2025..
//

#include "ecs/tilemap/TileMapChunk.h"

namespace mars {
    TileMapChunk::TileMapChunk(const int32_t x, const int32_t y, const Rect sourceRect)
        : x(x), y(y), sourceRect(sourceRect){
        empty = false;
    }
}
