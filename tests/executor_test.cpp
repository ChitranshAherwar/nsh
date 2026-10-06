#include <iostream>

#include "executor.hpp"

int main()
{
    ParsedCommand command;
    int result;

    command.args = {"ls"};
    result = execute(command);

    if(result == 0)
    {
        std::cout << "[PASS] single argument.\n";
    }
    else
    {
        std::cout << "[FAIL] single argument.\n";
    }

    command.args = {"ls", "-la"};
    result = execute(command);

    if(result == 0)
    {
        std::cout << "[PASS] multiple arguments.\n";
    }
    else
    {
        std::cout << "[FAIL] multiple arguments.\n";
    }

    command.args = {"nsh"};
    result = execute(command);

    if(result != 0)
    {
        std::cout << "[PASS] unknown command.\n";
    }
    else
    {
        std::cout << "[FAIL] unknown command.\n";
    }

    command.args = {"echo", "hello"};
    command.redirection = RedirectionType::Output;
    command.file = "/some/path/file.txt";

    result = execute(command);

    if(result != 0)
    {
        std::cout << "[PASS] invalid output path\n";
    }
    else
    {
        std::cout << "[FAIL] invalid output path\n";
    }
}