---
title: Install GraceEngine
nav_order: 1
parent: Install & IDEs
---
# Install GraceEngine

There are a couple different ways of installing GraceEngine with the editor.\
This page will guide you through the installation process.
- If you would like to install GraceEngine from your browser click [here](#download-via-browser).
- If you would like to install GraceEngine via the CLI click [here](#download-via-cli-command-line-interface).

Optionally, if you only want the GraceEngine library and not the included editor please go to [GraceEngineCore](https://github.com/Grace-Engine-Org/GraceEngineCore).

## Download via Browser

1. Head over to the 'Releases' section of the repository which will provide the latest release of GraceEngine.
1. Hit on the 'Source code.zip' or '.tar.gz' whichever you prefer.
1. Once complete, follow the steps below to [open GraceEngine](#opening-graceengine).

## Download via CLI (Command Line Interface)

1. Open your CLI, on Windows this will be CMD while on macOS and Linux this will be terminal.
1. Type the command `git clone https://github.com/Grace-Engine-Org/GraceEngine.git`, this will install GraceEngine to the current directory you are inside of.
1. Once complete, follow the steps below to [open GraceEngine](#opening-graceengine).

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

If you are on a Linux based OS, please follow the [Linux Dependencies](#linux-dependencies) guide and then return back here once complete.

When the GraceEngine folder has been installed onto your computer, right-click on the folder and open via your preferred IDE.
We have guides to tested IDEs such as:

- [CLion](clion.html)
- [VS2022](vs2022.html)
- [VScode](vscode.html)

You can view our information on supported IDEs [here](supportedIDEs.html).

## Linux Dependencies
Some extra dependencies are required to get started with the project.
1. Open up your CLI.
1. Enter the command `sudo apt install build-essential cmake git libx11-dev libxrandr-dev libxinerama-dev libxcursor-dev libsndfile1-dev libfreetype6-dev libopenal-dev libudev-dev libgl1-mesa-dev libegl1-mesa-dev libsfml-dev`
1. Once everything has been installed, you may continue with the rest of the guide.