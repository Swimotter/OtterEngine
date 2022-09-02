#pragma once

/**
* Handles all keyboard events
* @see Event.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Event.h"

namespace Otter {

	/**
	* Passes key number to KeyPressedEvent, KeyReleasedEvent, and KeyTypedEvent
	* @see KeyPressedEvent
	* @see KeyReleasedEvent
	* @see KeyTypedEvent
	*
	* @return int This is the id number of the key button
	*/
	class OTTER_API KeyEvent : public Event {
	public:
		inline int GetKeycode() const { return _keycode; }
		//Event group
		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode) : _keycode(keycode) {}

		int _keycode;
	};

	/**
	* Handles key presses
	* @see KeyEvent
	*
	* @param keycode, repeatCount These are the id of the key pressed and if it is repeating
	* @return string This returns key id pressed and if it is repeating
	*/
	class OTTER_API KeyPressedEvent : public KeyEvent {
	public:
		KeyPressedEvent(int keycode, int repeatCount) : KeyEvent(keycode), _repeatCount(repeatCount) {}

		inline int GetRepeatCount() const { return _repeatCount; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keycode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		//Event group
		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int _repeatCount;
	};

	/**
	* Handles key releases
	* @see KeyEvent
	*
	* @param keycode This is the id of the key released
	* @return string This returns key id released
	*/
	class OTTER_API KeyReleasedEvent : public KeyEvent {
	public:
		KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keycode;
			return ss.str();
		}

		//Event group
		EVENT_CLASS_TYPE(KeyReleased)
	};

	/**
	* Handles unicode char typed
	* @see KeyEvent
	*
	* @param keycode This is the ascii id of the char
	* @return string This is the ascii char id typed
	*/
	class OTTER_API KeyTypedEvent : public KeyEvent {
	public:
		KeyTypedEvent(int keycode) : KeyEvent(keycode) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "KeyTypedEvent: " << _keycode;
			return ss.str();
		}

		//Event group
		EVENT_CLASS_TYPE(KeyTyped)
	};
}