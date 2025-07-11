project "Feurgame-Lib"
   kind "StaticLib"
   language "C++"
   cppdialect "C++17"
   targetdir "Binaries/%{cfg.buildcfg}"
   staticruntime "off"

   files { "Source/**.hpp", "Source/**.cpp" }

   includedirs
   {
      "Source",

      "../Feurgame-GUILib/Source",
      "../Vendor/Binaries/sfml/include",
      "../Vendor"
   }

   libdirs { "../Vendor/Binaries/sfml/lib" }

   links
   {
      "freetype.lib",
      "opengl32.lib",
      "winmm.lib",
      "gdi32.lib",
      "Feurgame-GUILib"
   }

   targetdir ("../Binaries/" .. OutputDir .. "/%{prj.name}")
   objdir ("../Binaries/Intermediates/" .. OutputDir .. "/%{prj.name}")

   filter "system:windows"
       systemversion "latest"
       defines { "GAME_PLATFORM_WINDOWS", "SFML_STATIC" }

   filter "configurations:Debug"
       defines { "DEBUG" }
       runtime "Debug"
       symbols "On"
       links { "sfml-graphics-s-d.lib", "sfml-system-s-d.lib", "sfml-window-s-d.lib" }

   filter "configurations:Release"
       defines { "RELEASE" }
       runtime "Release"
       optimize "On"
       symbols "On"
       links { "sfml-graphics-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }

   filter "configurations:Dist"
       defines { "DIST" }
       runtime "Release"
       optimize "On"
       symbols "Off"
       links { "sfml-graphics-s.lib", "sfml-system-s.lib", "sfml-window-s.lib" }