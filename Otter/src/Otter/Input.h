#pragma once

/**
* Checks for inputs and gets information about inputs
* Inputs are handled per operating system
* @see WindowsInput.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Otter/Core.h"

namespace Otter {

	class OTTER_API Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressed(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_instance->IsMouseButtonPressedImpl(button); }
		inline static float GetMouseX() { return s_instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_instance->GetMouseYImpl(); }
		inline static std::pair<float, float> GetMousePos() { return s_instance->GetMousePosImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
		virtual std::pair<float, float> GetMousePosImpl() = 0;
	private:
		static Input* s_instance;
	};
}