//
// Created by luka on 04/01/25.
//

#include "core/fonts/SpriteFontCharacter.h"

namespace mars {

    SpriteFontCharacter::SpriteFontCharacter(
        const char character,
        const Quad textureCoords,
        const glm::vec2 size,
        const glm::vec2 offset,
        const float advance)
    {
        this->character = character;
        this->textureCoords = textureCoords;
        this->advance = advance;
        this->size = size;
        this->offset = offset;
    }

}
