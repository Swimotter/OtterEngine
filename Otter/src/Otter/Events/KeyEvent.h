#pragma once

#include "Event.h"

namespace Otter {

	class OTTER_API KeyEvent : public Event {
	public:
		inline int GetKeycode() const { return _keycode; }
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : _keycode(keycode) {}

		int _keycode;
	};

	class OTTER_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keycode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeatCount;
	};

	class OTTER_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};

	class OTTER_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << _keycode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyTyped)
	};
}