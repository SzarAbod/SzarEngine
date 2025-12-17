add_rules("mode.debug", "mode.release")

set_languages("c++23")

set_project("Szar")
set_version("1.0.0")

if is_mode("debug") then 
    add_defines("DEBUG")
else 
    set_optimize("fastest")
end

add_includedirs("Szar/include", {public = true})

target("Szar")
    set_kind("shared")
    -- add_rules("utils.symbols.export_all", {export_classes = true})    
    add_files("Szar/src/*.cpp")

target("Game")
    set_kind("binary")
    add_deps("Szar")
    add_files("Game/src/*.cpp")
    add_headerfiles("Game/src/*.hpp")


-- For packing and making the install file
includes("@builtin/xpack")

xpack("Game") 
    set_formats("nsis", "deb")
    set_title("Szar Game Application")
    set_description("Game application for Szar library")
    set_author("abod <abdulrahman.mah@proton.me>")
    set_homepage("szarabod.github.io")
    set_license("MIT")
    
    -- Set the icon file for the Game package
    set_iconfile("assets/installer.ico")
    set_nsis_displayicon("assets/installer.ico")

    -- Add binary target
    add_targets("Game")
    
    -- Include the Szar shared library
    add_targets("Szar")
    
    on_load(function (package)
        package:set("basename", "Game-$(plat)-$(arch)-$(mode)")
    end)