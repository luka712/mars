//
// Created by Erkapic Luka on 2.7.2025.
//

#include "Framework.h"
#include "gpu_util/opengles/opengles_util.h"
#include "opengles/pipelines/test/opengles_texture_test_pipeline.h"
#include "opengles/buffers/opengles_vertex_buffer.h"
#include "opengles/buffers/opengles_index_buffer.h"
#include "gpu_util/opengles/opengles_util.h"

using namespace gpu_util;

namespace mars {

	OpenGLESTextureTestPipeline::OpenGLESTextureTestPipeline(Framework& framework)
		: framework(framework), renderer(*dynamic_cast<OpenGLESRenderer*>(&framework.getRenderer())) {
		createProgram();
		vaoId = 0;
		vertexBufferId = 0;
	}

	Texture2D* OpenGLESTextureTestPipeline::getTexture2D() {
		return texture;
	}

	void OpenGLESTextureTestPipeline::setTexture2D(Texture2D *texture) {
		if (this->texture != nullptr) {
			this->texture = asOpenGLESTexture(texture);
		} else {
			// Create default texture
			throw std::runtime_error("Need to create default empty texture");
		}
	}


	void OpenGLESTextureTestPipeline::createProgram()
	{
		const GLuint vertexShader = OpenGLESUtil::getShader()->createVertexShaderFromFile("content/shaders/glsl/300es/test/texture_vs.glsl");
		const GLuint fragmentShader = OpenGLESUtil::getShader()->createFragmentShaderFromFile("content/shaders/glsl/300es/test/texture_fs.glsl");

		programId = OpenGLESUtil::getProgram()->create(vertexShader, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLESTextureTestPipeline::createVAO(const OpenGLESVertexBuffer& vertexBuffer) {

		if (vertexBuffer.getBuffer() != vertexBufferId) {

			// Assign the new vertex buffer ID
			vertexBufferId = vertexBuffer.getBuffer();

			// If the VAO ID is not set, create a new VAO
			if (vaoId == 0)
			{
				vaoId = OpenGLESUtil::getVertexArrayObject()->createPositionColorTextureCoordinatesVAO(
					vertexBufferId,
					"TextureTestPipelineVertexArrayObject");
			}
		}
	}

	void OpenGLESTextureTestPipeline::render(AVertexBuffer& vertexBuffer)
	{
		const OpenGLESVertexBuffer& openGLESVertexBuffer = *toOpenGLESVertexBuffer(&vertexBuffer);

		createVAO(openGLESVertexBuffer);

		glUseProgram(programId);
		glBindVertexArray(vaoId);
		glBindTexture(GL_TEXTURE_2D, texture->getTexture());
		glDrawArrays(GL_TRIANGLES, 0, openGLESVertexBuffer.getVertexCount());
	}

	void OpenGLESTextureTestPipeline::render(AVertexBuffer& vertexBuffer, AIndexBuffer& indexBuffer)
	{
		const OpenGLESVertexBuffer& openGLESVertexBuffer = *toOpenGLESVertexBuffer(&vertexBuffer);
		const OpenGLESIndexBuffer& openGLESIndexBuffer = *toOpenGLESIndexBuffer(&indexBuffer);

		createVAO(openGLESVertexBuffer);

		glUseProgram(programId);
		glBindVertexArray(vaoId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, openGLESIndexBuffer.getBuffer());
		glBindTexture(GL_TEXTURE_2D, texture->getTexture());

		const GLenum indexType = openGLESIndexBuffer.getType() == IndexBufferType::Uint16 ? GL_UNSIGNED_SHORT : GL_UNSIGNED_INT;
		glDrawElements(
			GL_TRIANGLES,
			openGLESIndexBuffer.getIndicesCount(),
			indexType,
			nullptr);
	}

	void OpenGLESTextureTestPipeline::destroy() {
		glDeleteProgram(programId);
		glDeleteVertexArrays(1, &vaoId);
	}
}
