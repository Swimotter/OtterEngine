#pragma once

/**
* Handles all events
* Events are handled immediately
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "OtterPCH.h"
#include "Otter/Core.h"

namespace Otter {

	//Events sorted by type
	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	//Event categories
	enum EventCategory {
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

#define EVENT_CLASS_TYPE(type) static EventType GetStaticType() { return EventType::##type; }\
virtual EventType GetEventType() const override { return GetStaticType(); }\
virtual const char* GetName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }

	/**
	* Defines event and categories
	*
	* @param category This is the event category to compare the event to
	* @return bool This returns if the event is in the given category
	*/
	class OTTER_API Event {
	public:
		bool handled = false;

		virtual EventType GetEventType() const = 0;
		virtual const char* GetName() const = 0;
		virtual int GetCategoryFlags() const = 0;
		virtual std::string ToString() const { return GetName(); }

		inline bool IsInCategory(EventCategory category) {
			return GetCategoryFlags() & category;
		}
	};

	/**
	* Dispatches events to be handled
	*
	* @param event This is the event that needs to be handled
	* @return bool This returns if the event was handled
	*/
	class EventDispatcher {
		template<typename T>
		using EventFn = std::function<bool(T&)>;
	public:
		EventDispatcher(Event& event) : _event(event) {}

		template<typename T>
		bool Dispatch(EventFn<T> func) {
			if (_event.GetEventType() == T::GetStaticType()) {
				_event.handled = func(*(T*)&_event);
				return true;
			}
			return false;
		}
	private:
		Event& _event;
	};

	/**
	* Returns event as a string
	*
	* @param os This is ostream
	* @param e This is the event
	* @return ostream This returns an output stream of the event as a string
	*/
	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}
}