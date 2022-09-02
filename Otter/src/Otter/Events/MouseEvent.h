#pragma once

/**
* Handles all mouse events
* @see Event.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Event.h"

namespace Otter {

	/**
	* Handles moving the mouse
	*
	* @param x, y These are the x and y coordinates of the mouse
	* @return string This returns the mouse position
	*/
	class OTTER_API MouseMovedEvent : public Event {
	public:
		MouseMovedEvent(float x, float y) : _mouseX(x), _mouseY(y) {}

		inline float GetX() const { return _mouseX; }
		inline float GetY() const { return _mouseY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << _mouseX << ", " << _mouseY;
			return ss.str();
		}

		//Event groups
		EVENT_CLASS_TYPE(MouseMoved)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _mouseX, _mouseY;
	};

	/**
	* Handles mouse scrolling
	*
	* @param offsetX, offsetY These are the vertical and horizontal scrolling since the last frame
	* @return string This returns the amount scrolled since last frame
	*/
	class OTTER_API MouseScrolledEvent : public Event {
	public:
		MouseScrolledEvent(float offsetX, float offsetY) : _offsetX(offsetX), _offsetY(offsetY) {}
		
		inline float GetOffsetX() const { return _offsetX; }
		inline float GetOffsetY() const { return _offsetY; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << _offsetX << ", " << _offsetY;
			return ss.str();
		}

		//Event groups
		EVENT_CLASS_TYPE(MouseScrolled)
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float _offsetX, _offsetY;
	};

	/**
	* Passes mouse button number to MouseButtonPressedEvent and MouseButtonReleasedEvent
	* @see MouseButtonPressedEvent
	* @see MouseButtonReleasedEvent
	* 
	* @return int This returns the mouse button number
	*/
	class OTTER_API MouseButtonEvent : public Event {
	public:
		inline int GetMouseButton() const { return _button; }
		//Event group
		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button) : _button(button) {}

		int _button;
	};

	/**
	* Handles mouse button presses
	* @see MouseButtonEvent
	*
	* @param button This is the numerical id of the mouse button
	* @return string This returns the mouse button pressed in numerical form
	*/
	class OTTER_API MouseButtonPressedEvent : public MouseButtonEvent {
	public:
		MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _button;
			return ss.str();
		}

		//Event group
		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	/**
	* Handles mouse button releases
	* @see MouseButtonEvent
	*
	* @param button This is the numerical id of the mouse button
	* @return string This returns the mouse button released in numerical form
	*/
	class OTTER_API MouseButtonReleasedEvent : public MouseButtonEvent {
	public:
		MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

		std::string ToString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _button;
			return ss.str();
		}

		//Event group
		EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}