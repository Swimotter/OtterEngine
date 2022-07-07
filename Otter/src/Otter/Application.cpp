#include "OtterPCH.h"
#include "Application.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/Log.h"

#include <GLFW/glfw3.h>

namespace Otter {

	#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
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

		OTTER_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack) {
				layer->OnUpdate();
			}

			_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		_running = false;
		return true;
	}
}