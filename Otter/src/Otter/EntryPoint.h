#pragma once

/**
* Access point for external applications to begin engine
* 
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#ifdef OTTER_PLATFORM_WINDOWS
extern Otter::Application* Otter::CreateApplication();

int main(int argc, char** argv) {
	Otter::Log::Init();
	OTTER_CORE_WARN("Initialized Log");

	auto app = Otter::CreateApplication();
	app->Run();
	delete app;
}
#endif