# CPack
C Language Project Bootstrapper

## Installation

> Currently CPack durectly supports installation only on macOS.

To install CPack download the source code and from the root directory of the project run

```bash
make install
```

This automatically create alias in your system and set up some environment variables.

## Usage

To bootstrap an empty C project run in terminal

```bash
cpack new new_project_name
```

This will create a new folder with specified project name and initialize some source code that compiles down to a single binary.

If you want to initialize project in current folder you can run this command

```bash
cpack init
```

By default you can bootstrap one of two type of projects: *binary* and *static library*

If you want to extend functionality, you can add custom template in installed Cpack directory.
Path to that directory should be `~/.cpack/templates`

Then, you can simply run this commands

```bash
cpack new project_name -t<your_template>
# or
cpack init -t<your_template>
```
