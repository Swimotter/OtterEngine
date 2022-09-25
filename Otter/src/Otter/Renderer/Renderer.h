#pragma once
 
/**
* {DESCRIPTION}
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.18
*/

namespace Otter {

	enum class RendererAPI {
		None = 0, OpenGL = 1
	};

	class Renderer {
	public:
		inline static RendererAPI GetAPI() { return s_rendererAPI; }
	private:
		static RendererAPI s_rendererAPI;
	};
}