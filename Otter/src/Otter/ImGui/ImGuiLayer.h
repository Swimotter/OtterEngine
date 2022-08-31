#pragma once

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