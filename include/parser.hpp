#pragma once // prevents header from multiple include.

#include <vector>
#include <string>

enum class RedirectionType
{
    None,
    Input,
    Output,
    Append
};

struct ParsedCommand
{
    std::vector<std::string> args;

    RedirectionType redirection = RedirectionType::None;
    std::string file;
    bool valid = true;
};

ParsedCommand tokenize(const std::string& input);