# Minimal CMakeLists C++ VSCode - MSVC+Ninja

 [![Status](https://travis-ci.org/langheran/minimal-vscode-cmake.svg?branch=master)](https://travis-ci.org/langheran/minimal-vscode-cmake)

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

1. MSVC is the best generator for CUDA. Others like `gcc` and `clang` are not fully supported.
2. `/FS` flag is required when building using Ninja generator and MSVC to avoid concurrent `pdb`.
3. This is the solution that requires less disk memory of all. Installing VS2017 requires at least 20GB.
4. `vcvarsall.bat x64` needs to be run before running `cmake --build` or `cl.exe`.
5. Remove all unnecessary plugins from vscode, they might interfere to setting the `build variant` on the CMake `vector-of-bool.cmake-tools` extension.

## C++ Boost naming convention

```cpp
#ifndef NAMESPACE_NAMES_THEN_PRIMARY_CLASS_OR_FUNCTION_THEN_HPP
#define NAMESPACE_NAMES_THEN_PRIMARY_CLASS_OR_FUNCTION_THEN_HPP

#include <boost/headers/go/first>
#include <boost/in_alphabetical/order>
#include <then_standard_headers>
#include <in_alphabetical_order>

#include "then/any/detail/headers"
#include "in/alphabetical/order"
#include "then/any/remaining/headers/in"
// (you'll never guess)
#include "alphabetical/order/duh"

#define NAMESPACE_NAMES_THEN_MACRO_NAME(pMacroNames) ARE_ALL_CAPS

namespace lowercase_identifers
{
    class separated_by_underscores
    {
    public:
        void because_underscores_are() const
        {
            volatile int mostLikeSpaces = 0; // but local names are condensed

            while (!mostLikeSpaces)
                single_statements(); // don't need braces
    
            for (size_t i = 0; i < 100; ++i)
            {
                but_multiple(i);
                statements_do();
            }             
        }
    
        const complex_type& value() const
        {
            return mValue; // no conflict with value here
        }
    
        void value(const complex_type& pValue)
        {
            mValue = pValue ; // or here
        }
    
    protected:
        // the more public it is, the more important it is,
        // so order: public on top, then protected then private
    
        template <typename Template, typename Parameters>
        void are_upper_camel_case()
        {
            // gman was here                
        }
    
    private:
        complex_type mValue;
    };
}

#endif
```

Taken from [Stack Overflow](https://stackoverflow.com/questions/3706379/what-is-a-good-naming-convention-for-vars-methods-etc-in-c), recommended by `The C++ Programming Language` by _Bjarne Stroustrup_ creator of C++.