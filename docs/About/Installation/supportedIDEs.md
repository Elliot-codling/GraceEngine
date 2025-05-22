---
title: Supported IDEs
nav_order: 2
parent: Install & IDEs
---

# Supported IDEs

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
GraceEngine is not limited to specific IDEs as long as it can compile the code correctly. We do recommend other IDEs such as:
- [VS2022](https://visualstudio.microsoft.com/vs/) by Microsoft.
- [VScode](https://code.visualstudio.com/) by Microsoft.


Many IDEs support different compiler versions such as MinGW, Clang, MSVC and more. However, not all IDEs include the correct compiler or even a compiler at all. For example:
- Clion includes MinGW64 / MSVC / Clang
- VS2022 includes MSVC
- VScode does not include a C++ compiler

We currently support Mingw64, MSVC and Clang. Mingw64 is primarily used on Clion, VScode and others where MSVC is the default used with VS2022. If you plan to use Mingw64 please ensure you have it installed. If you do not have it installed follow this guide.

{: .note }
We will be using Mingw64 and MSVC as the compiler. If you would like to do so, you can use a different compiler instead, however, this guide does not apply to this.

### Other IDEs

We have not tested any other IDEs except for Clion, VS2022 and VScode. However, we can give you some guidance.
Thanks to our Github runners we can confirm this project builds correctly on:
- Windows: MinGW, Clang and MSVC
- Linux: MinGW and Clang

These have been tested in both Debug and Release configurations.
Ensure your IDE supports the listed compiler above.

{: .note}
MacOS will be added shortly to our runners to ensure the project builds correctly on those systems too.