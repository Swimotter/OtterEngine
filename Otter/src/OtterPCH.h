#pragma once

/**
* Precompiled header file
*
* @author Jackson Rubiano
* @version 1.0
* @since 0.0.0-pa.1
*/

#include "Otter/Log.h"

#include <iostream>
#include <memory>
#include <utility>
#include <algorithm>
#include <functional>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

//platform specific includes
#ifdef OTTER_PLATFORM_WINDOWS
	#include <Windows.h>
#endif