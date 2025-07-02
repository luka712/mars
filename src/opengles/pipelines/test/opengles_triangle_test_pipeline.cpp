//
// Created by Erkapic Luka on 2.7.2025.
//

#include "Framework.h"
#include "opengles/util/OpenGLESUtil.h"
#include "opengles/pipelines/test/opengles_triangle_test_pipeline.h"

namespace mars {

	OpenGLESTriangleTestPipeline::OpenGLESTriangleTestPipeline(Framework& framework)
		: framework(framework), renderer(*dynamic_cast<OpenGLESRenderer*>(&framework.getRenderer())) {
		createProgram();
	}

	void OpenGLESTriangleTestPipeline::createProgram()
	{
		GLuint vertexShader = OpenGLESUtil::getShader()->createVertexShaderFromFile("content/shaders/glsl/300es/test/triangle_vs.glsl");
		GLuint fragmentShader = OpenGLESUtil::getShader()->createFragmentShaderFromFile("content/shaders/glsl/300es/test/triangle_fs.glsl");

		programId = OpenGLESUtil::getProgram()->create(vertexShader, fragmentShader);

		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	void OpenGLESTriangleTestPipeline::render() {
		glUseProgram(programId);
		glDrawArrays(GL_TRIANGLES, 0, 3);
	}

	void OpenGLESTriangleTestPipeline::destroy() {
		glDeleteProgram(programId);
	}
}
