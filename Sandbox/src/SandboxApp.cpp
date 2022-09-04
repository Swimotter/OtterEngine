#include <Otter.h>

class TestLayer : public Otter::Layer {
public:
	TestLayer() : Layer("Test") {}

	void OnUpdate() override {}

	void OnEvent(Otter::Event& event) override {
		//log events
		//OTTER_TRACE("{0}", event);
	}
};

class Sandbox : public Otter::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer());
	}
};

Otter::Application* Otter::CreateApplication() {
	return new Sandbox;
}