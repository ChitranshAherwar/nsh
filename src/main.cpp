#include <iostream>
#include <string>
#include <vector>
#include <unistd.h>
#include <cerrno>
#include <cstring>

#include "parser.hpp"
 #include "executor.hpp"

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
            if(command.args.size() == 1)
            {
                continue;
            }
            else if(command.args.size() > 2){

                continue;
            }
            else{

                std::string dir = command.args[1];
                
                int result = chdir(dir.c_str());

                if(result == 0)
                {
                    // TODO: update path in nsh>
                    continue;
                }
                else{
                    std::cout << "cd: " << strerror(errno) << '\n';
                    continue;
                }
            }

        }

        execute(command);
     
        std::cout << '\n';

    }

    return 0;
}