#pragma once

#include "Event.h"
#include <sstream>

namespace Otter {
	class OTTER_APi WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : _Width(width), _Height(height) {}

		inline unsigned int GetWidth() const { return _Width; }
		inline unsigned int GetHeight() const { return _Height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _Width << ", " << _Height;
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int _Width, _Height;
	};

	class OTTER_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}