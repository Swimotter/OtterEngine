#pragma once

#include "Event.h"
#include <sstream>

namespace Otter {
	class OTTER_API KeyEvent : public Event {
	public:
		inline int GetKeyCode() const { return _KeyCode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : _KeyCode(keycode) {}

		int _KeyCode;
	};

	class OTTER_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _KeyCode << " (" << _repeatCount << " repeats)";
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeatCount;
	};
}