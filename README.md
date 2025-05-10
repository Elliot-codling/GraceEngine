# Grace Engine

## What is Grace Engine?

This in mine now a-ha!
This is a new upcoming Engine written in C++ using SFML. It is inspired from the on going PiEngine created by Elliot Codling. Grace Engine will allow you to take leverage of the SFML library while being much easier to code with.

## Why not just write in SFML?

You can and no one is stopping you from doing that. The reason for this project is so that you can harness the power of SFML while making your own application easier to read.
Grace Engine abstracts the rendering side of you project and many other aspects too such as collision, audio and more.

Our end goal is to create an open source editor powered Grace Engine, it will be a fast and reliable editor for all your game making needs.

## Supported Platforms
This current branch of GraceEngine currently included SFML 2.6.2 built for windows. This is using GCC 13.1.0 MinGW 64-bit.
We have future plans to allow this to be used on different operating systems and architectures however at this current time we are focusing on development.

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
We do support other IDEs such as [VS2022](https://visualstudio.microsoft.com/vs/) by Microsoft.

## How to get started

> [!NOTE]
> - If you have any issues with setting this up please report the problem on the issue tab on the official Github page.
> - More information on how to create your own project will be included in the documentation.

### For Clion IDE
1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so. 
2. Open up the project via Clion.
3. In the root directory, right click on the CMakeLists.txt and press "Load CMake Project". This will create two folders called "cmake-build-debug" and "cmake-build-release".
4. Click the run button. Ensure the configuration says "GameTesting".

### For VS2022

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. If you have MinGW compiler installed please skip to step 5. Else download MinGW via [MSYS2](https://www.msys2.org/).
3. Install MSYS2 ensuring to tick run MSYS2 once completed, do not type in any commands into the terminal just yet.
> [!NOTE]
> VS2022 defaults to MinGW compiler, we will be using this. If you would like to you can use ucrt instead, however, this guide does apply to this.

4. Once you've hit the terminal, type the command: `pacman -S mingw-w64-x86_64-gcc`. Type y to proceed with the installation.
5. Open up the project via VS2022.
6. By default the configuration is x64-Debug, this needs to change. Click on manage configurations and press the +.
7. Add MinGW64-Debug/Release and change the configuration to MinGW64-Debug/Release.
8. Click the run button.

### Other IDEs

We have not tested any other IDEs except for Clion and VS2022. However we can give you some guidence.
Currently we support MinGW GCC compiler, specifically MinGW64 for x64 windows. Please ensure you have MinGW from [MSYS](https://www.msys2.org/) installed.
Depending on your IDE it may use clang, ucrt or MinGW, ensure you have installed the right one for your IDE.

## Documentation

This is a work in progress and will be relased in the coming months.

## Requirements

SFML: [2.6.2 64-bit](https://www.sfml-dev.org/download/sfml/2.6.2/) (Included)\
Compiler version: C++17

> [!NOTE]
> Later revisions of Grace Engine may use newer compiler versions.
