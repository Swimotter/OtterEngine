#include "OtterPCH.h"
#include "LayerStack.h"

namespace Otter {
	
	LayerStack::LayerStack() {

	}

	LayerStack::~LayerStack() {
		for (Layer* layer : _layers) {
			delete layer;
		}
	}

	void LayerStack::PushLayer(Layer* layer) {
		_layers.emplace(_layers.begin() + _layerInsertIndex, layer);
		_layerInsertIndex++;
		layer->OnAttach();
	}

	void LayerStack::PushOverlay(Layer* overlay) {
		_layers.emplace_back(overlay);
		overlay->OnAttach();
	}

	void LayerStack::PopLayer(Layer* layer) {
		auto item = std::find(_layers.begin(), _layers.end(), layer);
		if (item != _layers.end()) {
			_layers.erase(item);
			_layerInsertIndex--;
			layer->OnDetach();
		}
	}

	void LayerStack::PopOverlay(Layer* overlay) {
		auto item = std::find(_layers.begin(), _layers.end(), overlay);
		if (item != _layers.end()) {
			_layers.erase(item);
			overlay->OnDetach();
		}
	}
}