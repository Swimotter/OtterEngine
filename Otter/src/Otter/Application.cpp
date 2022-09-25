#include "OtterPCH.h"
#include "Application.h"
#include "Otter/Log.h"
#include "Otter/Input.h"

#include <glad/glad.h>

namespace Otter {

	#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() {
		OTTER_CORE_ASSERT(!s_instance, "Application already exists!");
		s_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));

		_ImGuiLayer = new ImGuiLayer();
		PushOverlay(_ImGuiLayer);

		glGenVertexArrays(1, &_vertexArray);
		glBindVertexArray(_vertexArray);

		//Triangle
		float vertices[3 * 3] = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f
		};

		m_vertexBuffer.reset(VertexBuffer::Create(vertices, sizeof(vertices)));

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		uint32_t indices[3] = {
			0,
			1,
			2
		};
		m_indexBuffer.reset(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_position;

			out vec3 v_position;

			void main() {
				v_position = a_position;
				gl_Position = vec4(a_position, 1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 o_color;

			in vec3 v_position;

			void main() {
				o_color = vec4(v_position * 0.5 + 0.5, 1.0);
			}
		)";

		m_shader.reset(new Shader(vertexSrc, fragmentSrc));
	}

	void Application::PushLayer(Layer* layer) {
		_layerStack.PushLayer(layer);
	}
	
	void Application::PushOverlay(Layer* overlay) {
		_layerStack.PushOverlay(overlay);
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FUNCTION(OnWindowClose));

		for (auto item = _layerStack.end(); item != _layerStack.begin();) {
			(*--item)->OnEvent(e);
			if (e.handled) {
				break;
			}
		}

		//log events
		//OTTER_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		while (_running) {
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			m_shader->Bind();
			glBindVertexArray(_vertexArray);
			glDrawElements(GL_TRIANGLES, m_indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : _layerStack) {
				layer->OnUpdate();
			}

			_ImGuiLayer->Begin();
			for (Layer* layer : _layerStack) {
				layer->OnImGuiRender();
			}
			_ImGuiLayer->End();

			_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		_running = false;
		return true;
	}
}