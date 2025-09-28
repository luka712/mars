//
// Created by Erkapic Luka on 28.9.2025.
//

#ifndef DX11_SPRITE_RENDER_PIPELINE_H
#define DX11_SPRITE_RENDER_PIPELINE_H

#ifdef _WIN32

#include <core/renderer/enums.h>
#include "dx11/dx11.h"
#include "core/pipelines/sprite/ASpriteRenderPipeline.h"
#include "dx11/renderer/dx11_renderer.h"
#include "core/camera/core/OrthographicCamera.h"
#include "dx11/texture/dx11_texture2d.h"

namespace mars {
    class Framework;

    //! The DX11 implementation of @ref ASpriteRenderPipeline.
    class DX11SpriteRenderPipeline : public ASpriteRenderPipeline {
    public:
        //! The constructor.
        //! @param framework The framework.
        //! @param camera The orthographic camera.
        //! @param culling The culling, by default it is `Culling::Back`.
        DX11SpriteRenderPipeline(
            Framework &framework,
            OrthographicCamera *camera,
            Culling culling = Culling::Back);

        //! @inheritDoc
        ATexture2D* getSpriteTexture() override;

        //! @inheritDoc
        void setSpriteTexture(ATexture2D* spriteTexture) override;

        //! @inheritDoc
        void render(
            AVertexBuffer *vertexBuffer,
            AIndexBuffer *indexBuffer,
            uint32_t indicesCount,
            uint32_t indicesOffset) override;

        //! @inheritDoc
        void destroy() override;

    private:
        Framework &framework;
        DX11Renderer *renderer;
        OrthographicCamera *camera;
        Culling culling;

		ComPtr<ID3D11Device> device;
		ComPtr<ID3D11DeviceContext> context;
		ComPtr<ID3D11VertexShader> vertexShader;
		ComPtr<ID3D11PixelShader> pixelShader;
		ComPtr<ID3D11InputLayout> inputLayout;

        DX11Texture2D* texture = nullptr;

        void createInputAndShaders();
    };
}

#endif // _WIN32

#endif //DX11_SPRITE_RENDER_PIPELINE_H

