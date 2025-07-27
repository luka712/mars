//
// Created by Erkapic Luka on 22.12.2024.
//

#ifndef TEXTURE_FACTORY_H
#define TEXTURE_FACTORY_H

#include <string>
#include <memory>
#include "core/texture/texture2d.h"
#include "core/texture/TextureEnums.h"

namespace mars {
    class Framework;

    //! The TextureFactory class.
    class TextureFactory {
    public:
        //! Construct a new TextureFactory object.
        //! @param framework The framework.
        explicit TextureFactory(Framework &framework);

        //! Create a new texture from the specified file.
        //! @param filePath The path to the file.
        //! @param usage The usage of the texture. By default, it is set to CopyDst_TextureBinding.
        //! @param label The label of the texture. By default, it is set to an empty string.
        //! @return The texture.
        [[nodiscard]] std::shared_ptr<Texture2D> createTextureFromImageFile(
            const std::string &filePath,
            TextureUsage usage = TextureUsage::CopyDst_TextureBinding,
            const std::string &label = "") const;

        //! Create a new empty texture.
        //! @param width The width of the texture.
        //! @param height The height of the texture.
        //! @param defaultColor The default color of the texture. By default, it is set to white.
        //! @param usage The usage of the texture. By default, it is set to CopyDst_TextureBinding.
        //! @param label The label of the texture. By default, it is set to an empty string.
        //! @return The texture.
        [[nodiscard]] std::shared_ptr<Texture2D> createEmpty(
            uint32_t width,
            uint32_t height,
            Color defaultColor = Color::white(),
            TextureUsage usage = TextureUsage::CopyDst_TextureBinding,
            const std::string &label = "") const;

    private:
        Framework &framework;
    };
}


#endif //TEXTURE_FACTORY_H
