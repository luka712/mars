//
// Created by Erkapic Luka on 9.8.2025.
//

#if _WIN32

#ifndef DX11_TEXTURE_TEST_PIPELINE_H
#define DX11_TEXTURE_TEST_PIPELINE_H

#include "core/pipelines/test/a_texture_test_pipeline.h"
#include "dx11/dx11.h"
#include "dx11/renderer/dx11_renderer.h"
#include "dx11/buffers/dx11_vertex_buffer.h"
#include "dx11/texture/dx11_texture2d.h"

namespace mars
{
    class Framework;

    //! A D3D11 implementation of the texture test pipeline.
    class DX11TextureTestPipeline : public ATextureTestPipeline
    {
    public:
        //! Constructor for the DX11TextureTestPipeline.
        //! @param framework The framework to use for rendering.
        DX11TextureTestPipeline(Framework& framework);

        //! @copydoc ATextureTestPipeline::getTexture2D
        ATexture2D* getTexture2D() override { return texture; }

        //! @copydoc ATextureTestPipeline::setTexture2D
        void setTexture2D(ATexture2D* texture) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer) override;

        //! @copydoc ATextureTestPipeline::render
        void render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer) override;

        void destroy() override;
    private:
        Framework& framework;

        DX11Renderer& renderer;
        DX11Texture2D* texture;

        ComPtr<ID3D11Device> device;
        ComPtr<ID3D11DeviceContext> deviceContext;

        ComPtr<ID3D11VertexShader> vertexShader;
        ComPtr<ID3D11PixelShader> pixelShader;
        ComPtr<ID3D11InputLayout> inputLayout;


        void createShaders(ComPtr<ID3D10Blob> vertexBlob);
        void createInputLayout(ComPtr<ID3D10Blob> vertexBlob);
    };
}

#endif //DX11_TEXTURE_TEST_PIPELINE_H

#endif