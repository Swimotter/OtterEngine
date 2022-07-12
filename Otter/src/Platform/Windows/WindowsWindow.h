#pragma once

#include "Otter/Window.h"
#include <GLFW/glfw3.h>

namespace Otter {

	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void OnUpdate() override;

		inline unsigned int GetWidth() const override { return _data.width; }
		inline unsigned int GetHeight() const override { return _data.height; }

		inline void SetEventCallback(const EventCallbackFunction& callback) override { _data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return _window; };
	private:
		virtual void Init(const WindowProps& props);
		virtual void Shutdown();
	private:
		GLFWwindow* _window;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool VSync;

			EventCallbackFunction eventCallback;
		};

		WindowData _data;
	};
}