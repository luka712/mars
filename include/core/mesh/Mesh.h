//
// Created by lukaa on 29.11.2024
//

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstdint>
#include <memory>
#include "core/geometry/Geometry.h"
#include "core/buffers/a_vertex_buffer.h"
#include "core/buffers/AIndexBuffer.h"

namespace mars {

    class Framework;

    //! The mesh class.
    class Mesh {
    public:
        virtual ~Mesh() = default;

        //! Construct a new Mesh object.
        //! @param framework The framework.
        explicit Mesh(Framework& framework);

        //! Gets the positions of the mesh.
        //! @return The positions of the mesh.
        std::vector<float> &getPositions() { return positions; }

        //! Gets the indices of the mesh.
        //! @return The indices of the mesh.
        std::vector<uint16_t> &getIndices() { return indices; }

        //! Gets the colors of the mesh.
        //! @return The colors of the mesh.
        std::vector<float>& getColors() { return colors; }

        //! Gets the texture coordinates of the mesh.
        //! @return The texture coordinates of the mesh.
        std::vector<float>& getTextureCoords() { return textureCoordinates; }

        //! Gets the normals of the mesh.
        //! @return The normals of the mesh.
        std::vector<float>& getNormals() { return normals; }

        //! Gets the vertex buffer.
        //! @return The vertex buffer.
        [[nodiscard]] AVertexBuffer& getVertexBuffer() const { return *vertexBuffer; }

        //! Gets the index buffer.
        //! @return The index buffer.
        [[nodiscard]] AIndexBuffer& getIndexBuffer() const { return *indexBuffer; }

        //! Initialize the mesh.
        virtual void initialize();

        //! Sets the mesh from the geometry.
        //! This created mesh vertex and index buffers from the geometry.
        //! @ref{positions}, @ref{colors}, @ref{textureCoordinates} and @ref{normals} are ignored.
        //! @param geometry The geometry.
        //! @param format The geometry format.
        void setGeometry(const Geometry& geometry, GeometryFormat format);

        //! Apply the changes to the mesh.
        virtual void applyChanges();

        //! Destroy the mesh.
        virtual void destroy();

    protected:
        Framework& framework;
        std::vector<float> vertexData;
        BufferUsage bufferUsage = BufferUsage::Vertex;
        std::shared_ptr<AVertexBuffer> vertexBuffer;
        std::shared_ptr<AIndexBuffer> indexBuffer;
        std::vector<float> positions;
        std::vector<uint16_t> indices;
        std::vector<float> colors;
        std::vector<float> textureCoordinates;
        std::vector<float> normals;

        void fillColors(size_t& vertexIndex, size_t& colorIndex, const std::vector<float>& colors);
    };
}

#endif //MESH_H
