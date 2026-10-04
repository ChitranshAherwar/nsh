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

        std::vector<std::string> args = tokenize(input);

        if(args.empty())
        continue;

        if(args[0] == "exit"){
            break;
        }

        if(args[0] == "cd")
        {
            if(args.size() == 1)
            {
                continue;
            }
            else if(args.size() > 2){

                continue;
            }
            else{

                std::string dir = args[1];
                
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

        execute(args);
     
        std::cout << '\n';

    }

    return 0;
}