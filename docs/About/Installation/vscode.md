---
title: VScode
nav_order: 6
parent: Install
---

# Install GraceEngine via VScode

{: .important }
Theoretically GraceEngine will compile on macOS, this has not been tested and currently we have no guide for the installation of GraceEngine on macOS.

## VScode - MinGW for x86_64 processors

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. If you have MinGW compiler installed please continue. Else follow the steps [here](/About/Installation/mingw.html) to install MinGW64.
3. Open up the project via VScode.
4. Open the tab "CMAKE" on your side bar. In the "Configure" subheading press the pencil button which will read "Select a kit".
5. Select the option "GCC x.x.x x86_64-w64-mingw32 (mingw64). Ensure it's the mingw64 and not clang or ucrt.
6. Click the run button located on the bottom bar.

## VScode - MinGW for ARM processors

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
2. If you have MinGW compiler installed please continue. Else follow the steps [here](/About/Installation/mingw.html) to install MinGW64.
3. Open up the project via VScode.
4. Open the tab "CMAKE" on your sidebar. In the "Configure" subheading press the pencil button which will read "Select a kit".
5. Select the option: "GCC x.x.x arm64-w64-mingw32 (mingw64). Ensure it's the mingw64 and not clang or ucrt.
6. Click the run button located on the bottom bar.