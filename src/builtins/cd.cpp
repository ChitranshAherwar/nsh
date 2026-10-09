#include "builtins/cd.hpp"

#include <unistd.h>
#include <cstring>
#include <iostream>

int builtin_cd(const ParsedCommand& command)
{
    
    if(command.args.size() == 2)
    {
        std::string dir = command.args[1];
                
        int result = chdir(dir.c_str());

        if(result == 0)
        {
            // TODO: update path in nsh>
            // success cd
        }
        else
        {
            // cd dir not exist;
            std::cout << "cd: " << strerror(errno) << '\n';
        }
    }

    return 0;
}