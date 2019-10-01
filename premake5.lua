print "test"
--Workspace level
workspace "Game"
	location	"build"
	startproject "Game"
	configurations {"Debug", "Release"}
	filter "system:windows"
		platforms	{ "x64" }
		characterset	"MBCS"

-- Game Project
project "Game"
	location "build"
	kind "WindowedApp"
	language "C++"
	pchheader "GamePCH.h"
	pchsource "Source/WinMain.cpp"
	debugdir "Source"
	files {
	"Source/**.cpp",
	"Source/**.h",
	"Source/**.frag",
	"Source/**.vert",
	"premake5.lua",
	}
	includedirs {
		"Source",
	}
	links {
		"Framework",
		"opengl32",
	}

-- Framework Project
project "Framework"
	location "build"
	kind "StaticLib"
	language "C++"
	pchheader "FrameworkPCH.h"
	pchsource "Libraries/Framework/Source/Framework.cpp"
	files {
	"Libraries/Framework/Source/**.cpp",
	"Libraries/Framework/Source/**.h",
	}
	includedirs {
		"Libraries/Framework/Source",
	}

