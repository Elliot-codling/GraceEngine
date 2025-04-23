# Grace Engine

## What is Grace Engine?

This is a new upcoming Engine written in C++ using SFML. It is inspired from the on going PiEngine created by Elliot Codling. Grace Engine will allow you to take leverage of the SFML library while being much easier to code with.

## Why not just write in SFML?

You can and no one is stopping you from doing that. The reason for this project is so that you can harness the power of SFML while making your own application easier to read.
Grace Engine abstracts the rendering side of you project and many other aspects too such as collision, audio and more.

## Supported Platforms
This current branch of GraceEngine currently included SFML 2.6.2 built for windows. This is using GCC 13.1.0 MinGW 64-bit.
We have future plans to allow this to be used on different operating systems and architectures however at this current time we are focusing on development.

Our recommended fully supported IDE is [Clion](https://www.jetbrains.com/clion/) by Jetbrains.
We are in the works of supporting VS 2022 along with a guide to setup the project correctly.

## How to get started

### For Clion IDE
1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so. 
2. Open up the project via Clion.
3. In the root directory, right click on the CMakeLists.txt and press "Load CMake Project". This will create two folders called "cmake-build-debug" and "cmake-build-release".
4. Click the run button. Ensure the configuration says "GameTesting".
> [!NOTE]
> If you have any issues with setting this up please report the problem on the issue tab on the official Github page.

### For other IDE

Apologies as we do not currently support any other IDEs.

## Documentation

This is a work in progress and will be relased in the coming months.

## Requirements

SFML: [2.6.2 64-bit](https://www.sfml-dev.org/download/sfml/2.6.2/) (Included)\
Compiler version: C++17

> [!NOTE]
> Later revisions of Grace Engine will use newer compiler versions.
