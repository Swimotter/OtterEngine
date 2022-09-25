#include "OtterPCH.h"
#include "OpenGLBuffer.h"

#include "glad/glad.h"

namespace Otter {

	OpenGLVertexBuffer::OpenGLVertexBuffer(float* vertices, uint32_t size) {
		glCreateBuffers(1, &m_rendererID);
		glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		glDeleteBuffers(1, &m_rendererID);
	}

	void OpenGLVertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, m_rendererID);
	}

	void OpenGLVertexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}