#pragma once

#include "Core.h"

namespace Otter {

	class OTTER_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};
}