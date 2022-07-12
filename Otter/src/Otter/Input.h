#pragma once

#include "Otter/Core.h"

namespace Otter {

	class OTTER_API Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressed(keycode); }

		inline static bool IsMouseButtonPressed(int button) { return s_instance->IsMouseButtonPressedImpl(button); }
		inline static float GetMouseX() { return s_instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_instance->GetMouseYImpl(); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(int button) = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;
	private:
		static Input* s_instance;
	};
}