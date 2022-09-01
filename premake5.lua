workspace "Otter"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "Otter/vendor/GLFW/include"
includeDir["Glad"] = "Otter/vendor/Glad/include"
includeDir["ImGui"] = "Otter/vendor/ImGui"
includeDir["glm"] = "Otter/vendor/glm"

group "Dependencies"
	include "Otter/vendor/GLFW"
	include "Otter/vendor/Glad"
	include "Otter/vendor/ImGui"
group ""


project "Otter"
	location "Otter"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "OtterPCH.h"
	pchsource "Otter/src/OtterPCH.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	defines {
		"_CRT_SECURE_NO_WARNINGS"
	}

	removefiles {
		"%{prj.name}/src/Math/**"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDir.GLFW}",
		"%{includeDir.Glad}",
		"%{includeDir.ImGui}",
		"%{includeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"OTTER_PLATFORM_WINDOWS",
			"OTTER_BUILD_DLL",
			"GLFW_INCLUDE_NONE",
			"IMGUI_IMPL_OPENGL_LOADER_CUSTOM"
		}

	filter "configurations:Debug"
		defines "OTTER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OTTER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OTTER_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Otter/vendor/spdlog/include",
		"Otter/src",
		"Otter/vendor",
		"%{includeDir.glm}"
	}

	links {
		"Otter"
	}

	filter "system:windows"
		systemversion "latest"

		defines {
			"OTTER_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "OTTER_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "OTTER_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "OTTER_DIST"
		runtime "Release"
		optimize "on"