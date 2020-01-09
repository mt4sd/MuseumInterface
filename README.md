MuseumInterface by GTMA
================================

Custom version of Slicer for museum exhibition

![MuseumInterface by GTMA](Applications/App/Resources/Images/LogoFull.png?raw=true)

# Prerequisites

* **Operating System**:
    * Microsoft Windows 7 or above recommended
    * Ubuntu 18.04
        * Maybe is necessary create the Slicer-build/bin directory 

* **Tested Microsoft Visual Studio versions**:
    * Visual Studio 2015

* **Tools**:
    * [CMake](http://cmake.org/cmake/resources/software.html)
        * Version 3.11 or above
    * [Qt](https://www.qt.io/download)
        * Version 5.9.8 or above
    * [Git](http://git-scm.com/downloads)
    * [Subversion](http://www.sliksvn.com/en/download)

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

Note: The build process will take approximately 3 hours.

## Building on Windows:

<b>Option 1: CMake GUI and Visual Studio (Recommended)</b>

1. Start [CMake GUI](https://cmake.org/runningcmake/), select source directory `C:\W\MuseumInterface` and set build directory to `C:\W\Build`.
2. Add an entry `Qt5_DIR` pointing to:
    * `[Qt Location]\[Qt Version]\[MSVC Version]\lib\cmake\Qt5\`.
3. Generate the project.
4. Open the  project using the ***Open Project* button** in CMake, select `Release` and build the project.

**Note**: It is mandatory to use CMake macros of Git that are located in `[Git location]\usr\bin`. This path should be included in `Windows PATH Variable`.     

<b>Option 2: Command Line</b>

1. Start the [Command Line Prompt](http://windows.microsoft.com/en-us/windows/command-prompt-faq)
2. Configure and build the project in `C:\W\Build` by typing the following commands:

```bat
cd C:\W\
mkdir Build
cd Build
cmake -G "Visual Studio 14 2015 Win64" -DQt5_DIR=[Qt Location]\[Qt Version]\[MSVC Version]\lib\cmake\Qt5\ ..\MuseumInterface
cmake --build . --config Release
```

# Package

Install [NSIS 2](http://sourceforge.net/projects/nsis/files/)

<b>Option 1: CMake and Visual Studio (Recommended)</b>

1. In the `C:\W\MuseumInterface-rel\Slicer-build` directory, open `Slicer.sln` and build the `PACKAGE` target

<b>Option 2: Command Line</b>

1. Start the [Command Line Prompt](http://windows.microsoft.com/en-us/windows/command-prompt-faq)
2. Build the `PACKAGE` target by typing the following commands:

```bat
cd C:\W\MuseumInterface-rel\Slicer-build
cmake --build . --config Release --target PACKAGE
```

# Resources

* [3D Slicer Developer Wiki](http://wiki.slicer.org/slicerWiki/index.php/Documentation/Nightly/Developers)
