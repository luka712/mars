//
// Created by lukaa on 21.12.2024.
//

#ifndef TEXTURE2D_H
#define TEXTURE2D_H

#include <cstdint>
#include <string>
#include "core/content/AContent.h"

namespace mars {
    //! The Texture2D class.
    //! Represents a 2D texture.
    class ATexture2D : public AContent {
    public:

        //! Get the width of the texture.
        //! @return The width of the texture.
        [[nodiscard]] uint32_t getWidth() const { return width; }

        //! Get the height of the texture.
        //! @return The height of the texture.
        [[nodiscard]] uint32_t getHeight() const { return height; }

        //! Gets the label of the texture.
        //! @return The label of the texture.
        [[nodiscard]] std::string getLabel() const { return label; }

        //! Destroy the texture.
        //! Releases the resources.
        virtual void destroy() = 0;

        //! Print and return information about Texture2D.
        //! @returns Information about Texture2D.
        virtual std::string printInfo() = 0;

    protected:
        std::string label;
        uint32_t width = 0, height = 0;
    };
}


#endif //TEXTURE2D_H
