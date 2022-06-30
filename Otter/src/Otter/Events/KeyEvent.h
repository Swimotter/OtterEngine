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
}