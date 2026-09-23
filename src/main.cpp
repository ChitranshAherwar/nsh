#include <iostream>
#include <string>
#include <vector>

#include "parser.hpp"
 #include "executor.hpp"

int main()
{
    std::string input;

    while (true)
    {

        std::cout << "nsh> ";
        std::getline(std::cin, input);

        std::vector<std::string> args = tokenize(input);
        execute(args);
        
        std::cout << '\n';

    }

    return 0;
}