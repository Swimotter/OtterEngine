#pragma once

/**
* LayerStack for use in organizing layers
* @see Layer.h
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Otter/Core.h"
#include "Layer.h"

namespace Otter {

	class LayerStack {
	public:
		LayerStack();
		~LayerStack();

		//Adding and removing layers and overlays
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);
		void PopLayer(Layer* layer);
		void PopOverlay(Layer* overlay);

		std::vector<Layer*>::iterator begin() { return _layers.begin(); }
		std::vector<Layer*>::iterator end() { return  _layers.end(); }
	private:
		std::vector<Layer*> _layers;
		unsigned int _layerInsertIndex = 0;
	};
}