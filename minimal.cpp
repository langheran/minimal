#include <iostream>;

using namespace std;

int main()
{
    /** Steps to reproduce minimal functionality:
     * 1. Install ms-vscode.cpptools
     * 2. Install vector-of-bool.cmake-tools
     * 3. Ctrl+Shift+P `CMake: Select Kit` -> VisualStudio.14.0 - amd64
     * 4. Ctrl+Shift+P `CMake: Delete cached build settings and reconfigure`
     * 5. Ctrl+Shift+P `CMake: Clean rebuild`
     * 6. F5 to Debug the first task on `launch.json`, `build` on `tasks.json` must also be executed
     */
    cout << "Minimal";
    cin.get();
    return 0;
}