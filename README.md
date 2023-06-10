# `ASCron`: Plugin to add cron for Sven Co-op<img align="right" src="./img/logo.png" width="140" height="140" alt="ASCron" />

[![License: GPL v3](https://img.shields.io/github/license/DrAbcOfficial/ascron)](https://www.gnu.org/licenses/gpl-3.0)
[![Build](https://img.shields.io/github/actions/workflow/status/DrAbcOfficial/ascron/build.yml?branch=main)](https://github.com/DrAbcOfficial/ascron/actions)
[![Release](https://img.shields.io/github/v/release/DrAbcOfficial/ascron)](https://github.com/DrAbcOfficial/ascron/releases)
[![Download](https://img.shields.io/github/downloads/DrAbcOfficial/ascron/total)](https://github.com/DrAbcOfficial/ascron/releases)
[![Commit](https://img.shields.io/github/last-commit/DrAbcOfficial/ascron)](https://github.com/DrAbcOfficial/ascron)

`ASCron` is a Metamod plugin based on PerMalmberg's libcron to add Cron for Sven Co-op AngelScripts scripting system.

---

<!-- vscode-markdown-toc -->
* 1. [Install](#Install)
* 2. [Build](#Build)
* 3. [Document](#Document)
	* 3.1. [Current Expansion Property](#CurrentExpansionProperty)
	* 3.2. [Current Expansion Methods](#CurrentExpansionMethods)
	* 3.3. [Expansion Method Examples](#ExpansionMethodExamples)

<!-- vscode-markdown-toc-config
	numbering=true
	autoSave=true
	/vscode-markdown-toc-config -->
<!-- /vscode-markdown-toc -->

---

##  1. <a name='Install'></a>Install

1. Grab metamod-p and asext.dll/asext.so [Here](https://github.com/hzqst/metamod-fallguys/releases)

2. Install them.
3. Grab ascron.dll/ascron.so, put them into `svencoop/addons/metamod/dlls`
   1.  Grab latest version in [Action](https://github.com/DrAbcOfficial/ascron/actions/workflows/build.yml) (Unstable, crash risk)
		
		or

   2.  Grab release version in [Release](https://github.com/DrAbcOfficial/ascron/releases) (Stable)
4. edit `svencoop/addons/metamod/plugins.ini`
5. add 

``` ini
win32 addons/metamod/dlls/ascron.dll
linux addons/metamod/dlls/ascron.so
```

6. enjoy your new cron :3

---

##  2. <a name='Build'></a>Build

If you are using systems that are not covered by automatic builds (yum's and aur's) 

or want to add new hooks yourself, you can follow these steps to configure your build environment.

1. Install everything you need
   
	<img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white"/>

	1. [Git](https://git-scm.com/download/win) or `winget install --id Git.Git -e --source winget`
	2. [Visual Studio with vc143 toolset](https://visualstudio.microsoft.com/) And [C++ desktop development](https://learn.microsoft.com/en-us/cpp/ide/using-the-visual-studio-ide-for-cpp-desktop-development?view=msvc-170)

	<img src="https://img.shields.io/badge/Debian-A81D33?style=for-the-badge&logo=debian&logoColor=white"/>

	1. `sudo apt install git make build-essential gcc gcc-multilib g++-multilib cmake -y`

	<img src="https://img.shields.io/badge/Fedora-294172?style=for-the-badge&logo=fedora&logoColor=white"/>

	1. `sudo yum install git make gcc gcc-c++ glibc-devel.i686 libstdc++-devel.i686 cmake -y`

	<img src="https://img.shields.io/badge/Arch_Linux-1793D1?style=for-the-badge&logo=arch-linux&logoColor=white"/>

	Sorry guys who using Arch, I've never used an Arch based distribution, you'll have to find out how to configure the dependencies yourselves!🙂

2. Clone metamod modified by hzqst
   
   `git clone https://github.com/DrAbcOfficial/metamod-fallguys.git metamod`

   `cd metamod`

3. Clone this

	`git clone https://github.com/DrAbcOfficial/ascron.git`

	`cd ascron`

4. Build!

	<img src="https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white"/>

	1. Open `ascron.sln` with visual studio
	2. Press `F7`
	3. Wait and done.

	<img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black"/>

	1. `mkdir build && cd build && cmake .. && make`
   
6. Grab
	
	Now you can grab your new library (ascron.dll/ascron.so) in 
	
	`metamod/build/addons/metamod/dlls/`

##  3. <a name='Document'></a>Document

###  3.1. <a name='CurrentExpansionProperty'></a>Current Expansion Property
 
|Class|Namespace|Object|
|---|---|---|
|CCron|\<Global\>|g_Cron|


---

###  3.2. <a name='CurrentExpansionMethods'></a>Current Expansion Methods

|Class|Method|Explian|
|---|---|---|
|CCron|void Add(string&in name, string&in time, fnCronCallback@ callback, any@ param)|Add Scheduler|
|CCron|void Add(string&in name, string&in time, fnCronNoParamCallback@ callback)|Add Scheduler|
|CCron|void Remove(string&in name)|Remove Scheduler|
|CCron|void RemoveAll()|Remove All Scheduler|
|CCron|uint Count()|Count Scheduler|

###  3.3. <a name='ExpansionMethodExamples'></a>Expansion Method Examples

[Example](https://github.com/DrAbcOfficial/ascron/tree/main/example)

# ThirdParty

This plugin use PerMalmberg's [libcron](https://github.com/PerMalmberg/libcron) and Howard Hinnant's [date](https://github.com/HowardHinnant/date/)