//
// Created by luka on 04/01/25.
//

#ifndef SPRITEFONTCHARACTER_H
#define SPRITEFONTCHARACTER_H

#include "core/math/Quad.h"

namespace mars {

    //! The sprite font character or character in a sprite font.
    class SpriteFontCharacter {

        public:
        //! The constructor.
        //! @param character - The character.
        //! @param textureCoords - The texture coordinagtes.
        //! @param size - The size of character.
        //! @param offset - The offset of character.
        //! @param advance - The offset of the character to the baseline.
        SpriteFontCharacter(
            char character,
            Quad textureCoords,
            glm::vec2 size,
            glm::vec2 offset,
            float advance
            );

        //! Gets the character.
        //! @return The character
        [[nodiscard]] char getCharacter() const { return character; }

        //! Gets the texture coordinates.
        //! @return The texture coordinates.
        [[nodiscard]] Quad getTextureCoords() const { return textureCoords; }

        //! Gets the size of the character.
        //! @return The size.
        [[nodiscard]] glm::vec2 getSize() const { return size; }

        //! Gets the offset of the character.
        //! @return The offset.
        [[nodiscard]] glm::vec2 getOffset() const { return offset; }

        //! Gets the advance of the character to the baseline.
        //! @return The advance.
        [[nodiscard]] float getAdvance() const { return advance; }
    private:
        char character;
        Quad textureCoords;
        glm::vec2 size{};
        glm::vec2 offset{};
        float advance;

    };
}





#endif //SPRITEFONTCHARACTER_H
