#include <iostream>
#include <unistd.h>
#include <string>

#include "builtins/cd.hpp"
#include "parser.hpp"

int main()
{
    ParsedCommand command;

    command.args = {"cd", "/tmp"};
    builtin_cd(command);

    char after_cd[1024];
    getcwd(after_cd, sizeof(after_cd));
    
    std::string actual(after_cd);

    if(actual == "/tmp")
    {
        std::cout << "[PASS]\n";
        return 0;
    }
    else
    {
        std::cout << "[FAIL]\n";
        return 1;
    }
}