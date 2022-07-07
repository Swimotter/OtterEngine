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

	void LayerStack::PushOverlay(Layer* overlay) {
		_layers.emplace_back(overlay);
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto item = std::find(_layers.begin(), _layers.end(), layer);
		if (item != _layers.end()) {
			_layers.erase(item);
			_layerInsert--;
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto item = std::find(_layers.begin(), _layers.end(), overlay);
		if (item != _layers.end()) {
			_layers.erase(item);
		}
	}
}