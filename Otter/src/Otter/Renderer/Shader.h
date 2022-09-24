#pragma once

#include <string>
 
/**
* Will be moved to OpenGL specific files in the future
* Handles the shader through the OpenGL pipeline
* 
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.12
*/

namespace Otter {

	class Shader {
	public:
		Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
		~Shader();

		void Bind() const;
		void Unbind() const;
	private:
		uint32_t m_rendererID;
	};
}