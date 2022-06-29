#pragma once

#ifdef OTTER_PLATFORM_WINDOWS
extern Otter::Application* Otter::CreateApplication();

int main(int argc, char** argv) {
	Otter::Log::Init();
	OTTER_CORE_WARN("Initialized Log");
	int a = 5;
	OTTER_INFO("Hello Var = {0}", a);

	auto app = Otter::CreateApplication();
	app->Run();
	delete app;
}
#endif