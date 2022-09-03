#pragma once

/**
* Windows implementation of Window.h
* @see Window.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

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

		/**
		* Sets the function to send events to be handled
		*
		* @param props This is a reference to the window settings
		*/
		inline void SetEventCallback(const EventCallbackFunction& callback) override { _data.eventCallback = callback; }
		void SetVSync(bool enabled) override;
		bool IsVSync() const override;

		inline virtual void* GetNativeWindow() const { return _window; };
	private:
		/**
		* Initializes a window with given properties
		*
		* @param props This is a reference to the window settings
		*/
		virtual void Init(const WindowProps& props);
		/**
		* Closes the window
		*/
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