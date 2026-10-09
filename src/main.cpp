#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include "parser.hpp"
#include "executor.hpp"
#include "builtins/cd.hpp"

int main()
{
    bool logo = false;

    if(logo == true){
    std::cout << R"(
         : :::    :::  ::::::::  :::    :::
        :+:+:   :+: :+:    :+: :+:    :+:
       :+:+:+  +:+ +:+        +:+    +:+
      +#+ +:+ +#+ +#++:++#++ +#++:++#+
     +#+  +#+#+#        +#+ +#+    +#+
    #+#   #+#+# #+#    #+# #+#    #+#
   ###    ####  ########  ###    ###
  )";
    }

    std::cout << '\n';
    std::string input;

    while(true)
    {   
        std::cout << "nsh> ";
        std::getline(std::cin, input);

        ParsedCommand command = tokenize(input);

        if(!command.valid)
        continue;

        if(command.args.empty())
        continue;

        if(command.args[0] == "exit"){
            break;
        }

        if(command.args[0] == "cd")
        {
            builtin_cd(command);
            continue;
        }

        execute(command);
     
        std::cout << '\n';

    }

    return 0;
}
