cmake_minimum_required(VERSION 3.2)

if(WIN32)
	set(CMAKE_EXPORT_COMPILE_COMMANDS ON CACHE STRING "docstring" FORCE)
	set(CMAKE_C_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/amd64/cl.exe")
	set(CMAKE_CXX_COMPILER "C:/Program Files (x86)/Microsoft Visual Studio 14.0/VC/bin/amd64/cl.exe")
endif()

project(minimal LANGUAGES CXX)

if(MSVC)
	set(CMAKE_CXX_FLAGS "/FS /EHsc /FC") # No pdb concurrency, no warnings, full paths for $msCompile problemMatcher.
endif()

add_executable(minimal minimal.cpp)