#pragma once

#ifdef OTTER_PLATFORM_WINDOWS
	#ifdef OTTER_BUILD_DLL
		#define OTTER_API __declspec(dllexport)
	#else
		#define OTTER_API __declspec(dllimport)
	#endif
#else
	#error OS not supported!
#endif