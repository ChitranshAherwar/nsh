# Parsing

## Purpose
Converts a command line into individual arguments.

## Example

Input:
ls -la /home

Output:
["ls", "-la", "/home"]

## Current behavior
- Splits on spaces
- Ignores consecutive spaces
- Ignores leading/trailing spaces
- Returns vector<string>

## Current limitations
- No quoted arguments yet
- No escaping yet
- No operators yet