#include "OtterPCH.h"
#include "Buffer.h"

#include "Otter/Renderer/Renderer.h"
#include "Platform/OpenGL/OpenGLBuffer.h"

namespace Otter {
	VertexBuffer* VertexBuffer::Create(float* vertices, uint32_t size) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			OTTER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLVertexBuffer(vertices, size);
		}

		OTTER_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}

	IndexBuffer* IndexBuffer::Create(uint32_t* indices, uint32_t count) {
		switch (Renderer::GetAPI()) {
		case RendererAPI::None:
			OTTER_CORE_ASSERT(false, "RendererAPI::None is currently not supported!");
			return nullptr;
		case RendererAPI::OpenGL:
			return new OpenGLIndexBuffer(indices, count);
		}

		OTTER_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}