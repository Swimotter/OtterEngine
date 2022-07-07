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
}