#pragma once

#include "Otter/Input.h"

namespace Otter {

	class WindowsInput : public Input{
	protected:
		virtual bool IsKeyPressedImpl(int keycode) override;

		virtual bool IsMouseButtonPressedImpl(int button) override;
		virtual float GetMouseXImpl() override;
		virtual float GetMouseYImpl() override;
	};
}