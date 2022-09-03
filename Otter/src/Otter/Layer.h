#pragma once

/**
* Layers for use in LayerStack
* @see LayerStack.h
* @see Events.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Otter/Core.h"
#include "Otter/Events/Event.h"

namespace Otter {

	class OTTER_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const{ return _debugName; }
	protected:
		std::string _debugName;
	};
}