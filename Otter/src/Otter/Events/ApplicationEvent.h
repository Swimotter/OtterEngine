#pragma once

/**
* Handles all application events
* @see Event.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Event.h"

namespace Otter {

	/**
	* Handles resizing application 
	*
	* @param width, height These are the width and height of the application window
	* @return string This is dimensions of the application window
	*/
	class OTTER_API WindowResizeEvent : public Event {
	public:
		WindowResizeEvent(unsigned int width, unsigned int height) : _width(width), _height(height) {}

		inline unsigned int GetWidth() const { return _width; }
		inline unsigned int GetHeight() const { return _height; }

		std::string ToString() const override {
			std::stringstream ss;
			ss << "WindowResizeEvent: " << _width << ", " << _height;
			return ss.str();
		}

		//Event groups
		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		unsigned int _width, _height;
	};

	/**
	* Handles closing application
	*/
	class OTTER_API WindowCloseEvent : public Event {
	public:
		WindowCloseEvent() {}

		//Event groups
		EVENT_CLASS_TYPE(WindowClose)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}