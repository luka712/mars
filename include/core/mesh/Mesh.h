//
// Created by lukaa on 29.11.2024
//

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstdint>
#include <memory>
#include "core/buffers/AVertexBuffer.h"
#include "core/buffers/AIndexBuffer.h"



namespace mars {

    class Framework;

    //! The mesh class.
    class Mesh {
    public:
        Mesh();

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

        //! Initialize the mesh.
        virtual void initialize();

        //! Apply the changes to the mesh.
        virtual void applyChanges();

    private:
        Framework& framework;
        std::vector<float> positions;
        std::vector<uint16_t> indices;
        std::vector<float> colors;
        std::vector<float> textureCoordinates;
        std::vector<float> normals;
    };
}

#endif //MESH_H
