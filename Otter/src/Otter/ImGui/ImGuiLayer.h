#pragma once

/**
* Handles ImGui layers
* @see Layer.h
* @see Event.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Otter/Layer.h"
#include "Otter/Events/ApplicationEvent.h"
#include "Otter/Events/KeyEvent.h"
#include "Otter/Events/MouseEvent.h"

namespace Otter {

	class OTTER_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;

		void Begin();
		void End();
	private:
		float _time = 0;
	};
}