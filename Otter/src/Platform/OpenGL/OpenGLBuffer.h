#pragma once

#include "Otter/Renderer/Buffer.h"

/**
* {DESCRIPTION}
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.15
*/

namespace Otter {

	class OpenGLVertexBuffer : public VertexBuffer {
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
	private:
		uint32_t m_rendererID;
	};
}