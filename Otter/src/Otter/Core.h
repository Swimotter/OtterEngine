#pragma once

/**
* Creates required defines for engine to run
* 
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

/**
* @throws OS not supported!if using not using windows
*/
#ifdef OTTER_PLATFORM_WINDOWS
#if OTTER_DYNAMIC_LINK
	#ifdef OTTER_BUILD_DLL
		#define OTTER_API __declspec(dllexport)
	#else
		#define OTTER_API __declspec(dllimport)
	#endif
#else
	#define OTTER_API
#endif
#else
	#error OS not supported!
#endif

#ifdef OTTER_DEBUG
	#define OTTER_ENABLE_ASSERTS
#endif

#ifdef OTTER_ENABLE_ASSERTS
	#define OTTER_ASSERT(x, ...) { if(!(x)) {OTTER_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
	#define OTTER_CORE_ASSERT(x, ...) { if(!(x)) { OTTER_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); }}
#else
	#define OTTER_ASSERT(x, ...)
	#define OTTER_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)

#define OTTER_BIND_EVENT_FUNCTION(function) std::bind(&function, this, std::placeholders::_1)