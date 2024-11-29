//
// Created by lukaa on 29.11.2024..
//

#include "Framework.h"
#include "core/sprite/SpriteBatchDrawable.h"

namespace mars {

	SpriteBatchDrawable::SpriteBatchDrawable(Framework& framework, size_t maxBatchSize)
		: framework(framework), maxBatchSize(maxBatchSize){

          }

	void SpriteBatchDrawable::initialize() {
		drawingMesh = std::make_unique<SpriteBatchMesh>(framework, maxBatchSize);
		drawingMesh->initialize();
	}

	void SpriteBatchDrawable::reset() {
		// Nothing is drawn yet.
		fromInstance = 0;
		toInstance = 0;
	}

	void SpriteBatchDrawable::writeSprite(glm::vec3 position, glm::vec2 size) {
		if (toInstance >= maxBatchSize) {
			// We need to resize the batch.
			needsResize = true;
			return;
		}

		drawingMesh->writeSprite(toInstance, position, size);
		toInstance++;
	}

	void SpriteBatchDrawable::draw() {
		// Nothing to draw.
		if (toInstance <= 0 || fromInstance > toInstance)
		{
			return;
		}

		// Clamp instance to max batch size.
		if(toInstance >= maxBatchSize)
		{
			toInstance = maxBatchSize - 1;
		}

		// Draw mesh.
		int indicesOffset = fromInstance * 6;
		int indicesCount = toInstance * 6 - indicesOffset;
		drawingMesh->applyChanges();
		// renderPipeline.Render(drawingMesh.VertexBuffer, drawingMesh.IndexBuffer,
		// 	indicesCount,
		// 	(uint) indicesOffset );
		fromInstance = toInstance;
	}
}