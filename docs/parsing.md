# Parsing

## Purpose
Converts a command line into individual arguments.

## Example

Input:
ls -la /home

Output:
["ls", "-la", "/home"]

## Current behavior
- Parses command into `ParsedCommand`
- Splits on spaces
- Ignores consecutive spaces
- Ignores leading/trailing spaces
- Stores command arguments
- Detects `>`
- Stores the redirection target file
- Rejects invalid redirection syntax

## Current limitations
- No quoted arguments yet
- No escaping yet
- No other operators