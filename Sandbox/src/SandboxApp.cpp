#include <Otter.h>

class Sandbox : public Otter::Application {
public:
	Sandbox() {}

	~Sandbox() {}
};

void main() {
	Sandbox* sandbox = new Sandbox();
	sandbox->Run();
	delete sandbox;
}