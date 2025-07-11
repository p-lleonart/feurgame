-- premake5.lua
workspace "Feurgame"
   architecture "x86"
   configurations { "Debug", "Release", "Dist" }
   startproject "Feurgame-App"
   -- toolset "gcc"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }
   
   -- filter { "language:C++" and "toolset:gcc or clang" }
   --    buildoptions { "-std=c++17" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "libs"
	include "Feurgame-GUILib/Build-Feurgame-GUILib.lua"

	include "Feurgame-Lib/Build-Feurgame-Lib.lua"
group ""

include "Feurgame-App/Build-Feurgame-App.lua"