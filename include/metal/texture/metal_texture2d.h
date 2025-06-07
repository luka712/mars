//
// Created by Luka Erkapic on 07.06.25.
//

#if __APPLE__

#ifndef METAL_TEXTURE2D_H
#define METAL_TEXTURE2D_H

#include <string>
#include "metal/metal.h"
#include "core/log/Logger.h"
#include "core/texture/Texture2D.h"
#include "core/data/ImageData.h"
#include "metal/renderer/metal_renderer.h"

namespace mars
{
    class Framework;

    //! The Metal implementation of the Texture2D.
    class MetalTexture2D : public Texture2D {
    public:
        //! Construct a new  MetalTexture2D object.
        //! @param framework The framework.
        //! @param imageData The image data.
        //! @param label The label.
        MetalTexture2D(Framework& framework,
            const ImageData& imageData,
            const std::string& label = "");

        //! Get the texture.
        [[nodiscard]] MTL::Texture* getTexture() const { return texture; }

        //! @inheritDoc
        void destroy() override;

        //! @inheritDoc
        std::string printInfo() override;
    private:
        Framework& framework;
        MetalRenderer& renderer;
        Logger& logger;
        //! The OpenGL texture.
        MTL::Texture* texture;
    };

    //! Converts the @ref Texture2D to the @ref MetalTexture2D.
    //! @param texture The @ref Texture2D
    //! @returns The MetalTexture2D.
    MetalTexture2D* asMetalTexture(Texture2D* texture);
}

#endif //METAL_TEXTURE2D_H

#endif