MuseumInterface by GTMA
================================

Custom version of Slicer for museum exhibition

![MuseumInterface by GTMA](Applications/App/Resources/Images/LogoFull.png?raw=true)

# Prerequisites

* **Operating System**:
    * Microsoft Windows 7 or above recommended
    * Ubuntu 18.04 

* **Tested Microsoft Visual Studio versions**:
    * Visual Studio 2015

* **Tools**:
    * [CMake](http://cmake.org/cmake/resources/software.html)
        * Version 3.11 or above
    * [Qt](https://www.qt.io/download)
        * Version 5.9.9 or above
    * [Git](http://git-scm.com/downloads)
    * [Subversion](http://www.sliksvn.com/en/download)

* **Optional:**
    * [SteamVR](https://store.steampowered.com/app/250820/SteamVR/)
        * If you are interesting in Virtual Reality (VR) capability
            

* **Setting up your git account**:

    * Setup your SSH keys following [these](https://help.github.com/articles/generating-ssh-keys) instructions at the
    exception of `step 2` where you should **NOT** enter a passphrase.
        * Start [Git Bash](https://help.github.com/articles/set-up-git#need-a-quick-lesson-about-terminalterminalgit-bashthe-command-line) and introduce  *ssh-keygen* to create a ssh key.
        * In [GitLab](https://alix.iuibs.ulpgc.es), go to `User Setting > SSH Keys` and introduce the ***public key*** located on `[User Dir]\.ssh\id_rsa.pub`.   
           
    * Setup [your git username](https://help.github.com/articles/setting-your-username-in-git) and [your git email](https://help.github.com/articles/setting-your-email-in-git).

    * If not already done, email `Abián Hernández <abian.hernandez@ulpgc.es>` to be granted access to
    the [GTMA/MuseumInterface](https://alix.iuibs.ulpgc.es/ULPGC.GTMA/MuseumInterface) repository.

# Checkout

1. Start [Git Bash](https://help.github.com/articles/set-up-git#need-a-quick-lesson-about-terminalterminalgit-bashthe-command-line)
2. Checkout the source code into a directory `C:\W\` by typing the following commands:

```bat
cd /c
mkdir W
cd /c/W
git clone git@alix.iuibs.ulpgc.es:ULPGC.GTMA/MuseumInterface.git MuseumInterface
```

Note: **in Windows**, use short source and build directory names to avoid the [maximum path length limitation](http://msdn.microsoft.com/en-us/library/windows/desktop/aa365247%28v=vs.85%29.aspx#maxpath).

# Build

Note: The build process will take approximately 3 hours. This time can be significantly reduced using Ninja build system but the paths presented in the following chapters can be different.

## Building on Windows:

**Option 1: CMake GUI and Visual Studio (Recommended)**

1. Start [CMake GUI](https://cmake.org/runningcmake/), select source directory `C:\W\MuseumInterface` and set build directory to `C:\W\Build`.
2. Add an entry `Qt5_DIR` pointing to:
    * `[Qt Location]\[Qt Version]\[MSVC Version]\lib\cmake\Qt5\`.
3. Generate the project.
4. Open the  project using the ***Open Project* button** in CMake, select `Release` and build the project.

**Note**: It is mandatory to use CMake macros of Git that are located in `[Git location]\usr\bin`. This path should be included in `Windows PATH Variable`.

**Warning**: Sometimes is necessary create the `Slicer-build/bin` directory because it is not created in Building time.

**Option 2: Command Line**

1. Start the [Command Line Prompt](http://windows.microsoft.com/en-us/windows/command-prompt-faq)
2. Configure and build the project in `C:\W\Build` by typing the following commands:

```bat
cd C:\W\
mkdir Build
cd Build
cmake -G "Visual Studio 14 2015 Win64" -DQt5_DIR=[Qt Location]\[Qt Version]\[MSVC Version]\lib\cmake\Qt5\ ..\MuseumInterface
cmake --build . --config Release
```

# Developing
**If you are developing on Windows**, it is necessary to locate the library `vtkRenderingOpenVR-8.2.dll` located on `C:\W\bin\Release` in order to be able to load the necessary modules. You can do one of the following solutions:

**Option 1: Modified the launcher settings.**

Slicer contains a *.ini* file which is used to indicate the launcher settings, `MuseumInterfaceLauncherSettings.ini`. This file is located on `C:\W\Build\Slicer-build\`.

This file is a text which can be modified using any text editor. This file contains a field called `[LibraryPaths]` where, as the name suggests, the libraries directories are located. In this field we need to add the path where is located the `vtkRenderingOpenVR-8.2.dll` file.


```bat
[LibraryPaths]
1\path=<APPLAUNCHER_SETTINGS_DIR>/bin/Release
.
.
.
19\path=C:/W/Build/OpenVR/bin/win64/
20\path=E:/W/Build/bin/Release
size=20
```

    
**Option 2: copy the library in a accessible directory.**

For this options, we recommend to copy the file `C:\W\Build\bin\Release\vtkRenderingOpenVR-8.2.dll` in `C:\W\Build\Slicer-build\lib\[Application Name]\qt-loadable-modules\Release\` directory.

In order to avoid any problem, it is recommennded to copy the OpenVR library too, `C:\W\Build\OpenVR\bin\win64\openvr_api.dll`

```bat
$ copy C:\W\Build\bin\Release\vtkRenderingOpenVR-8.2.dll C:\W\Build\Slicer-build\lib\MuseumInterface-4.11\qt-loadable-modules\Release\

$ copy C:\W\Build\OpenVR\bin\win64\openvr_api.dll C:\W\Build\Slicer-build\lib\MuseumInterface-4.11\qt-loadable-modules\Release\
```

# Package

Install [NSIS 2](http://sourceforge.net/projects/nsis/files/)

**Option 1: CMake and Visual Studio (Recommended)**

1. In the `C:\W\Build\Slicer-build` directory, open `Slicer.sln` and build the `PACKAGE` target

**Option 2: Command Line**

1. Start the [Command Line Prompt](http://windows.microsoft.com/en-us/windows/command-prompt-faq)
2. Build the `PACKAGE` target by typing the following commands:

```bat
cd C:\W\Build\Slicer-build
cmake --build . --config Release --target PACKAGE
```

# Resources

* [3D Slicer Developer Wiki](http://wiki.slicer.org/slicerWiki/index.php/Documentation/Nightly/Developers)
