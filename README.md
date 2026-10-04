# nsh — Nyx Shell

nsh started with a simple question: what actually happens between typing a command and seeing a program run? Rather than treating the shell as another layer of the system to take for granted, I decided to build one from scratch in C++ and learn by pulling that layer apart piece by piece.

What began as a small experiment has grown into a working shell with command parsing, external process execution, and builtins such as `cd` and `exit`, with tests and documentation evolving alongside it.

nsh is still deliberately far from a full-featured shell, and that's the point. The project will keep growing as I understand more about Unix processes, system interfaces, and the machinery underneath everyday command-line tools. There is no fixed finish line; as long as there is something interesting hiding behind the prompt, nsh has somewhere left to go.

## Current Functionality

- Interactive command input
- Command argument parsing
- External command execution
- `cd` builtin
- `exit` builtin

## Build
```bash
cmake -S . -B build
cmake --build build
```
## Run shell
```
./build/nsh
```
## Run tests
```
./build/parser_test
./build/executor_test
```
> Yes, it runs commands. No, it won't replace your shell anytime soon.