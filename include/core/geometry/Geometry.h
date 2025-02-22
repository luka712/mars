//
// Created by Luka Erkapic on 22.2.2025.
//

#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cstdint>
#include <vector>
#include <core/renderer/enums.h>

namespace mars {
    //! The geometry format.
    enum class GeometryFormat {
        //! Geometry format where:
        //! - first 3 floats are reserved for vertex position,
        //! - next 4 floats are reserved for color,
        //! - last 2 floats are reserved for texture coordinates.
        Pos3_Color4_TextureCoords2,

        //! Geometry format where:
        //! - first 3 floats are reserved for vertex position,
        //! - next 4 floats are reserved for color,
        //! - next 2 floats are reserved for texture coordinates.
        //! - last 3 floats are reserved for normals.
        Pos3_Color4_TextureCoords2_Normal3,

        //! Geometry format where:
        //! - first 3 floats are reserved for vertex position,
        //! - next 4 floats are reserved for color,
        //! - next 2 floats are reserved for texture coordinates,
        //! - last 3 floats are reserved for normals.
        //! When aligned, the vertex format is aligned to 4 floats.
        //! Meaning:
        //! - first 4 floats are reserved for vertex position, but only 3 are used,
        //! - next 4 floats are reserved for color,
        //! - next 4 floats are reserved for texture coordinates, but only 2 are used.
        Pos3_Color4_TextureCoords2_Aligned
    };

    class Geometry {
    public:
        //! The position vertex format of the geometry.
        VertexFormat positionsFormat;

        //! The positions of the geometry.
        std::vector<float> positions;

        //! The color vertex format of the geometry.
        VertexFormat colorFormat;

        //! The colors of the geometry.
        std::vector<float> colors;

        //! The texture coordinates vertex format of the geometry.
        VertexFormat textureCoordsFormat;

        //! The texture coordinates of the geometry.
        std::vector<float> textureCoords;

        //! The normals vertex format of the geometry.
        VertexFormat normalsFormat;

        //! The normals of the geometry.
        std::vector<float> normals;

        //! The indices of the geometry.
        std::vector<uint16_t> indices;

        //! Converts data of this geometry to interleaved buffer format.
        //! @param format The format of the geometry.
        //! @return The interleaved data of the geometry.
        std::vector<float> toInterleaved(GeometryFormat format);

    private:

        //! Pushes the geometry data for index to the destination array.
        //! @param index The index of the vertex.
        //! @param source The source array.
        //! @param sourceFormat The source format.
        //! @param destination The destination array.
        //! @param destinationFormat The destination format.
        void pushFormat(
            int32_t index,
            const std::vector<float> &source,
            VertexFormat sourceFormat,
            std::vector<float> &destination,
            VertexFormat destinationFormat);
    };
}

#endif //GEOMETRY_H
