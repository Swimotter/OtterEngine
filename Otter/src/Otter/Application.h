#pragma once

#include "Core.h"
#include "Window.h"
#include "Otter/LayerStack.h"
#include "Otter/Events/Event.h"
#include "Otter/Events/ApplicationEvent.h"

namespace Otter {

	class OTTER_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_instance; }
		inline Window& GetWindow() { return *_window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> _window;
		bool _running = true;
		LayerStack _layerStack;
	private:
		static Application* s_instance;
	};

	//Defined by client
	Application* CreateApplication();
}