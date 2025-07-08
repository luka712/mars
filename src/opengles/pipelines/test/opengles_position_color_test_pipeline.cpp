//
// Created by Erkapic Luka on 2.7.2025.
//

#include "Framework.h"
#include "gpu_util/opengles/opengles_util.h"
#include "opengles/pipelines/test/opengles_position_color_test_pipeline.h"
#include "opengles/buffers/opengles_vertex_buffer.h"
#include "gpu_util/opengles/opengles_util.h"

using namespace gpu_util;

namespace mars {

	OpenGLESPositionColorTestPipeline::OpenGLESPositionColorTestPipeline(Framework& framework)
		: framework(framework), renderer(*dynamic_cast<OpenGLESRenderer*>(&framework.getRenderer())) {
		createProgram();
		vaoId = 0;
		vertexBufferId = 0;
	}

	void OpenGLESPositionColorTestPipeline::createProgram()
	{
		GLuint vertexShader = OpenGLESUtil::getShader()->createVertexShaderFromFile("content/shaders/glsl/300es/test/position_color_vs.glsl");
		GLuint fragmentShader = OpenGLESUtil::getShader()->createFragmentShaderFromFile("content/shaders/glsl/300es/test/position_color_fs.glsl");

		programId = OpenGLESUtil::getProgram()->create(vertexShader, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLESPositionColorTestPipeline::createVAO(OpenGLESVertexBuffer& vertexBuffer) {

		if (vertexBuffer.getBuffer() != vertexBufferId) {

			// Assign the new vertex buffer ID
			vertexBufferId = vertexBuffer.getBuffer();

			// If the VAO ID is not set, create a new VAO
			if (vaoId != 0) 
			{
				vaoId = OpenGLESUtil::getVertexArrayObject()->create("PositionColorTestVAO");
			}
			glBindVertexArray(vaoId);

			// Bind the vertex buffer
			glBindBuffer(GL_ARRAY_BUFFER, vertexBufferId);
			glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)0); // Position attribute
			glVertexAttribPointer(1, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 7, (void*)(sizeof(float) * 3)); // Color attribute
			glEnableVertexAttribArray(0); // Enable position attribute
			glEnableVertexAttribArray(1); // Enable color attribute
		}
	}

	void OpenGLESPositionColorTestPipeline::render(AVertexBuffer& vertexBuffer)
	{
		OpenGLESVertexBuffer& openGLESVertexBuffer = *toOpenGLESVertexBuffer(&vertexBuffer);

		createVAO(openGLESVertexBuffer);

		glUseProgram(programId);
		glBindVertexArray(vaoId);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void OpenGLESPositionColorTestPipeline::destroy() {
		glDeleteProgram(programId);
		glDeleteVertexArrays(1, &vaoId);
	}
}
