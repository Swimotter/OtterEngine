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
	}

	Application::~Application() {}

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
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

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