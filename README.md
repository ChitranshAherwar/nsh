# nsh — Nyx Shell

A small Unix shell written in C++ from scratch.

> ⚠️ **Early development:** `nsh` is currently in a very early stage of development. The shell currently only reads and parses input; it does not execute commands yet. The interactive loop runs indefinitely and can be stopped with `Ctrl+C`.

## Current Functionality

* Interactive command input
* Command argument parsing

## Build

```bash
cmake -S . -B build
cmake --build build
```

Run:

```bash
./build/nsh
```

Run parser tests:

```bash
./build/parser_test
```
