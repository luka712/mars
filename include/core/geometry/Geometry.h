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
        //! Gets the vertex count.
        //! @return The vertex count.
        [[nodiscard]] uint32_t getVertexCount() const { return vertexCount; }

        //! Sets the vertex count.
        //! @param vertexCount The vertex count.
        void setVertexCount(const uint32_t vertexCount) { this->vertexCount = vertexCount; }

        //! Gets the indices of the geometry.
        //! @return The indices of the geometry.
        [[nodiscard]] const std::vector<uint16_t>& getIndices() const { return indices; }

        //! Sets the indices of the geometry.
        //! @param indices The indices of the geometry.
        void setIndices(const std::vector<uint16_t>& indices) { this->indices = indices; }

        //! Gets the positions of the geometry.
        //! @return The positions of the geometry.
        [[nodiscard]] const std::vector<float>& getPositions() const { return positions; }

        //! Sets the positions of the geometry.
        //! @param positions The positions of the geometry.
        void setPositions(const std::vector<float>& positions) { this->positions = positions; }

        //! Gets the colors of the geometry.
        //! @return The colors of the geometry.
        [[nodiscard]] const std::vector<float>& getColors() const { return colors; }

        //! Sets the colors of the geometry.
        //! @param colors The colors of the geometry.
        void setColors(const std::vector<float>& colors) { this->colors = colors; }

        //! Gets the texture coordinates of the geometry.
        //! @return The texture coordinates of the geometry.
        [[nodiscard]] const std::vector<float>& getTextureCoords() const { return textureCoords; }

        //! Sets the texture coordinates of the geometry.
        //! @param textureCoords The texture coordinates of the geometry.
        void setTextureCoords(const std::vector<float>& textureCoords) { this->textureCoords = textureCoords; }

        //! Gets the normals of the geometry.
        //! @return The normals of the geometry.
        [[nodiscard]] const std::vector<float>& getNormals() const { return normals; }

        //! Sets the normals of the geometry.
        //! @param normals The normals of the geometry.
        void setNormals(const std::vector<float>& normals) { this->normals = normals; }

        //! The position vertex format of the geometry.
        VertexFormat positionsFormat;

        //! The color vertex format of the geometry.
        VertexFormat colorFormat;


        //! The texture coordinates vertex format of the geometry.
        VertexFormat textureCoordsFormat;


        //! The normals vertex format of the geometry.
        VertexFormat normalsFormat;




        //! Converts data of this geometry to interleaved buffer format.
        //! @param format The format of the geometry.
        //! @return The interleaved data of the geometry.
        [[nodiscard]] std::vector<float> toInterleaved(GeometryFormat format) const;

    private:
        uint32_t vertexCount = 0;
        std::vector<uint16_t> indices;
        std::vector<float> positions;
        std::vector<float> colors;
        std::vector<float> textureCoords;
        std::vector<float> normals;

        //! Pushes the geometry data for index to the destination array.
        //! @param index The index of the vertex.
        //! @param source The source array.
        //! @param sourceFormat The source format.
        //! @param destination The destination array.
        //! @param destinationFormat The destination format.
        static void pushFormat(
            int32_t index,
            const std::vector<float> &source,
            VertexFormat sourceFormat,
            std::vector<float> &destination,
            VertexFormat destinationFormat) ;
    };
}

#endif //GEOMETRY_H
