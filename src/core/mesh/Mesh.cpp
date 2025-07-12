//
// Created by Erkapic Luka on 29.11.2024.
//

#include "core/mesh/Mesh.h"
#include <Framework.h>
#include <stdexcept>

namespace mars {

	Mesh::Mesh(Framework& framework)
		: framework(framework) {
		bufferUsage = BufferUsage::Vertex;
	}


	void Mesh::initialize() {
		applyChanges();
	}

	void Mesh::applyChanges() {
		if (positions.empty()) {
			framework.getLogger().warn("Cannot create buffers for a Mesh as Mesh has no positions.");
		}

		// - POSITIONS
		const size_t vertexCount = positions.size() / 3;

		vertexData = std::vector<float>((3 + 4 + 2) * vertexCount);

		size_t vertexIndex = 0;
		size_t positionsIndex = 0;
		size_t colorIndex = 0;
		size_t normalIndex = 0;
		size_t uvsIndex = 0;

		for (size_t i = 0; i < vertexCount; i++)
		{
			// Positions.
			vertexData[vertexIndex++] = positions[positionsIndex++];
			vertexData[vertexIndex++] = positions[positionsIndex++];
			vertexData[vertexIndex++] = positions[positionsIndex++];

			// Colors.
			if (!colors.empty())
			{
				fillColors(vertexIndex, colorIndex, colors);
			}

			if (!textureCoordinates.empty())
			{
				// Uvs.
				vertexData[vertexIndex++] = textureCoordinates[uvsIndex++];
				vertexData[vertexIndex++] = textureCoordinates[uvsIndex++];
			}

			if (!normals.empty())
			{
				vertexData[vertexIndex++] = normals[normalIndex++];
				vertexData[vertexIndex++] = normals[normalIndex++];
				vertexData[vertexIndex++] = normals[normalIndex++];
			}
		}

		// Vertices
		vertexBuffer->destroy();
		vertexBuffer =
			framework.getBuffersFactory().createVertexBuffer(
				vertexData,
				vertexCount,
				(3 + 4 * 2) * sizeof(float),
				bufferUsage,
				"Mesh.vertexBuffer");

		// Indices
		indexBuffer->destroy();
		if (!indices.empty()) {
			indexBuffer = framework.getBuffersFactory().createIndexBuffer(
				indices,
				"Mesh.indexBuffer"
			);
		}
	}

	void Mesh::setGeometry(const Geometry& geometry, GeometryFormat format) {
		std::vector<float> interleavedData = geometry.toInterleaved(format);

		// Vertices
		if (vertexBuffer != nullptr) {
			vertexBuffer->destroy();
		}

		// TODO: geometry format to the byte stride
		throw std::runtime_error("Mesh::setGeometry: Geometry format not supported yet.");
		uint32_t byteStride = 0;

		vertexBuffer = framework.getBuffersFactory().createVertexBuffer(
			interleavedData,
			byteStride,
			geometry.getVertexCount(),
			bufferUsage,
			"Mesh.vertexBuffer"
		);

		// Indices
		if (indexBuffer != nullptr) {
			indexBuffer->destroy();
		}
		if (!geometry.getIndices().empty()) {
			indexBuffer = framework.getBuffersFactory().createIndexBuffer(
				geometry.getIndices(),
				"Mesh.indexBuffer"
			);
		}
	}

	void Mesh::fillColors(size_t& vertexIndex, size_t& colorIndex, const std::vector<float>& colors) {

		// If there is still colour to fill.
		if (colors.size() > colorIndex) {
			vertexData[vertexIndex++] = colors[colorIndex++];
			vertexData[vertexIndex++] = colors[colorIndex++];
			vertexData[vertexIndex++] = colors[colorIndex++];
			vertexData[vertexIndex++] = colors[colorIndex++];
		}
		else {
			// Just provide a default colour.
			vertexData[vertexIndex++] = 1.0f;
			vertexData[vertexIndex++] = 1.0f;
			vertexData[vertexIndex++] = 1.0f;
			vertexData[vertexIndex++] = 1.0f;
		}
	}

	void Mesh::destroy() {
		if (vertexBuffer != nullptr) {
			vertexBuffer->destroy();
		}
		if (indexBuffer != nullptr) {
			indexBuffer->destroy();
		}
	}


}
