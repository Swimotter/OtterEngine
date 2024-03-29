#pragma once

/**
* Used to log messages to the console
* @see https://spdlog.docsforge.com/
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Otter {

	/**
	* Handles loggers
	*
	* @return std::shared_ptr<spdlog::logger>& These are pointers to the core and client loggers
	*/
	class OTTER_API Log {
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//Core macros
#define OTTER_CORE_TRACE(...)		::Otter::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define OTTER_CORE_INFO(...)		::Otter::Log::GetCoreLogger()->info(__VA_ARGS__)
#define OTTER_CORE_WARN(...)		::Otter::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define OTTER_CORE_ERROR(...)		::Otter::Log::GetCoreLogger()->error(__VA_ARGS__)
#define OTTER_CORE_CRITICAL(...)	::Otter::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client macros
#define OTTER_TRACE(...)			::Otter::Log::GetClientLogger()->trace(__VA_ARGS__)
#define OTTER_INFO(...)				::Otter::Log::GetClientLogger()->info(__VA_ARGS__)
#define OTTER_WARN(...)				::Otter::Log::GetClientLogger()->warn(__VA_ARGS__)
#define OTTER_ERROR(...)			::Otter::Log::GetClientLogger()->error(__VA_ARGS__)
#define OTTER_CRITICAL(...)			::Otter::Log::GetClientLogger()->critical(__VA_ARGS__)