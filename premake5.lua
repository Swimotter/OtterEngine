workspace "Otter"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Otter"
	location "Otter"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "OtterPCH.h"
	pchsource "Otter/src/OtterPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OTTER_PLATFORM_WINDOWS",
			"OTTER_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "OTTER_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OTTER_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OTTER_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Otter/vendor/spdlog/include",
		"Otter/src"
	}

	links
	{
		"Otter"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"OTTER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OTTER_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "OTTER_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "OTTER_DIST"
		optimize "On"