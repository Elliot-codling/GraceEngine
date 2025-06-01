---
title: Supported IDEs
nav_order: 2
parent: Install & IDEs
---

# Supported IDEs

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
GraceEngine is not limited to specific IDEs as long as it includes:
- Cmake version 3.14 or newer
- C++ version 17 or newer

We do recommend other IDEs such as:
- [VS2022](https://visualstudio.microsoft.com/vs/) by Microsoft.
- [VScode](https://code.visualstudio.com/) by Microsoft.

Many IDEs support different compiler versions such as GCC, Clang, MSVC and more. However, not all IDEs include the correct compiler or even a compiler at all. For example:
- Clion includes GCC / MSVC / Clang
- VS2022 includes MSVC / Clang (Optional installation package)
- VScode does not include a C++ compiler

We currently support GCC, MSVC and Clang. GCC is the primary default used on Clion, VScode and others while MSVC is the default used with VS2022.\
The compilers we will be using during this installation guide are:
- Clion - GCC
- VS2022 - MSVC
- VScode - MSVC (Windows) or GCC (Linux)

Clion and VS2022 are easy to get setup due to them having C++ compilers built in while VScode does not include any.
For VScode we will be using MSVC for Windows, or if you are on Linux we will be using GCC, as our compiler. Thanks to their compatibility 
with traditional processors (Intel and AMD) while also being compatible with ARM processors (Apple M and Snapdragon X).

{: .note }
If you plan to use VScode as your IDE and you are on Windows, ensure you have MSVC installed onto your system. If you do not have it installed, follow [this](https://code.visualstudio.com/docs/cpp/config-msvc#_prerequisites) guide.

### Other IDEs

We have not tested any other IDEs except for Clion, VS2022 and VScode. However, we can give you some guidance.
Thanks to our Github runners we can confirm this project builds correctly on:
- Windows: GCC, Clang and MSVC
- Linux: GCC and Clang
- MacOS: GCC and Clang 

These have been tested in both Debug and Release configurations.
Ensure your IDE supports the listed compiler above to match your OS, Cmake version 3.14 or newer and C++ version 17 newer.

{: .important }
Theoretically GraceEngine will compile on macOS, this has not been tested, and currently we have no guide for the installation of GraceEngine on macOS.

