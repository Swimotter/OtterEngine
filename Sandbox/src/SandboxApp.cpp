#include <Otter.h>

class TestLayer : public Otter::Layer {
public:
	TestLayer() : Layer("Test") {}

	void OnUpdate() override {}

	void OnEvent(Otter::Event& event) override {
		OTTER_TRACE("{0}", event);
	}
};

class Sandbox : public Otter::Application {
public:
	Sandbox() {
		PushLayer(new TestLayer());
		PushOverlay(new Otter::ImGuiLayer());
	}

	~Sandbox() {}
};

Otter::Application* Otter::CreateApplication() {
	return new Sandbox;
}