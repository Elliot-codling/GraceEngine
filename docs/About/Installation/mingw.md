---
title: MinGW
nav_order: 3
parent: Install
---

# MinGW Install (OPTIONAL)

{: .important }
This page only applies to Windows only.

## Install for x86_84 processors (Intel or AMD)

1. Download MinGW via [MSYS2](https://www.msys2.org/).
1. Install MSYS2 ensuring to tick run MSYS2 once completed, do not type in any commands into the terminal just yet.
1. Once you've hit the terminal, type the command: `pacman -S mingw-w64-x86_64-gcc`. Type `y` to proceed with the installation.
1. OPTIONAL: To ensure you have GCC installed correctly, open "MSYS2 MINGW64" and type the command `gcc --version` and `g++ --version`.

## Install for ARM processors (Snapdragon)

1. Download MinGW via [MSYS2](https://www.msys2.org/).
1. Install MSYS2 ensuring to tick run MSYS2 once completed, do not type in any commands into the terminal just yet.
1. Once you've hit the terminal, type the command: `pacman -S mingw-w64-aarch64-gcc`. Type `y` to proceed with the installation.
1. OPTIONAL: To ensure you have GCC installed correctly, open "MSYS2 MINGW64" and type the command `gcc --version` and `g++ --version`.

{: .note } 
If you have any issues with setting this up please report the problem on the issue tab on the official Github page.\
More information on how to create your own project will be included in the documentation.