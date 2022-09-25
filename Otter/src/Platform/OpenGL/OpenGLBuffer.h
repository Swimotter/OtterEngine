#pragma once

#include "Otter/Renderer/Buffer.h"

/**
* Handles vertex and index buffers for OpenGL
* @see Buffer.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.15
*/

namespace Otter {

	class OpenGLVertexBuffer : public VertexBuffer {
	public:
		OpenGLVertexBuffer(float* vertices, uint32_t size);
		virtual ~OpenGLVertexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;
	private:
		uint32_t m_rendererID;
	};

	class OpenGLIndexBuffer : public IndexBuffer {
	public:
		OpenGLIndexBuffer(uint32_t* indices, uint32_t count);
		virtual ~OpenGLIndexBuffer();

		virtual void Bind() const;
		virtual void Unbind() const;

		virtual inline uint32_t GetCount() const { return m_count; }
	private:
		uint32_t m_rendererID;
		uint32_t m_count;
	};
}