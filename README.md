# Minimal CMakeLists C++ VSCode - MSVC+Ninja

## Steps to reproduce minimal functionality

1. Install `ms-vscode.cpptools` extension.
2. Install `vector-of-bool.cmake-tools` extension.
3. `Ctrl+Shift+P` `CMake: Select Kit` -> VisualStudio.14.0 - amd64 (Ninja is set on workspace settings).
4. `Ctrl+Shift+P` `CMake: Set current build variant` -> Debug.
5. `Ctrl+Shift+P` `CMake: Delete cached build settings and reconfigure`.
6. `Ctrl+Shift+P` `CMake: Clean rebuild`.
7. F5 to Debug the first task on `launch.json`, `build` on `tasks.json` must also be executed.

## Steps to install MSVC

1. Install [Windows SDK](https://developer.microsoft.com/en-us/windows/downloads/sdk-archive). Required for _Ninja_.
2. Install [Build Tools for Visual Studio](https://visualstudio.microsoft.com/downloads/#build-tools-for-visual-studio-2017).
3. Install Ninja `choco install ninja`.
3. Add windows environment `PATH` references.

## Some hard-earned tips

1. MSVC is the best generator for CUDA. Others like gcc and clang are not fully supported.
2. `/FS` flag is required when building using Ninja generator and MSVC to avoid concurrent `pdb`.
3. This is the solution that requires less hard-drive of all. Installing VS2017 requires at least 20GB.
4. `vcvarsall.bat x64` needs to be run before running `cmake --build` or `cl.exe`.