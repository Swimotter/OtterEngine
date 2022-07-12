#pragma once

#include "Otter/Core.h"

namespace Otter {

	class OTTER_API Input {
	public:
		inline static bool IsKeyPressed(int keycode) { return s_instance->IsKeyPressed(keycode); }
	protected:
		virtual bool IsKeyPressedImpl(int keycode) = 0;
	private:
		static Input* s_instance;
	};
}