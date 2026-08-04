set_xmakever("3.0.9")

set_project("QuickLootIEPolicyTests")
set_version("1.0.0")
set_languages("cxx23")
set_license("MIT")
set_warnings("allextra", "error")

set_policy("package.requires_lock", true)

add_requires("catch2 v3.15.2")

target("QuickLootIEPolicyTests")
    set_kind("binary")
    add_packages("catch2", {components = {"main", "lib"}})
    add_files("*.cpp")
    add_includedirs("../src")
target_end()
