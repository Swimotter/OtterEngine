#include "OtterPCH.h"
#include "Application.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/Log.h"

namespace Otter {

	Application::Application() {}

	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1200, 720);
		OTTER_TRACE(e);
		while (true);
	}
}