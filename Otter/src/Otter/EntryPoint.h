#pragma once

#ifdef OTTER_PLATFORM_WINDOWS
extern Otter::Application* Otter::CreateApplication();

int main(int argc, char** argv) {
	auto app = Otter::CreateApplication();
	app->Run();
	delete app;
}
#endif