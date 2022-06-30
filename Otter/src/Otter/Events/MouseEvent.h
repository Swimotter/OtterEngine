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
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _MouseX, _MouseY;
	};

	class OTTER_APi MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float OffsetX, float OffsetY) : _OffsetX(OffsetX), _OffsetY(OffsetY) {}
		
		inline float GetOffsetX() const { return _OffsetX; }
		inline float GetOffsetY() const { return _OffsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _OffsetX << ", " << _OffsetY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _OffsetX, _OffsetY;
	};

	class OTTER_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _Button; }
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : _Button(button) {}

		int _Button;
	};

	class OTTER_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class OTTER_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _Button;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}