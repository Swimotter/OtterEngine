#pragma once

/**
* Handles the graphics contexts
* Implemented per graphics library
* @see OpenGLContext.h
* 
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

namespace Otter {

	class GraphicsContext {
	public:
		virtual void Init() = 0;
		virtual void SwapBuffers() = 0;
	};
}