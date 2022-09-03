#pragma once

/**
* Used to create and get information about the window
* Implemented per operating system
* @see WindowsWindow.h
* @see Event.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "OtterPCH.h"
#include "Otter/Core.h"
#include "Otter/Events/Event.h"

namespace Otter {

	/**
	* Used to give default parameters for a window
	*
	* @return WindowProps This returns the default window
	*/
	struct WindowProps {
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProps(const std::string& title = "Otter Engine", unsigned int width = 1280, unsigned int height = 720) : title(title), width(width), height(height) {}
	};

	//Interface implemented per system
	class OTTER_API Window {
	public:
		using EventCallbackFunction = std::function<void(Event&)>;

		virtual ~Window() {}

		virtual void OnUpdate() = 0;

		virtual unsigned int GetWidth() const = 0;
		virtual unsigned int GetHeight() const = 0;

		virtual void SetEventCallback(const EventCallbackFunction& callback) = 0;
		virtual void SetVSync(bool enabled) = 0;
		virtual bool IsVSync() const = 0;

		virtual void* GetNativeWindow() const = 0;

		/**
		* Creates a new window
		*
		* @param props This is the pointer to the default window settings
		* @return Window* This returns the default window
		*/
		static Window* Create(const WindowProps& props = WindowProps());
	};
}