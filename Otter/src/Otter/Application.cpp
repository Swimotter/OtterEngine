#include "OtterPCH.h"
#include "Application.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/Log.h"
#include "Otter/Input.h"
#include <glad/glad.h>

namespace Otter {

	#define BIND_EVENT_FUNCTION(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_instance = nullptr;

	Application::Application() {
		//This shouldn't be getting called but it does
		// needs a fix
		//OTTER_CORE_ASSERT(s_instance, "Application already exists!");
		s_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FUNCTION(OnEvent));
	}

	Application::~Application() {}

	void Application::PushLayer(Layer* layer) {
		_layerStack.PushLayer(layer);
		layer->OnAttach();
	}
	
	void Application::PushOverlay(Layer* overlay) {
		_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
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

		OTTER_CORE_TRACE("{0}", e);
	}

	void Application::Run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack) {
				layer->OnUpdate();
			}

			auto [xPos, yPos] = Input::GetMousePos();

			OTTER_CORE_TRACE("{0}, {1}", xPos, yPos);

			_window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		_running = false;
		return true;
	}
}