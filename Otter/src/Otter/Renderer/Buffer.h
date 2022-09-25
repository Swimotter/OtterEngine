#pragma once

/**
* Handles vertex and index buffers
* Implemented per rendering system
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.14
*/

namespace Otter {

	class VertexBuffer {
	public:
		virtual ~VertexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static VertexBuffer* Create(float* vertices, uint32_t size);
	};

	class IndexBuffer {
	public:
		virtual ~IndexBuffer() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		static IndexBuffer* Create(uint32_t* indices, uint32_t size);
	};
}