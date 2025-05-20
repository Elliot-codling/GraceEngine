---
title: Install GraceEngine
nav_order: 1
parent: Install
---

# Install GraceEngine

To install GraceEngine with the editor included there are many ways of installing it.<br>
Optionally, if you only want the GraceEngine library and not the included editor please go to [GraceEngineCore](https://github.com/Grace-Engine-Org/GraceEngineCore)

## Install via Browser

1. Head over to the 'Releases' section of the repository which will provide the latest release of GraceEngine. 
1. Hit on the 'Source code.zip' or '.tar.gz' whichever you prefer. 
1. Once complete, follow the steps below to [open GraceEngine.](#opening-graceengine)

## Install via CLI (Command Line Interface)

1. Open your CLI, on Windows this will be CMD while on macOS and Linux this will be terminal.
1. Type the command `git clone https://github.com/Grace-Engine-Org/GraceEngine.git`, this will install GraceEngine to the current directory you are inside of.
1. Once complete, follow the steps below to [open GraceEngine.](#opening-graceengine)

Changing Branch:\
By default, git will clone the main branch (stable) when executing the command:\
`git clone https://github.com/Grace-Engine-Org/GraceEngine.git` 

If you have this installed you can change the branch with the following steps:
1. Change the directory of the CLI to inside the GraceEngine folder.
1. Type `git fetch` to download all changes.
1. Once updated, type `git checkout BRANCH-NAME`
1. Then follow the steps below to [open GraceEngine.](#opening-graceengine)

Else to download a different branch of GraceEngine type the command:\
`git clone -b BRANCH-NAME https://github.com/Grace-Engine-Org/GraceEngine.git`

## Opening GraceEngine

When the GraceEngine folder has been installed onto your computer, right-click on the folder and open via your preferred IDE.
We have guides to tested IDEs such as:

- [CLion](/About/Installation/clion.html)
- [VS2022](/About/Installation/vs2022.html)
- [VScode](/About/Installation/vscode.html)

# Supported IDEs

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
GraceEngine is not limited to specific IDEs as long as it can compile the code correctly. We do recommend other IDEs such as:
- [VS2022](https://visualstudio.microsoft.com/vs/) by Microsoft.
- [VScode](https://code.visualstudio.com/) by Microsoft.


Many IDEs support different compiler versions such as MinGW, Clang, MSVC and more. However, not all IDEs include the correct compiler or even a compiler at all. For example:
- Clion includes MinGW64 / MSVC / Clang
- VS2022 includes MSVC
- VScode does not include a C++ compiler

We currently support Mingw64, MSVC and Clang. Mingw64 is primarily used on Clion, VScode and others where MSVC is the default used with VS2022. If you plan to use Mingw64 please ensure you have it installed. If you do not have it installed please follow this guide.

{: .note }
We will be using Mingw64 and MSVC as the compiler. If you would like to do so, you can use a different compiler instead, however, this guide does not apply to this.

### Other IDEs

We have not tested any other IDEs except for Clion, VS2022 and VScode. However, we can give you some guidance.
Currently, we have support for Mingw, MSVC and Clang