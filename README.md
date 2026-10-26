
# Watson

Watson is a very simple framework for developing text-focused adventure games.
It is written in C23 using SDL3.
This repository represents a very early development version.

## Building

Watson is built using CMake, Ninja, and a modern C Compiler.

### System Libraries

On Unix-like platforms you can just install the dependencies and compile.
The following will install all the necessary build tools and dependencies:

Debian:
```sh
sudo apt install cmake ininja gcc gdb sdl3
```

Fedora Linux:
```sh
sudo dnf install cmake ninja gcc gdb sdl3
```

Arch Linux:
```sh
sudo pacman -ySu cmake ninja gcc gdb sdl3
```

### Vendored Libraries

If system libraries are unavailable, you can use vendored libraries.
This option will dramatically increase compile time as SDL3 is also compiled.

Either, initialize submodules when cloning the repository using the `--recursive` flag;
or, from the root of the repository run the following command:

```sh
git submodule update --init --recursive
```

This will pull down the relevant version of SDL3 and store it in `vendor/SDL`.
The provided `CMakeLists.txt` will look for SDL here before attempting to find it as a system library.
If you are using this method, you will need to make sure you have [SDL3's dependencies](https://wiki.libsdl.org/SDL3/README-linux) installed.

