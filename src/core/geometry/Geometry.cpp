//
// Created by Luka Erkapic on 22.2.2025.
//

#include "core/geometry/Geometry.h"

namespace mars {
    std::vector<float> Geometry::toInterleaved(GeometryFormat format) {
        std::vector<float> interleavedData;

        switch (format)
        {
            case GeometryFormat::Pos3_Color4_TextureCoords2:
            {
                const size_t count = positions.size() / 3;

                for (int i = 0; i < count; i++)
                {
                    pushFormat(i, positions, VertexFormat::Float32x3, interleavedData, VertexFormat::Float32x3);
                    pushFormat(i, colors, VertexFormat::Float32x4, interleavedData, VertexFormat::Float32x4);
                    pushFormat(i, textureCoords, VertexFormat::Float32x2, interleavedData, VertexFormat::Float32x2);
                }
                break;
            }
            case GeometryFormat::Pos3_Color4_TextureCoords2_Normal3:
            {
                  const size_t count = positions.size() / 3;

                for (int i = 0; i < count; i++)
                {
                    pushFormat(i, positions, VertexFormat::Float32x3, interleavedData, VertexFormat::Float32x3);
                    pushFormat(i, colors, VertexFormat::Float32x4, interleavedData, VertexFormat::Float32x4);
                    pushFormat(i, textureCoords, VertexFormat::Float32x2, interleavedData, VertexFormat::Float32x2);
                    pushFormat(i, normals, VertexFormat::Float32x3, interleavedData, VertexFormat::Float32x3);
                }
                break;
            }
            case GeometryFormat::Pos3_Color4_TextureCoords2_Aligned:
            {
               const size_t count = positions.size() / 3;

                for (int i = 0; i < count; i++)
                {
                    pushFormat(i, positions, VertexFormat::Float32x3, interleavedData, VertexFormat::Float32x4);
                    pushFormat(i, colors, VertexFormat::Float32x4, interleavedData, VertexFormat::Float32x4);
                    pushFormat(i, textureCoords, VertexFormat::Float32x2, interleavedData, VertexFormat::Float32x4);
                }
                break;
            }
        }


        return interleavedData;
    }

    void Geometry::pushFormat(const int32_t index,
                              const std::vector<float> &source,
                              const VertexFormat sourceFormat,
                              std::vector<float> &destination,
                              const VertexFormat destinationFormat) {

        // This simply takes source format and pushes new vertices to destination format.
        // If source format is less than destination, 0 is being push in its place.
        float _0 = 0;
        float _1 = 0;
        float _2 = 0;
        float _3 = 0;

        if (sourceFormat == VertexFormat::Float32x1)
        {
            _0 = source[index];
        }
        else if (sourceFormat == VertexFormat::Float32x2)
        {
            _0 = source[index * 2];
            _1 = source[index * 2 + 1];
        }
        else if (sourceFormat == VertexFormat::Float32x3)
        {
            _0 = source[index * 3];
            _1 = source[index * 3 + 1];
            _2 = source[index * 3 + 2];
        }
        else if (sourceFormat == VertexFormat::Float32x4)
        {
            _0 = source[index * 4];
            _1 = source[index * 4 + 1];
            _2 = source[index * 4 + 2];
            _3 = source[index * 4 + 3];
        }

        destination.push_back(_0);
        if (destinationFormat >= VertexFormat::Float32x2)
        {
            destination.push_back(_1);
        }

        if (destinationFormat >= VertexFormat::Float32x3)
        {
            destination.push_back(_2);
        }

        if (destinationFormat >= VertexFormat::Float32x4)
        {
            destination.push_back(_3);
        }
    }

}
