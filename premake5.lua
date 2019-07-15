workspace "Lmq"
	architecture "x64"
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "Lmq"
	location "Lmq"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "8.1"
		
		defines
		{
			"LMQ_PLATFORM_WINDOWS",
			"LMQ_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "LMQ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LMQ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LMQ_DIST"
		optimize "On"
		
project "Sandbox"

	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	
	targetdir ("bin/" ..outputdir.. "/%{prj.name}")
	objdir ("bin-int/" ..outputdir.. "/%{prj.name}")
	
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"Lmq/vendor/spdlog/include",
		"Lmq/src"
	}
	
	links
	{
		"Lmq"
	}
	
	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "8.1"
		
		defines
		{
			"LMQ_PLATFORM_WINDOWS"
		}
		
		
		
	filter "configurations:Debug"
		defines "LMQ_DEBUG"
		symbols "On"
	
	filter "configurations:Release"
		defines "LMQ_RELEASE"
		optimize "On"
		
	filter "configurations:Dist"
		defines "LMQ_DIST"
		optimize "On"
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		