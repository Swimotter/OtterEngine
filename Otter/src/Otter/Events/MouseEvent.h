#pragma once

#include "Event.h"
#include <sstream>

namespace Otter {

	class OTTER_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : _MouseX(x), _MouseY(y) {}

		inline float GetX() const { return _MouseX; }
		inline float GetY() const { return _MouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _MouseX << ", " << _MouseY;
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _MouseX, _MouseY;
	};
}