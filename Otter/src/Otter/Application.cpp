#include "OtterPCH.h"
#include "Application.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/Log.h"

#include <GLFW/glfw3.h>

namespace Otter {

	Application::Application() {
		_window = std::unique_ptr<Window>(Window::Create());
	}

	Application::~Application() {}

	void Application::Run() {
		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			_window->OnUpdate();
		}
	}
}