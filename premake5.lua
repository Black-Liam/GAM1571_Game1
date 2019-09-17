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
	location "build/Game"
	kind "WindowedApp"
	language "C++"
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
	location "build/Libraries/Framework"
	kind "StaticLib"
	language "C++"
	files {
	"Libraries/Framework/Source/**.cpp",
	"Libraries/Framework/Source/**.h",
	}
	includedirs {
		"Libraries/Framework/Source",
	}

