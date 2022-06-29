#include <Otter.h>

class Sandbox : public Otter::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

Otter::Application* Otter::CreateApplication() {
	return new Sandbox;
}