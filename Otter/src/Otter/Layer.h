#pragma once

#include "Otter/Core.h"
#include "Otter/Events/Event.h"

namespace Otter {

	class OTTER_API Layer {
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttatch() {}
		virtual void OnDetatch() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const{ return _debugName; }
	protected:
		std::string _debugName;
	};
}