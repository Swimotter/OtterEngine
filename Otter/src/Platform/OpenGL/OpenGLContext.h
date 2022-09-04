#pragma once

/**
* OpenGL implementation of GraphicsContext
* @see GraphicsContext.h
* @see https://www.glfw.org/docs/latest/
* @see https://github.com/Dav1dde/glad
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.3
*/

#include "Otter/Renderer/GraphicsContext.h"

struct GLFWwindow;

namespace Otter {

	class OpenGLContext : public GraphicsContext {
	public:
		OpenGLContext(GLFWwindow* windowHandle);

		virtual void Init() override;
		virtual void SwapBuffers() override;
	private:
		GLFWwindow* _windowHandle;
	};
}