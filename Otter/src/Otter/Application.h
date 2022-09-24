#pragma once

/**
* Handles the application
* @see Window.h
* @see ImGuiLayer.h
* @see LayerStack.h
* @see Event.h
* @see Shader.h
*
* @author Jackson Rubiano
* @version 1.3
* @since 0.0.0-pa.1
*/

#include "Otter/Core.h"
#include "Otter/Window.h"
#include "Otter/LayerStack.h"
#include "Otter/Events/Event.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/ImGui/ImGuiLayer.h"
#include "Otter/Renderer/Shader.h"

namespace Otter {

	class OTTER_API Application {
	public:
		Application();
		virtual ~Application() = default;

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

		inline static Application& Get() { return *s_instance; }
		inline Window& GetWindow() { return *_window; }
	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> _window;
		ImGuiLayer* _ImGuiLayer;
		bool _running = true;
		LayerStack _layerStack;

		unsigned int _vertexArray, _vertexBuffer, _indexBuffer;
		std::unique_ptr<Shader> m_shader;
	private:
		static Application* s_instance;
	};

	//Defined by client
	Application* CreateApplication();
}