# Command Execution

`nsh` executes external commands using Unix process APIs.

## Process Creation

`fork()` creates a child process.

## Program Execution

The child uses `execvp()` to replace itself with the requested program.

## Parent Process

The parent uses `waitpid()` to wait for the child to finish.

## Exit Status

The parent checks the child's termination status using:

- `WIFEXITED()`
- `WEXITSTATUS()`

## Failed Execution

If `execvp()` fails, the child reports the error and terminates using `_exit()`.

This allows the parent to receive the failure status.