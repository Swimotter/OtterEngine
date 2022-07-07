#include "OtterPCH.h"
#include "LayerStack.h"

namespace Otter {
	
	LayerStack::LayerStack() {
		_layerInsert = _layers.begin();
	}

	LayerStack::~LayerStack() {
		for (Layer* layer : _layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		_layerInsert = _layers.emplace(_layerInsert, layer);
	}
}