---
title: VScode
nav_order: 5
parent: Install & IDEs
---

# Install GraceEngine via VScode

## VScode - MSVC (Windows)

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
1. If you have MSVC compiler installed please continue. Else follow the steps [here](https://code.visualstudio.com/docs/cpp/config-msvc#_prerequisites) to install MSVC.
1. Open up the project via VScode.
1. Open the tab "CMAKE" on your sidebar. In the "Configure" subheading press the pencil button which will read "Select a kit".
1. Select the option "Visual Studio Community 2022 Release - amd64". Check note if this does not match what you see.
1. Click the run button located on the bottom bar.

{: .note}
There are different versions of VS such as Professional, Enterprise and Preview. Additionally, they may be from different years such as 2017 or 2019. Or the suffix at the end may say arm64.
The year of VS requires 2019 or later for GraceEngine to compile.

## VScode - GCC (Linux)

1. Download the project from the Github release page using your preferred method. However, you can clone from the stable branch if you wish to do so.
1. Open up the project via VScode.
1. Open the tab "CMAKE" on your sidebar. In the "Configure" subheading press the pencil button which will read "Select a kit".
1. Select the option "GCC x.x.x x86_64-linux-gnu". Check note if this does not match what you see.
1. Click the run button located on the bottom bar.

{: .note}
There are different versions of the GCC compiler, they may be compiled for ARM or x86. They will both work the same.
The version number of the GCC compiler is required to be 7.2.0 or higher for GraceEngine to compile.