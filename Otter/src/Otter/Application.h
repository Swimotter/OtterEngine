#pragma once

#include "Core.h"
#include "Events/Event.h"
#include "Window.h"

namespace Otter {

	class OTTER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);
	private:
		std::unique_ptr<Window> _window;
		bool _running = true;
	};

	//Defined by client
	Application* CreateApplication();
}