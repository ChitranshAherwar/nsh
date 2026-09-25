# nsh — Nyx Shell

A small Unix shell written in C++ from scratch.

> ⚠️ **Early development:** `nsh` is currently in a very early stage of development. The interactive loop runs indefinitely and can be stopped with `Ctrl+C`.

## Current Functionality

- Interactive command input
- Command argument parsing
- External command execution
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