workspace "game"
    architecture "x64"
    toolset "gcc"

    configurations {
        "debug",
        "release",
        "dist"
    }

    filter "configurations:debug"
        defines {"DEBUG"}
        symbols "On"
        filter {"system:linux", "action:gmake"}
            buildoptions {"-g"}
    filter "configurations:release"
        defines {"RELEASE"}
        optimize "On"
    filter "configurations:dist"
        defines {"DIST"}
        optimize "On"

    filter "system:macosx"
        defines {"MACOSX"}

    filter "system:linux"
        defines {"LINUX"}

    filter "system:windows"
        defines {"WINDOWS"}

outputdir = "%{cfg.buildcfg}/%{cfg.system}/%{cfg.architectrure}" 
project "game"
    kind "ConsoleApp"
    language "C++"
    targetname "game"
    targetdir ("game/bin/" .. outputdir)
    objdir ("game/bin-int/" .. outputdir)

    files {
        "game/src/**.hpp",
        "game/src/**.cpp",
        "game/include/**.hpp",
        "game/include/**.cpp",
        "game/deps/src/**.cpp",
        "game/deps/src/**.c",
        "game/deps/include/**.h",
        "game/deps/include/**.hpp"
    }

    includedirs {
        "game/include",
        "game/deps/include",
        "erosion/include"
        --"/usr/include"
    }

    links {
        "GL",
        "glfw",
        "assimp",
        "reactphysics3d",
        "erosion"
    }

    libdirs {
        "game/deps/libs",
        "erosion/bin/" .. outputdir
        --"/usr/lib"
    }

    postbuildcommands {
        "cp -r game/res game/bin/" .. outputdir
    }

project "erosion"
    kind "StaticLib"
    language "C++"
    targetname "erosion"
    targetdir ("erosion/bin/" .. outputdir)
    objdir ("erosion/bin-int/" .. outputdir)

    files {
        "erosion/src/**.hpp",
        "erosion/src/**.cpp",
        "erosion/include/**.hpp",
        "erosion/include/**.cpp",
        "erosion/deps/src/**.cpp",
        "erosion/deps/src/**.c",
        "erosion/deps/include/**.h",
        "erosion/deps/include/**.hpp"
    }

    includedirs {
        "erosion/include",
        "erosion/deps/include",
        --"/usr/include"
    }

    links {
        "GL",
        "glfw",
        "assimp",
        "reactphysics3d"
    }

    libdirs {
        "erosion/deps/libs",
        --"/usr/lib"
    }

    postbuildcommands {
        "cp -r erosion/res erosion/bin/" .. outputdir,
        "cp -r erosion/res game/bin/" .. outputdir
    }

