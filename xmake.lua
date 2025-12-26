add_rules("mode.debug", "mode.release")

set_languages("c++23")

set_project("Szar")
set_version("1.0.0")

local packages = {
    "libsdl3", "spdlog"
}

add_requires(packages)

add_includedirs("Szar/include")

target("Szar")
    set_kind("static")
    add_packages(packages)
    add_headerfiles("Szar/include/*.hpp")
    add_files("Szar/src/*.cpp")

target("Game")
    set_kind("binary")
    add_deps("Szar")
    add_packages(packages)
    add_files("Game/src/*.cpp")

-- For packing and making the install file
includes("@builtin/xpack")

xpack("Game") 
    set_formats("nsis", "zip")
    set_title("Szar Game Application")
    set_description("Game application for Szar library")
    set_author("abod <abdulrahman.mah@proton.me>")
    set_homepage("szarabod.github.io")
    set_license("MIT")
    
    -- Set the icon file for the Game package
    set_iconfile("assets/installer.ico")
    set_nsis_displayicon("assets/installer.ico")

    add_targets("Game")
    
    on_load(function (package)
        package:set("basename", "Game-$(plat)-$(arch)-$(mode)")
    end)

xpack("Szar")
    set_formats("zip")
    add_targets("Szar")
    on_load(function (package)
        package:set("basename", "Szar-$(plat)-$(arch)-$(mode)")
    end)