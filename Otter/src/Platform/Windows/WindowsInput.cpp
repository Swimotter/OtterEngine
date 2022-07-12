#include "OtterPCH.h"
#include "WindowsInput.h"
#include "Otter/Application.h"
#include <GLFW/glfw3.h>

namespace Otter {

	bool WindowsInput::IsKeyPressedImpl(int keycode) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}

	bool WindowsInput::IsMouseButtonPressedImpl(int button) {
		auto window = static_cast<GLFWwindow*>(Application::Get().GetWindow().GetNativeWindow());
		auto state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}

	float WindowsInput::GetMouseXImpl() {
		return 0.0f;
	}

	float WindowsInput::GetMouseYImpl() {
		return 0.0f;
	}
}