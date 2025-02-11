//
// Created by lukaa on 22.12.2024..
//

#ifndef TEXTUREFACTORY_H
#define TEXTUREFACTORY_H

#include <string>
#include <memory>
#include "core/texture/Texture2D.h"
#include "core/texture/TextureEnums.h"

namespace mars {

    class Framework;

    //! The TextureFactory class.
    class TextureFactory {

          public:
            //! Construct a new TextureFactory object.
            //! @param framework The framework.
            explicit TextureFactory(Framework& framework);

          //! Create a new texture from the specified file.
          //! @param filePath The path to the file.
          //! @param usage The usage of the texture. By default, it is set to CopyDst_TextureBinding.
          //! @param label The label of the texture. By default, it is set to an empty string.
          //! @return The texture.
          std::shared_ptr<Texture2D> createTextureFromImageFile(
              const std::string& filePath,
              TextureUsage usage = TextureUsage::CopyDst_TextureBinding,
              const std::string& label = "") const;

          private:
            Framework& framework;
    };

}



#endif //TEXTUREFACTORY_H
