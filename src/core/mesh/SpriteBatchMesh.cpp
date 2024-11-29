//
// Created by lukaa on 29.11.2024
//

#include "core/mesh/SpriteBatchMesh.h"
#include "Framework.h"

namespace mars {
    SpriteBatchMesh::SpriteBatchMesh(Framework &framework, size_t numberOfInstances)
        : Mesh(), maxInstances(numberOfInstances) {
        vertexData.resize(maxInstances * TOTAL_FLOATS_IN_SPRITE);
        setupIndices();
    }

    void SpriteBatchMesh::setupIndices() {
        indices.resize(maxInstances * 6);
        for (size_t i = 0; i < maxInstances; i++) {
            size_t indexInIndices = i * 6;
            size_t indicesStartIndex = i * 4;

            indices[indexInIndices] = indicesStartIndex + 2; // Bottom left.
            indices[indexInIndices + 1] = indicesStartIndex + 3; // Bottom right.
            indices[indexInIndices + 2] = indicesStartIndex + 1; // Top right.
            indices[indexInIndices + 3] = indicesStartIndex + 1; // Top right.
            indices[indexInIndices + 4] = indicesStartIndex; // Top left.
            indices[indexInIndices + 5] = indicesStartIndex + 2; // Bottom left.
        }
    }


    void SpriteBatchMesh::resize(size_t newSize) {
        if (newSize == maxInstances) {
            return;
        }

        maxInstances = newSize;

        // Create a new data that will be used.
        std::vector<float> newData = std::vector<float>(maxInstances * TOTAL_FLOATS_IN_SPRITE);

        // Copy the old data to the new data.
        newData.insert(newData.begin(), vertexData.begin(), vertexData.end());

        // Set the new data.
        vertexData = newData;

        setupIndices();

        // TODO: Dispose of buffers.

        // TODO: Assign new buffers.
    }

    void SpriteBatchMesh::writeSprite(size_t instance, glm::vec3 position, glm::vec2 size) {
        size_t index = instance * TOTAL_FLOATS_IN_SPRITE; // 36 due to 9 * 4 vertices.

        // Top left.
        vertexData[index++] = position.x;
        vertexData[index++] = position.y;
        vertexData[index++] = position.z;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 0;
        vertexData[index++] = 0;

        // Top right.
        vertexData[index++] = position.x + size.x;
        vertexData[index++] = position.y;
        vertexData[index++] = position.z;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 0;

        // Bottom left.
        vertexData[index++] = position.x;
        vertexData[index++] = position.y + size.y;
        vertexData[index++] = position.z;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 0;
        vertexData[index++] = 1;

        // Bottom right.
        vertexData[index++] = position.x + size.x;
        vertexData[index++] = position.y + size.y;
        vertexData[index++] = position.z;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
        vertexData[index++] = 1;
    }
}
