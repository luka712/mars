//
// Created by lukaa on 29.11.2024
//

#ifndef MESH_H
#define MESH_H

#include <vector>
#include <cstdint>

namespace mars {
  class Mesh {
  public:
    //! The position points of the mesh.
    std::vector<float> positions;

    //! The indices of the mesh.
    std::vector<uint16_t> indices;

    //! The colors for points of the mesh.
    std::vector<float> colors;

    //! The texture coordinates of the mesh.
    std::vector<float> textureCoordinates;

    //! Initialize the mesh.
    virtual void initialize();

    //! Apply the changes to the mesh.
    virtual void applyChanges();
  };
}

#endif //MESH_H
