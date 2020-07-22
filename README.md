# Godot playground!
A place to play with Godot.

## Godot installation

Clone the Godot repository:

```
mkdir -p ~/workspace && cd ~/workspace
git clone https://github.com/godotengine/godot.git
cd godot
git checkout 3.2.2-stable
```

Install the Godot dependencies:

```
sudo apt-get install build-essential scons pkg-config libx11-dev \
    libxcursor-dev libxinerama-dev libgl1-mesa-dev libglu-dev libasound2-dev \
    libpulse-dev libudev-dev libxi-dev libxrandr-dev yasm
```

Compile Godot:

```
scons -j8 platform=x11
```

References:
  * [Compiling_for_x11](https://docs.godotengine.org/en/stable/development/compiling/compiling_for_x11.html).

Testing:

```
./bin/godot.x11.tools.64
```

## Create a C++ external custom module

Clone this repo:

```
mkdir -p ~/workspace && cd ~/workspace
git clone https://github.com/osrf/godot_playground.git
cd godot_playground
```

Compile the custom modules:

```
cd ~/workspace/godot
scons custom_modules=~/workspace/godot_playground/modules
```

We're compiling a custom module (`sumator`) as a shared library, that is
dynamically loaded when starting our entry point script. The library is located
in `~/workspace/godot/bin/libsummator.x11.tools.64.so`.

## Using our module

We're going to use a script as an entry point:

```
LD_LIBRARY_PATH=~/workspace/godot/bin ./bin/godot.x11.tools.64 -s ~/workspace/godot_playground/scripts/sayhello.gd
```

As expected, we need to use `LD_LIBRARY_PATH` for being able to find the shared
library of our module. The script `sayhello.gd` automatically imports our
`summator` module and uses its functionality.


Referefences:
  * [Custom modules in C++](https://docs.godotengine.org/en/2.1/development/cpp/custom_modules_in_cpp.html#using-the-module)
  * [Running a script](https://docs.huihoo.com/godotengine/godot-docs/godot/reference/command_line_tutorial.html#running-a-script)
