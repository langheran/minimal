# Minimal CMakeLists C++ VSCode - MSVC+Ninja<!-- omit in toc -->

 [![Status](https://travis-ci.org/langheran/minimal-vscode-cmake.svg?branch=master)](https://travis-ci.org/langheran/minimal-vscode-cmake)

## Table of contents <!-- omit in toc -->
- [Steps to reproduce minimal functionality](#steps-to-reproduce-minimal-functionality)
- [Steps to install MSVC](#steps-to-install-msvc)
- [Some hard-earned tips](#some-hard-earned-tips)
- [C++ Boost naming convention](#c-boost-naming-convention)
- [Usefull VSCode Keyboard Shortcuts](#usefull-vscode-keyboard-shortcuts)
- [Usual errors](#usual-errors)
- [Useful questions](#useful-questions)

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
6. If you require to install an external library use `ninja install` to install it after building it in the same folder. Then use `find_package(library REQUIRED)` in CMakeLists.txt before `TARGET_LINK_LIBRARIES(${target_name} namepace::library)`.

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

Taken from [Stack Overflow](https://stackoverflow.com/questions/3706379/what-is-a-good-naming-convention-for-vars-methods-etc-in-c), recommended by _Bjarne Stroustrup_ creator of in the book `The C++ Programming Language`.

## Usefull VSCode Keyboard Shortcuts

1. `Shrink/Expand select` `Shift+Alt+RightArrow` selects between brackets.
2. `Fold/Unfold` `Control+K,Control+0` `Control+Shift+'` `Control+Shift+¿` expands or collapse region.
3. `Goto Definition` `F12` `Control+Click` goes to the definition.
4. `Format Document` `Shift+Alt+f` formats the document.
5. `Switch Header/Source` `Alt+O` switchs between _\<header>_.h and _\<source>_.cpp files.
5. `Back` `Alt+LeftArrow` back position.
6. `Control+K,Control+S` opens keyboard shortcuts.
7. `Control+K,Control+R` [Opens Keyboard Reference](https://code.visualstudio.com/shortcuts/keyboard-shortcuts-windows.pdf)

## Usual errors

1. `unresolved externals` signature between header and source files does not match or `extern` variable in the header file no set in the source file.

## Useful questions

1. Why there is not a single vscode extension to save or group breakpoints?