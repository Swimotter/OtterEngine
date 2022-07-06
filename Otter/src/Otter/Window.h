#pragma once

#include "OtterPCH.h"
#include "Otter/Core.h"
#include "Otter/Events/Event.h"

namespace Otter {

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

		static Window* Create(const WindowProps& props = WindowProps());
	};
}