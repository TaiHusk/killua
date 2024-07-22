# Killua Programming Language

<div align="center">
  <img src="https://github.com/TaiHusk/TaiHusk/blob/main/image.jpg" alt="TaiHusk's Github Profile Picture" width="5000" height="400" />
</div>

## Introduction
Killua is a programming language designed to offer greater flexibility and configuration capabilities in the future. It is written in C++, utilizing the [`C++29`](github.com/taihusk/CXX29) standard to leverage the latest features and improvements in the language. Killua is named after the character Killua from the anime series "Hunter x Hunter," known for his agility and adaptability.

## Requirements
- `g++ 13.2.0` or higher (required for `C++20` standard support)
- [`C++29`](github.com/taihusk/CXX29)
- `Linux` (currently does not work on Windows)

## Installation
To install Killua, you need to have a C++ compiler that supports the C++29 standard. Once you have the necessary compiler, you can install Killua by running the following commands in your terminal:

```bash
chmod +x ./install.sh
./install.sh
```

##Usage

Killua programs are written in files with the `.killua` extension. To run a Killua program, use the `killua` command followed by the path to the program file.

```bash
killua <path_to_file>
```

For example, to run a program named `index.killua` located in the `examples` directory, you would use:

```bash
killua ./examples/index.killua
```

## Example
Here is a simple example of a Killua program that executes a shell command:

```plaintext
// this comment

shell {
 "ls --color -ahl"
}
```

In this example, the `shell` block is used to execute a shell command. The `shell` keyword indicates that the content within the curly braces is a shell command. The command is enclosed in quotes, which signify that it is a string argument. The command `ls --color -ahl` is then executed, listing the files and directories in the current directory with colorized output and additional details.

## Language Features

- **Shell Command Execution**: Killua allows the execution of shell commands within the language using the `shell` block.
- **Comments**: Single-line comments are denoted by `//`.
- **String Arguments**: Commands within `shell` blocks are specified as strings.

## Future Plans
Killua is designed to be extensible and configurable. Future versions of the language will include more features and capabilities, allowing for more complex and powerful programs.

## License
Killua is released under the [MIT License](LICENSE). Feel free to use, modify, and distribute the language as you see fit.

---

Killua is a work in progress, and its features and capabilities will continue to evolve. Stay tuned for updates and new releases!