# Grace Engine

## What is Grace Engine?

This is a new upcoming Engine written in C++ using SFML. It is inspired from the on going PiEngine created by Elliot Codling. Grace Engine will allow you to take leverage of the SFML library while being much easier to code with.

## Why not just write in SFML?

You can and no one is stopping you from doing that. The reason for this project is so that you can harness the power of SFML while making your own application easier to read.
Grace Engine abstracts the rendering side of you project and many other aspects too such as collision, audio and more.

Our end goal is to create an open source editor powered Grace Engine, it will be a fast and reliable editor for all your game making needs.

## Supported Platforms

This current branch of GraceEngine currently included SFML 2.6.2 64-bit built for windows. This is using GCC 13.1.0 MinGW 64-bit and Visual C++ 17 (2022) 64-bit.
We have future plans to allow this to be used on different operating systems and architectures however at this current time we are focusing on development.

> [!IMPORTANT]
> We currently only support 64 bit systems and have no plan to revert this change.

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
We do support other IDEs such as:
- [VS2022](https://visualstudio.microsoft.com/vs/) by Microsoft.
- [VScode](https://code.visualstudio.com/) by Microsoft.

## How to get started

Many IDEs support different compiler versions such as MinGW, Clang, MSVC and more. However, not all IDEs include the correct compiler or even a compiler at all. For example: 
- Clion includes MinGW64 / MSVC / Clang
- VS2022 includes MSVC
- VScode does not include a C++ compiler

We currently support both MinGW64 and MSVC. MinGW64 is primarily used on Clion, VScode and others where MSVC is the default used with VS2022. If you plan to use MinGW64 please ensure you have it installed. If you do not have it installed please follow this guide.
> [!NOTE]
> We will be using MinGW64 as the compiler. If you would like to do so, you can use Clang or UCRT instead, however, this guide does not apply to this.

### Installing MinGW64

1. Download MinGW via [MSYS2](https://www.msys2.org/).
2. Install MSYS2 ensuring to tick run MSYS2 once completed, do not type in any commands into the terminal just yet.
3. Once you've hit the terminal, type the command: `pacman -S mingw-w64-x86_64-gcc`. Type `y` to proceed with the installation.
4. OPTIONAL: To ensure you have GCC installed correctly, open "MSYS2 MINGW64" and type the command `gcc --version` and `g++ --version`.
> [!NOTE]
> - If you have any issues with setting this up please report the problem on the issue tab on the official Github page.
> - More information on how to create your own project will be included in the documentation.

### For Clion IDE

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so. 
2. Open up the project via Clion.
3. In the root directory, right click on the CMakeLists.txt and press "Load CMake Project". This will create a folder called "cmake-build-debug".
4. Click the run button. Ensure the configuration says "GameTesting".

### For VS2022
#### VS2022 - MSVC (Default compiler)

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. Open up the project via VS2022.
3. By default the configuration is x64-Debug, this needs to change. Click on manage configurations and press the +.
4. Add x64-Release and change the configuration to x64-Release.
5. Click the run button.

#### VS2022 - MinGW

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. If you have MinGW compiler installed please continue. Else follow the steps above to install MinGW64.
3. Open up the project via VS2022.
4. By default the configuration is x64-Debug, this needs to change. Click on manage configurations and press the +.
5. Add MinGW64-Debug/Release and change the configuration to MinGW64-Debug/Release.
6. Click the run button.

### For VScode

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. If you have MinGW compiler installed please continue. Else follow the steps above to install MinGW64.
3. Open up the project via VScode.
4. Open the tab "CMAKE" on your side bar. In the "Configure" subheading press the pencil button which will read "Select a kit". 
5. Select the option "GCC x.x.x x86_64-w64-mingw32 (mingw64). Ensure its the mingw64 and not clang or ucrt.
6. Click the run button located on the bottom bar.

### Other IDEs

We have not tested any other IDEs except for Clion, VS2022 and VScode. However, we can give you some guidence.
Currently we support MinGW GCC compiler, specifically MinGW64 for x64 windows. Please ensure you have MinGW from [MSYS](https://www.msys2.org/) installed.
Depending on your IDE it may use Clang, UCRT or MinGW, ensure you have installed the right one for your IDE.

## Documentation

This is a work in progress and will be relased in the coming months.

## Requirements

SFML: [2.6.2 64-bit](https://www.sfml-dev.org/download/sfml/2.6.2/) (Included)\
Compiler version: C++17

> [!NOTE]
> Later revisions of Grace Engine may use newer compiler versions.
